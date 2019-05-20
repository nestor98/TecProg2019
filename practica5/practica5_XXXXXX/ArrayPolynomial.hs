module ArrayPolynomial where
--import TupleListPolynomial
import Numeric

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



-- quita los ceros a la izquierda de un pol:
eliminarCeros :: ArrayPol -> ArrayPol
eliminarCeros (x:[]) = [x]
eliminarCeros (x:xs) 
    | x /= 0 = [x] ++ xs
    | x == 0 = eliminarCeros xs


-- multiplica un polinomio por una cte:
pmulCte :: ArrayPol -> Float -> ArrayPol
pmulCte p c = eliminarCeros (map (c*) p)


-- multiplica un pol por una variable (constante y su grado)
pmulVble :: ArrayPol -> Float -> Int -> ArrayPol
pmulVble p x g = pmulCte p x ++ (take g [0..])


-- pmulVble p (x:[]) = pmulCte p x
-- pmulVble p (x:xs) = pmulCte (p++xs) x
-- pmulVble _ _ = error("Has llamado mal a pmulVble, melon")
-- -- no se si se supone que se hace asi lo de los errores

pmulTwoRec :: ArrayPol -> ArrayPol -> Int -> ArrayPol
pmulTwoRec p1 (x2:[]) _ = pmulCte p1 x2 --error(showFFloat (Just 2) x2 " (ultimo elto del pol 2)")--
pmulTwoRec p1 (x2:xs2) l2 = (paddTwo) (pmulVble p1 x2 l2) (pmulTwoRec p1 xs2 (l2-1))


-- ****************    Por aqui esta el problema, se supone que algo de tipos:   ************************
-- Devuelve la multiplicacion de dos polinomios   
pmulTwo :: ArrayPol -> ArrayPol -> ArrayPol
pmulTwo p1 p2 = pmulTwoRec p1 p2 ((length p2)-1) --(paddTwo) (pmulVble p1 x2 l2) (pmulTwoRec p1 xs2 l2-1)
-- pmulTwo p1 (x2:[]) = pmulCte p1 x2 --error(showFFloat (Just 2) x2 " (ultimo elto del pol 2)")--

-- ******************************************************************************************************



--pmul :: [ArrayPol] -> ArrayPol
--pmul (x:xs) = foldr (pmulTwo) x xs
--pmul [] = []
--pmul (x:[]) = x




peval :: ArrayPol -> Float -> Float
peval p x = foldr (+) 0 (zipWith (*) p [x^i | i<-[l-1,l-2..0]])
	where 
		l=length(p)
peval [] x = 0
peval (p:[]) x = p


pderv :: ArrayPol -> ArrayPol
pderv p = zipWith (*) (init p) [(l-1),(l-2)..1]
	where
		l= fromIntegral (length(p)) ::Float

