module TupleListPolynomial where
--import TupleListPolynomial


type TuplaPol = [(Float, Int)]


-- Esta función devolverá un polinomio que sólo contiene una x (el coeficiente degrado 1 vale 1)
x :: TuplaPol
x = [(1,1)] 

-- Esta función devolverá un polinomio que   contenga   como 
-- término independiente la constante c (el coeficiente de grado 0 vale c)
coef :: Float -> TuplaPol
coef c = [(c,0)]



paddTwo :: TuplaPol -> TuplaPol -> TuplaPol
paddTwo (x:xs) (y:ys) 
 | l1 > l2 = [x] ++ paddTwo xs (y:ys)
    | l1 < l2 = [y] ++ paddTwo ys (x:xs)
    | otherwise = [(c1+c2,l1)] ++ paddTwo ys xs
    where 
        l1 = snd x
        l2 = snd y
        c1 = fst x
        c2 = fst y
paddTwo [] y = y
paddTwo x [] = x
paddTwo [] [] = []


padd :: [TuplaPol] -> TuplaPol
padd (x:xs) = foldr (paddTwo) x xs
-- padd (x:(y:xs)) = foldr (padd) [x] xs
padd [] = []
--padd (x:[]) = x



peval :: TuplaPol -> Float -> Float
peval p x = foldr (+) 0 [ c*x^pot | (c, pot) <- p ]


pderv :: TuplaPol -> TuplaPol
pderv p = [ (c*(fromIntegral (pot)), pot-1) | (c, pot) <- p, pot > 0 ]
--pderv p = [ (c*(fromIntegral (pot)), pot-1) | t <- p, let c=(fst t), let pot=(snd t), pot > 0 ]