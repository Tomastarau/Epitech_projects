{-
-- EPITECH PROJECT, 2022
-- $HASKELL FUNCTIONS
-- File description:
-- $HASKELL FUNCTIONS
-}

mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x = if x < 0
          then x * (-1)
          else x

myMin :: Int -> Int -> Int
myMin x y = if x < y
            then x
            else y

myMax :: Int -> Int -> Int
myMax x y = if x < y
            then y
            else x

myTuple :: a -> b -> (a , b)
myTuple a b = (a , b)

myTruple :: a -> b -> c -> (a , b , c )
myTruple a b c = (a, b, c)

myFst :: (a , b ) -> a
myFst (a, b) = a

mySnd :: (a , b) -> b
mySnd (a, b) = b

mySwap :: (a , b ) -> (b , a )
mySwap (a, b) = (b, a)

myHead :: [ a ] -> a
myHead [] = error "List can't be empty"
myHead (a:_) = a

myTail :: [a] -> [a]
myTail [] = error "List can't be empty"
myTail (_:a) = (a)

myLength :: [a] -> Int
myLength [] = 0
myLength (_:a) = 1 + myLength a

myNth :: [a] -> Int -> a
myNth [] _ = error "Index out of bounds"
myNth (x:_) 0 = x
myNth (_:xs) n
    | n < 0 = error "Negative index"
    | otherwise = myNth xs (n - 1)

myTake :: Int -> [a] -> [a]
myTake n _
       | n <= 0 = []
myTake _ [] = []
myTake n (x:xs) = x : myTake (n - 1) xs

myDrop :: Int -> [a] -> [a]
myDrop n xs | n <= 0 = xs
myDrop 0 xs = xs
myDrop _ [] = []
myDrop n (_:xs) = myDrop (n - 1) xs

myAppend :: [ a ] -> [ a ] -> [ a ]
myAppend [] ys = ys
myAppend (x:xs) ys = x : myAppend xs ys

myReverse :: [a] -> [a]
myReverse list = myReverseAux list []
          where
            myReverseAux [] acc = acc
            myReverseAux (x:xs) acc = myReverseAux xs (x:acc)

myInit :: [a] -> [a]
myInit [] = error "Empty list"
myInit [x] = []
myInit (x:xs) = x : myInit xs

myLast :: [ a ] -> a
myLast [] = error "Empty list not allowed"
myLast [x] = x
myLast (_:xs) = myLast xs

myZip :: [a] -> [b] -> [(a, b)]
myZip [] _ = []
myZip _ [] = []
myZip (x:xs) (y:ys) = (x, y) : myZip xs ys

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((x, y) : tuples) =
        let (xs, ys) = myUnzip tuples
        in (x : xs, y : ys)

myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap f (x:xs) = f x : myMap f xs
