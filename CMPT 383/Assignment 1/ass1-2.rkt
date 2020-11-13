#lang racket

; Question 1
; (my-length lst) adapted from https://www2.cs.sfu.ca/CourseCentral/383/tjd/racket-intro.html

(define (my-length lst)
  (if (empty? lst) 0
      (+ 1 (my-length (rest lst)))))

; Question 2

(define (onion n)
  (cond [(< n 0)(error "n negative")]
        [(equal? n 0)'()]
        [else (list (onion (- n 1)))]))

; Question 3

(define (my-last lst)
  (cond [(empty? lst)(error "empty list")]
        [(empty? (rest lst)) (first lst)]
        [else (my-last (rest lst))]))

; Question 4

(define (double-up lst)
  (cond [(empty? lst)'()]
        [else (cons (first lst)
                    (cons (first lst)(double-up (rest lst))))]))

; Question 5

(define (swap-ends lst)
  (cons (my-last lst) (append (rest lst)(first lst)))
  )

; Helper function for question 7 
; Helper function adapted from adapted from https://www2.cs.sfu.ca/CourseCentral/383/tjd/racket-intro.html

(define member1
  (lambda (x lst)
    (cond [(empty? (rest lst)) #f]
          [(equal? x (first (rest lst))) #t]
          [else (member1 x (rest lst))]
          )))

; Question 7

(define (is-relation? lst)
  (cond [(not (list? lst)) #f]
        [(empty? lst) #f]
        [(equal? (length (first lst)) 1) #f]
        [(> (length (first lst)) 2) #f]
        [(equal? (integer? (first (first lst))) #f) #f]
        [(equal? (integer? (first (rest (first lst)))) #f) #f]
        [(empty? (rest lst)) #t]
        [(equal? (member1 (first lst) lst) #t) #f]
        [(equal? (length (first lst)) 2)
         (is-relation? (rest lst))]))

; Helper function for question 8
; Helper function adapted from adapted from https://www2.cs.sfu.ca/CourseCentral/383/tjd/racket-intro.html

(define member2
  (lambda (x lst)
    (cond [(empty? (rest lst)) #f]
          [(equal? (first x) (first (first (rest lst)))) #t]
          [(equal? (first (rest x)) (first (rest (first (rest lst))))) #t]
          [else (member2 x (rest lst))]
          )))

; Question 8

(define (is-function? lst)
  (cond [(empty? lst) #f]
        [(not (equal? (is-relation? lst) #t)) #f]
        [(equal? (member2 (first lst) lst) #t) #f]
        [else #t]))

; Atom Counting

; Question 1

(define (atom? x)
  (cond [(number? x) #t]
        [(symbol? x) #t]
        [else #f]))

; Question 2

(define (count-atoms1 lst)
  (cond [(empty? lst) 0]
        [(atom? (first lst))
         (+ 1 (count-atoms1 (rest lst)))]
        [else (count-atoms1 (rest lst))]))

; Question 3

(define (count-atoms2 lst)
  (length (filter (lambda (tf) (equal? tf #t)) (map atom? lst))))

; test-suite for question 4

(define test-suite
  '((() 0)
    ((a) 1)
    ((2) 1)
    (("a") 0)
    ((a b) 2)
    ((3 1) 2)
    ((a 2) 2)
    (("a" b) 1)
    ((1 2 3 4) 4)
    ((a b c d) 4)
    ((1 a 2 3 b c) 6)
    ((1 a () 2 3 "m" b c (4 s 2)) 6)))

; Question 4

(define (check f suite)
  (cond [(empty? (rest suite)) "all tests passed"]                         
        [(not (equal? (f (first (first suite)))(first (rest (first suite)))))
         (printf "\"fail: (f ") (print (first (first suite)))
         (printf ") returned ") (print (f (first suite)))
         (printf "; expected ") (print (first (rest (first suite))))
         (printf "\"") (newline)
         (f (first (first (rest suite))))
         (check f (rest suite))]
        [(f (first (first (rest suite))))
         (check f (rest suite))]))