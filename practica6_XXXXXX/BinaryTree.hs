module BinaryTree where
--import TupleListPolynomial
--import Numeric



data Tree a = Tree a (Tree a) (Tree a) | Leaf a | Nill
  deriving Show

--empty :: Tree
empty = Tree 

-- Preguntar
--show :: Tree -> String
--show a =

leaf x = Leaf x

tree x lb rb = Tree x lb rb


preorder :: (Ord a) => Tree a -> [a]
preorden Nill = []
preorden (x lb rb) = [x] ++ preorder lb ++ preorder rb
