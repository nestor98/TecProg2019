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






-- quita los ceros a la izquierda de un pol:
--eliminarCeros :: ArrayPol -> ArrayPol
--eliminarCeros (x:[]) = [x]
--eliminarCeros (x:xs) 
--    | x /= 0 = [x] ++ xs
--   | x == 0 = eliminarCeros xs


-- multiplica un polinomio por una cte:
--pmulCte :: ArrayPol -> Float -> ArrayPol
--pmulCte p c = (map (c*) p)--eliminarCeros 


-- multiplica un pol por una variable (constante y su grado)
--pmulVble :: ArrayPol -> Float -> Int -> ArrayPol
--pmulVble p x g = pmulCte p x ++ (take g [0,0..])


-- pmulVble p (x:[]) = pmulCte p x
-- pmulVble p (x:xs) = pmulCte (p++xs) x
-- pmulVble _ _ = error("Has llamado mal a pmulVble, melon")
-- -- no se si se supone que se hace asi lo de los errores

--pmulTwoRec :: ArrayPol -> ArrayPol -> Int -> ArrayPol
--pmulTwoRec p1 (x2:[]) _ = pmulCte p1 x2 --error(showFFloat (Just 2) x2 " (ultimo elto del pol 2)")--
--pmulTwoRec p1 (x2:xs2) l2 = (paddTwo) (pmulVble p1 x2 l2) (pmulTwoRec p1 xs2 (l2-1))


-- ****************    Por aqui esta el problema, se supone que algo de tipos:   ************************
-- Devuelve la multiplicacion de dos polinomios  

iguales :: TuplaPol -> TuplaPol
iguales (x:xs) = [((fst x)+(fst y),snd x) | y<-xs, (snd y)==(snd x)] 



sort :: TuplaPol -> TuplaPol
sort (x:xs) = sort [y | y<-xs, (snd y)>(snd x)] ++ (if iq==[] then [x] else iq ) ++ sort [y | y<-xs, (snd y)<(snd x)]
	where 
		iq= iguales (x:xs)
sort [] = []
sort (x:_) = [x]

 
pmulTwo :: TuplaPol -> TuplaPol -> TuplaPol
pmulTwo x y = sort [(c1*c2,l1+l2)|(c1,l1)<-x,(c2,l2)<-y]

--pmulTwoRec p1 p2 ((length p2)-1) --(paddTwo) (pmulVble p1 x2 l2) (pmulTwoRec p1 xs2 l2-1)
-- pmulTwo p1 (x2:[]) = pmulCte p1 x2 --error(showFFloat (Just 2) x2 " (ultimo elto del pol 2)")--

-- ******************************************************************************************************



pmul :: [TuplaPol] -> TuplaPol
pmul (x:xs) = foldr (pmulTwo) x xs
pmul [] = []
pmul (x:[]) = x












peval :: TuplaPol -> Float -> Float
peval p x = foldr (+) 0 [ c*x^pot | (c, pot) <- p ]


pderv :: TuplaPol -> TuplaPol
pderv p = [ (c*(fromIntegral (pot)), pot-1) | (c, pot) <- p, pot > 0 ]
--pderv p = [ (c*(fromIntegral (pot)), pot-1) | t <- p, let c=(fst t), let pot=(snd t), pot > 0 ]