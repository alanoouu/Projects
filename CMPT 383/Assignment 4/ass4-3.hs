data Token = Num Double | UnaryOps | BinaryOps | StackManips deriving Show

calcStack :: String -> String
calcStack n = convertToTokens (words n)

convertToTokens :: [String] -> String
convertToTokens a 
    | (length a) == 1   = head a
    | otherwise         = (convertToTokens (tail a)) ++ " " ++ (possibleTokens (head a))

calc :: String -> String
calc n 
    | (length n) == 0               = "empty stack"
    | otherwise                     = convertToTokens (words n)

-- Unary Operators
-- From Basic Features
inc :: Double -> Double
inc n = n + 1

dec :: Double -> Double  
dec n = n - 1

mySqrt :: Double -> Double 
mySqrt n = sqrt n

mySin :: Double -> Double
mySin n = sin n

myCos :: Double -> Double 
myCos n = cos n

inv :: Double -> Double
inv n = 1/n

-- Binary Operators
add :: Double -> Double -> Double
add n m = n + m

mul :: Double -> Double -> Double
mul n m = n * m

sub :: Double -> Double -> Double
sub n m = n - m

div :: Double -> Double -> Double
div n m = n / m

addAll :: Double -> Double -> Double
addAll n m = n + m

mulAll :: Double -> Double -> Double
mulAll n m = n + m

-- Stack manipulators

push :: a -> [a] -> [a]
push x []   = [x]
push x a = x : a 

dup :: [a] -> [a]
dup [] = []
dup (x:xs) = x : x : xs

pop :: [a] -> a
pop []         = error "Can't pop an empty stack"
pop (x:xs)     = x

clear :: [a] -> [a]
clear x = []

swap :: [a] -> [a]
swap []          = error "Can't swap an empty stack"
swap (x:y:ys)    = y : x : ys

possibleTokens :: String -> String
possibleTokens x  
    -- Unary Operators
    | x == "inc"    = "inc"
    | x == "dec"    = "dec"
    | x == "sqrt"   = "mySqrt"
    | x == "sin"    = "mySin"
    | x == "cos"    = "myCos"
    | x == "inv"    = "inv"

    -- Binary Operators
    | x == "+" = "add"
    | x == "*" = "mul"
    | x == "-" = "sub"
    | x == "/" = "div"
    | x == "+all" = "addAll"
    | x == "*all" = "mulAll"

    -- Numbers
    | x == "0" = "0"
    | x == "1" = "1"
    | x == "2" = "2"
    | x == "3" = "3"
    | x == "4" = "4"
    | x == "5" = "5"
    | x == "6" = "6"
    | x == "7" = "7"
    | x == "8" = "8"
    | x == "9" = "9"

    
