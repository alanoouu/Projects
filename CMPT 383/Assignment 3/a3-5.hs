-- Question 1 
snoc :: a -> [a] -> [a]
snoc a [] = [a]
snoc a (x:xs) =  x : snoc a xs  

-- Question 2 
myappend :: [a] -> [a] -> [a]
myappend [] a = a
myappend (x:xs) a = x : myappend xs a

-- Question 3 
myreverse :: [a] -> [a]
myreverse [] = []
myreverse (x:xs) = myappend (myreverse xs) [x]

-- Question 4
-- Helper functions

-- smallest_divisor referenced from Example: Finding Primes https://www2.cs.sfu.ca/CourseCentral/383/tjd/haskell_functions_lhs.html
smallest_divisor :: Int -> Int
smallest_divisor n
    | n == 0    = 0
    | n == 1    = 1
    | otherwise = head (dropWhile (\x -> n `mod` x /= 0) [2..n])

-- is_prime referenced from Example: Finding Primes https://www2.cs.sfu.ca/CourseCentral/383/tjd/haskell_functions_lhs.html
is_prime :: Int -> Bool
is_prime n 
	| n < 2     = False
    | otherwise = (smallest_divisor n) == n

-- reverse_int from https://stackoverflow.com/questions/19725292/how-to-reverse-an-integer-in-haskell
reverse_int :: Int -> Int
reverse_int n = read . reverse . show $ n

-- Check if the number and its reverse is 1. different and 2. prime
is_emirp :: Int -> Bool
is_emirp n = if (not (n == (reverse_int n))) 
				&& (is_prime n) 
				&& (is_prime (reverse_int n))
			then True
			else False

count_emirps :: Int -> Int
count_emirps x = length (filter is_emirp [1..x])

-- Question 5

-- Helper function - Keeps track of the list with the greatest sum
find_biggest_sum :: [Int] -> [[Int]] -> [Int]
find_biggest_sum a [] = a
find_biggest_sum a (b:bs) =			-- b is the first element in xs
	if sum a > sum b then 
		find_biggest_sum a bs 
	else 
		find_biggest_sum b bs 

biggest_sum :: [[Int]] -> [Int]
biggest_sum (x:xs) = find_biggest_sum x xs

-- Question 7
is_bit :: Int -> Bool
is_bit x = if (x == 0 || x == 1) then True else False

-- Question 8
flip_bit :: Int -> Int
flip_bit x 
	| x == 0 	= 1
	| x == 1	= 0
	| otherwise = error "Number entered is not a bit"

-- Question 9
-- Part a
is_bit_seq1 :: [Int] -> Bool
is_bit_seq1 x 
	| x == [] 					= True
	| is_bit (head x) == False 	= False
	| otherwise 				= is_bit_seq1 (tail x)

-- Part B
is_bit_seq2 :: [Int] -> Bool
is_bit_seq2 x = 
	if x == [] then True
	else if is_bit (head x) == False then False
	else is_bit_seq2 (tail x)
		
-- Part C
is_bit_seq3 :: [Int] -> Bool
is_bit_seq3 x = not (length (filter (\y -> y == False) (map is_bit x)) > 0)
		
-- Question 10
-- Part a
invert_bits1 :: [Int] -> [Int]
invert_bits1 x
	| x == [] 		= []
	| otherwise 	= (flip_bit (head x)) : (invert_bits1 (tail x))

-- Part b
invert_bits2 :: [Int] -> [Int]
invert_bits2 x = map flip_bit x

-- Part c
invert_bits3 :: [Int] -> [Int]
invert_bits3 (x:xs) = (flip_bit x) : y
					where y = [flip_bit n | n <- xs]

 -- Question 11

 -- Helper function - Counts the number of bits that are "0"
bit_count_zero :: [Int] -> Int
bit_count_zero x
	| x == [] 		= 0
	| head x == 1	= bit_count_zero (tail x)
	| otherwise		= 1 + bit_count_zero (tail x)

-- Helper function - Counts the number of bits that are "1"
bit_count_one :: [Int] -> Int
bit_count_one x
	| x == [] 		= 0
	| head x == 0	= bit_count_one (tail x)
	| otherwise		= 1 + bit_count_one (tail x)

bit_count :: [Int] -> (Int, Int)
bit_count x = ((bit_count_zero x),(bit_count_one x))


data List a = Empty | Cons a (List a)
    deriving Show

 -- Question 13
toList :: [a] -> List a
toList []		= Empty
toList (x:xs) = Cons x (toList xs)

-- Question 14
toHaskellList :: List a -> [a]
toHaskellList Empty = []
toHaskellList (Cons x xs) = x : toHaskellList xs

-- Question 15
append :: List a -> List a -> List a
append Empty b = b
append (Cons a as) b = Cons a (append as b)

-- Question 16
removeAll :: (a -> Bool) -> List a -> List a
removeAll f Empty = Empty
removeAll f (Cons x xs) 
	| f x 		= removeAll f xs
	| otherwise	= Cons x (removeAll f xs)