{-
-- EPITECH PROJECT, 2022
-- $PROJECT_NAME
-- File description:
-- $DESCRIPTION
-}

data Tree a = Empty
     | Node (Tree a) a (Tree a)

instance Show a => Show (Tree a) where
    show Empty = "Empty"
    show (Node left value right) =
        "Node " ++ showSubTree left ++ " " ++ show value ++ " " ++ showSubTree right
      where
        showSubTree Empty = "Empty"
        showSubTree (Node l v r) = "(" ++ show (Node l v r) ++ ")"

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree newValue Empty = Node Empty newValue Empty
addInTree newValue (Node left currentValue right)
    | newValue < currentValue =
      Node (addInTree newValue left) currentValue right
    | otherwise =
      Node left currentValue (addInTree newValue right)


instance Functor Tree where
    fmap _ Empty = Empty
    fmap f (Node left value right) = Node (fmap f left) (f value) (fmap f right)