{-
-- EPITECH PROJECT, 2022
-- $PROJECT_NAME
-- File description:
-- $DESCRIPTION
-}
myElem :: Eq a => a -> [ a ] -> Bool
myElem _ [] = False
myElem y (x:xs)
       | y == x = True
       | otherwise =  myElem y xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv a b = Just (a `div` b)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (x:_) 0 = Just x
safeNth (_:xs) n
    | n < 0 = Nothing
    | otherwise = safeNth xs (n - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just x) = Just (x + 1)

myLookup :: Eq a => a -> [( a , b ) ] -> Maybe b
myLookup _ [] = Nothing
myLookup n ((key, value):rest)
    | n == key = Just value
    | otherwise = myLookup n rest 

maybeDo :: ( a -> b -> c ) -> Maybe a -> Maybe b -> Maybe c
maybeDo f ma mb = f <$> ma <*> mb

isDigit :: Char -> Bool
isDigit c = c >= '0' && c <= '9'

readInt :: String -> Maybe Int
readInt [] = Nothing
readInt str@(x:xs)
    | (x == '-') && all isDigit xs = Just (read str)
    | all isDigit str = Just (read str)
    | otherwise = Nothing
  where
    isDigit c = c >= '0' && c <= '9'

getLineLength :: IO Int
getLineLength = do
              stringToConvert <- getLine
              let len = length stringToConvert
              return len

printAndGetLength :: String -> IO Int
printAndGetLength str = 
    putStrLn (str) >>
    return (length str)

printBox :: Int -> IO ()
printBox x
         | x < 1 = return ()
         | otherwise =
           putStrLn topBottomLine >>
           mapM_ putStrLn (replicate (x - 2) middleLine) >>
           putStrLn topBottomLine
         where
           topBottomLine = "+" ++ replicate ((x * 2) - 2) '-' ++ "+"
           middleLine = "|" ++ replicate ((x * 2) - 2) ' ' ++ "|"

main :: IO()
main = return()
