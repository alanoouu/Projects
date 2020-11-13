#lang racket

; Question 1

; Check if c is a digit using code-point numbers of the characters 0 to 9.
; If c is outside the bounds 48 to 57, then c is not a number. 
(define (is-digit? c)
  (cond [(equal? (char? c) #f) #f]
        [(< (char->integer c) 48) #f]   ; code-point number of 0 = 48
        [(> (char->integer c) 57) #f]   ; code-point number of 9 = 57
        [else #t]));

; Question 2

; Check if c is a letter using code-point numbers of the characters a to z and A to Z.
; If c is either inside the bounds 97 to 122 or 65 to 90, then c is a letter. 
(define (is-letter? c)
  (and (equal? (char? c) #t)
       (or (and (>= (char->integer c) 97)       ; code-point number of a = 97
                (<= (char->integer c) 122))     ; code-point number of z = 122
           (and (>= (char->integer c) 65)       ; code-point number of A = 65
                (<= (char->integer c) 90)))));  ; code-point number of Z = 90

; Question 3

; Helper function for question 3. Checks if the variable is a digit or number.

(define (check-letter-digit x)
  (cond [(equal? (is-letter? x) #t) #t]
        [(equal? (is-digit? x) #t) #t]
        [else #f]))

(define (is-vble? x)
  (cond [(or (equal? x 't)            
             (equal? x 'f)) #f]
        [(equal? (symbol? x) #f) #f]
        [else (let* ([xList (string->list (symbol->string x))])      ; Change symbol to a list of characters
                (let* ([xRes (map check-letter-digit xList)])        ; Check every character to see if it is a letter or digit
                  (cond [(equal? (is-digit? (first xList)) #t) #f]   ; If first character is a number then false
                        [(>= (length (filter (lambda (tf) (equal? tf #f)) xRes)) 1) #f]   ; If there is 1 or more character that is not a letter or digit
                        [else #t]
                        )))]))

; Question 4

; Helper function for question 4. Checks if x is a valid (variable, truth value) pair. 

(define (check-vble-truth x)
  ; Check first element in list for valid variable
  (cond [(equal? (is-vble? (first x)) #f) #f]
        ; Check second element for valid truth value
        [(equal? (not (or (equal? (first (rest x)) 't)
                          (equal? (first (rest x)) 'f))) #t) #f]
        [else #t]))

(define (is-bool-env? x)
  (cond [(equal? (list? (first x)) #f) #f]
        ; If there are 1 or more pairs that are not valid (var truth-value) pairs then false
        [(>= (length (filter (lambda (tf) (equal? tf #f)) (map check-vble-truth x))) 1) #f] 
        [else #t]))
                            
; Question 5

; Simplify helper function adapted from https://www2.cs.sfu.ca/CourseCentral/383/tjd/racket_intro_cont.html simplify function
(define (simplify expr)
  (match expr
    ['t 't]
    ['f 't]
    [`(not (not ,a)) (simplify a)]
    [`(not ,a) (list 'not (simplify a))]
    [`(,a or ,b) (list (simplify a) 'or (simplify b))]
    [`(,a and ,b) (list (simplify a) 'and (simplify b))]
    [`(,a --> ,b) (list (simplify a) '--> (simplify b))]
    [_ (if (is-vble? expr) expr 'f)]))

; Evalate expression to true or false
(define (is-bool-expr? expr)
  (cond [(equal? (is-vble? expr) #t) #t]
        [else (match (simplify expr)
                ['t #t]
                ['f #f]
                [`(not ,a) #t]
                [`(,a or ,b) #t]
                [`(,a and ,b) #t]
                [`(,a --> ,b) #t]
                [_ #f])]))

; Question 6. Tips were given by T.A Madana Krishnan Vadakandara Krishnan to help solve this problem. 

; Helper functions

; Obtains the correspondng (variable, truth value) pair based on the given variable.
(define (get-truth-value-pair vble env)
  (if (equal? (assoc vble env) #f) (error "eval-bool: undefined variable") (assoc vble env)))

; replace-vbles-with-truth-vals function adapted from https://www2.cs.sfu.ca/CourseCentral/383/tjd/racket_intro_cont.html simplify function
(define (replace-vbles-with-truth-vals expr env)
  (match expr
    ['t 't]
    ['f 'f]
    [`(not (not ,a)) (eval-bool a env)]
    [`(not ,a) (list 'not (eval-bool a env))]
    [`(,a or ,b) (list (eval-bool a env) 'or (eval-bool b env))]
    [`(,a and ,b) (list (eval-bool a env) 'and (eval-bool b env))]
    [`(,a --> ,b) (list (eval-bool a env) '--> (eval-bool b env))]
    [expr (first (rest (get-truth-value-pair expr env)))]
    [_ (error "eval-bool: undefined variable")]))

; Evaluate the boolean expression, resulting expression may include not, and, or -->. 
(define (eval-bool-raw expr env)
  (let* ([truth_expr (replace-vbles-with-truth-vals expr env)])
    (match truth_expr

      ; base cases
      ['t 't]
      ['f 'f]

      [`(not t) 'f]
      [`(not f) 't]
    
      [`(t and t) 't]
      [`(t and f) 'f]
      [`(f and f) 'f]
      [`(f and t) 'f]

      [`(t or t) 't]
      [`(t or f) 't]
      [`(f or f) 'f]
      [`(f or t) 't]

      [`(t --> t) 't]
      [`(t --> f) 'f]
      [`(f --> f) 't]
      [`(f --> t) 't]

      ; Portion below adapted from https://www2.cs.sfu.ca/CourseCentral/383/tjd/racket_intro_cont.html simplify function
      ; If base cases are not matched, recurse
      [`(not (not ,a)) (eval-bool-raw a env)]
      [`(not ,a) (list 'not (eval-bool-raw a env))]
      [`(,a or ,b) (list (eval-bool-raw a env) 'or (eval-bool-raw b env))]
      [`(,a and ,b) (list (eval-bool-raw a env) 'and (eval-bool-raw b env))]
      [`(,a --> ,b) (list (eval-bool-raw a env) '--> (eval-bool-raw b env))]
      
      [_ (error "eval-bool: undefined variable")])))

; Evaluate the boolean expression and produce a 'f or 't result
(define (eval-bool expr env)
  (let* ([res_expr (eval-bool-raw expr env)])
    (match res_expr

      ; Cases 
      ['t 't]
      ['f 'f]

      [`(not t) 'f]
      [`(not f) 't]
    
      [`(t and t) 't]
      [`(t and f) 'f]
      [`(f and f) 'f]
      [`(f and t) 'f]

      [`(t or t) 't]
      [`(t or f) 't]
      [`(f or f) 'f]
      [`(f or t) 't]

      [`(t --> t) 't]
      [`(t --> f) 'f]
      [`(f --> f) 't]
      [`(f --> t) 't]
      
      [_ (error "eval-bool: undefined variable")])))

; Question 7

; Helper functions

; is-mem? function adapted from https://www2.cs.sfu.ca/CourseCentral/383/tjd/racket_intro_cont.html member function
; Checks if there are other elements that are the same within the list
(define (is-mem? x lst)
  (cond [(empty? lst) #f]
        [(equal? x (first lst)) #t]
        [else (is-mem? x (rest lst))]))

; Removes duplicates 
(define (remove-duplicates lst)  
  (cond [(empty? lst) '()]
        [(is-vble? lst) lst]                 ; if lst is a single variable
        [(empty? (rest lst)) lst]
        [(is-mem? (first lst) (rest lst))(remove-duplicates (rest lst))]   ; if there are other elements that are the same, remove it
        [else (cons (first lst)(remove-duplicates (rest lst)))]))

; get-vbles-raw adapted from https://www2.cs.sfu.ca/CourseCentral/383/tjd/racket_intro_cont.html simplify function
; Extracts all the variables (including duplicates)
(define (get-vbles-raw expr)
  (match expr
    ['t '()]
    ['f '()]
    [`(not (not ,a)) (get-vbles-raw a)]
    [`(not ,a) (flatten (list (get-vbles-raw a)))]
    [`(,a or ,b) (flatten (list (get-vbles-raw a) (get-vbles-raw b)))]
    [`(,a and ,b) (flatten (list (get-vbles-raw a) (get-vbles-raw b)))]
    [`(,a --> ,b) (flatten (list (get-vbles-raw a) (get-vbles-raw b)))]
    [_ (list expr)]))

(define (get-vbles expr)
  (remove-duplicates (get-vbles-raw expr)))

; Question 8. Function uses append as suggested by T.A Madana Krishnan Vadakandara Krishnan.

; Helper functions

; Function used to recursively call generate-truth-values until n. 
(define (recurse-generate-truth-values x n truth-values)
  (cond [(= x n) truth-values]
        [else (recurse-generate-truth-values (+ x 1) n (generate-truth-values (expt 2 x) truth-values))]))

; Adds 'f and 't to every existing truth-value combination, therefore doubling
; the number of truth-value combos and increasing the length of each combo by 1.
(define (generate-truth-values x truth-values)
  (cond [(= x 0) '()]
        [else (append (list (append (first truth-values) '(f))            
                            (append (first truth-values) '(t)))           
                      (generate-truth-values (- x 2) (rest truth-values)))]))              

(define (all-truth-values n)
  (recurse-generate-truth-values 1 (+ n 1) '(() ())))