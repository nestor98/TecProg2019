module BinaryTree where
--import TupleListPolynomial
--import Numeric



data BinTree a = Tree a (BinTree a) (BinTree a) | Leaf a | Nill 


empty :: BinTree a
empty = Nill


instance (Show a) => Show (BinTree a) where 
    show (Tree r i d) = (show r) ++ "(" ++ (show i) ++ "," ++ (show d) ++ ")"
    show (Leaf a) = show a
    show Nill = ""
-- Preguntar
--show :: Tree -> String
--show a =

leaf x = Leaf x

tree x lb rb = Tree x lb rb


size :: BinTree a -> Int
size (Leaf a) = 1
size (Nill) = 0
size (Tree r i d) = 1 + size i + size d



preorder :: BinTree a -> [a]
preorder (Leaf x) = [x]
preorder (Nill) = []
preorder (Tree x lb rb) = [x] ++ preorder lb ++ preorder rb


postorder :: BinTree a -> [a]
postorder (Leaf x) = [x]
postorder (Nill) = []
postorder (Tree x lb rb) = postorder lb ++ postorder rb ++ [x]

inorder :: BinTree a -> [a]
inorder (Leaf x) = [x]
inorder (Nill) = []
inorder (Tree x lb rb) = inorder lb ++ [x] ++ inorder rb 


add :: (Ord a) => BinTree a -> a -> BinTree a
add (Leaf t) x
    | x > t     = (Tree t Nill (Leaf x))
    | otherwise = (Tree x (Leaf t) Nill)
add (Nill) x = Leaf x
add (Tree r i d) x 
    | x > r = (Tree r i (add d x))
    | otherwise = (Tree r (add i x) d)




busq :: (Ord a) => BinTree a -> a  -> [a] 
busq (Nill) x  = []
busq (Tree r i d) x  
	| x==r = x:[]
	| x<r = r:(busq i x  )
	| x>r = r:(busq d x  )

between :: (Ord a) => BinTree a -> a -> a -> [a]
between (Tree r i d) xmin xmax 
     | r < xmin = between d xmin xmax
     | r > xmax = between i xmin xmax
     | r == xmin = (busq (Tree r i d) xmax)
     | r == xmax = (busq (Tree r i d) xmin) 
between (Nill) xmin xmax = []