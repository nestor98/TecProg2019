module ArrayPolynomial where
--import TupleListPolynomial

type ArrayPol = [Float]


-- Esta función devolverá un polinomio que sólo contiene una x (el coeficiente degrado 1 vale 1)
x :: ArrayPol
x = [1,0] -- suponemos conversion automatica

-- Esta función devolverá un polinomio que   contenga   como 
-- término independiente la constante c (el coeficiente de grado 0 vale c)
coef :: Float -> ArrayPol
coef c = [c]



-- Devuelve la suma de dos polinomios de igual long
paddEqual :: ArrayPol -> ArrayPol -> ArrayPol
paddEqual x y = zipWith (+) x y



paddTwo :: ArrayPol -> ArrayPol -> ArrayPol
paddTwo x y
    | l1 > l2 = (take diffl1l2 x) ++ paddEqual (drop diffl1l2 x) y
    | l1 < l2 = (take diffl1l2 y) ++ paddEqual (drop diffl1l2 y) x
    | otherwise = paddEqual x y
    where 
        l1 = length x
        l2 = length y 
        diffl1l2 = abs (l1-l2)




--padd lp  –   Esta   función   suma   todos   
-- los   polinomios   que   haya   en   la   lista   lp   ydevuelve el resultado
padd :: [ArrayPol] -> ArrayPol
padd (x:xs) = foldr (paddTwo) x xs
-- padd (x:(y:xs)) = foldr (padd) [x] xs
padd [] = []
padd (x:[]) = x
-- aqui quedan solo dos polinomios, x e y:
--padd (x:(y:[])) = paddTwo x y
    


-- main = do
--      print p
--      print (peval p  2.0)
--      print dp
--      print (peval dp 2.0)
--      where
--          p  = padd [(pmul [x,x]),(coef 3.0),(pmul [(coef 2.0),x])]
--          dp = pderv p

