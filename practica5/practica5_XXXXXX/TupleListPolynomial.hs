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



-- -- Devuelve la suma de dos polinomios de igual long
-- paddEqual :: TuplaPol -> TuplaPol -> TuplaPol
-- paddEqual x y = zipWith (+) x y



-- paddTwo :: TuplaPol -> TuplaPol -> TuplaPol
-- paddTwo x y
--     | l1 > l2 = (take diffl1l2 x) ++ paddEqual (drop diffl1l2 x) y
--     | l1 < l2 = (take diffl1l2 y) ++ paddEqual (drop diffl1l2 y) x
--     | otherwise = paddEqual x y
--     where 
--         l1 = length x
--         l2 = length y 
--         diffl1l2 = abs (l1-l2)




-- --padd lp  –   Esta   función   suma   todos   
-- -- los   polinomios   que   haya   en   la   lista   lp   ydevuelve el resultado
-- padd :: [TuplaPol] -> TuplaPol
-- padd (x:xs) = foldr (paddTwo) x xs
-- -- padd (x:(y:xs)) = foldr (padd) [x] xs
-- padd [] = []
-- padd (x:[]) = x
-- -- aqui quedan solo dos polinomios, x e y:
-- --padd (x:(y:[])) = paddTwo x y



-- -- quita los ceros a la izquierda de un pol:
-- eliminarCeros :: TuplaPol -> TuplaPol
-- eliminarCeros (x:[]) = [x]
-- eliminarCeros (x:xs) 
--     | x /= 0 = [x] ++ xs
--     | x == 0 = eliminarCeros xs


-- -- multiplica un polinomio por una cte:
-- pmulCte :: TuplaPol -> Float -> TuplaPol
-- pmulCte p c = (map (c*) p)--eliminarCeros 


-- -- multiplica un pol por una variable (constante y su grado)
-- pmulVble :: TuplaPol -> Float -> Int -> TuplaPol
-- pmulVble p x g = pmulCte p x ++ (take g [0,0..])


-- -- pmulVble p (x:[]) = pmulCte p x
-- -- pmulVble p (x:xs) = pmulCte (p++xs) x
-- -- pmulVble _ _ = error("Has llamado mal a pmulVble, melon")
-- -- -- no se si se supone que se hace asi lo de los errores

-- pmulTwoRec :: TuplaPol -> TuplaPol -> Int -> TuplaPol
-- pmulTwoRec p1 (x2:[]) _ = pmulCte p1 x2 --error(showFFloat (Just 2) x2 " (ultimo elto del pol 2)")--
-- pmulTwoRec p1 (x2:xs2) l2 = (paddTwo) (pmulVble p1 x2 l2) (pmulTwoRec p1 xs2 (l2-1))


-- -- ****************    Por aqui esta el problema, se supone que algo de tipos:   ************************
-- -- Devuelve la multiplicacion de dos polinomios   
-- pmulTwo :: TuplaPol -> TuplaPol -> TuplaPol
-- pmulTwo p1 p2 = pmulTwoRec p1 p2 ((length p2)-1) --(paddTwo) (pmulVble p1 x2 l2) (pmulTwoRec p1 xs2 l2-1)
-- -- pmulTwo p1 (x2:[]) = pmulCte p1 x2 --error(showFFloat (Just 2) x2 " (ultimo elto del pol 2)")--

-- -- ******************************************************************************************************



-- pmul :: [TuplaPol] -> TuplaPol
-- pmul (x:xs) = foldr (pmulTwo) x xs
-- pmul [] = []
-- pmul (x:[]) = x




peval :: TuplaPol -> Float -> Float
peval p x = foldr (+) 0 [ c*x^pot | t <- p, let c = (fst t), let pot = (snd t) ]


pderv :: TuplaPol -> TuplaPol
pderv p = [ (c*potFloat, pot-1) | t <- p, let c=(fst t), let pot=(snd t), pot > 0, 
                                  let potFloat = fromIntegral (pot) ::Float ]