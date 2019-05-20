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







peval :: TuplaPol -> Float -> Float
peval p x = foldr (+) 0 [ c*x^pot | (c, pot) <- p ]


pderv :: TuplaPol -> TuplaPol
pderv p = [ (c*(fromIntegral (pot)), pot-1) | (c, pot) <- p, pot > 0 ]
--pderv p = [ (c*(fromIntegral (pot)), pot-1) | t <- p, let c=(fst t), let pot=(snd t), pot > 0 ]