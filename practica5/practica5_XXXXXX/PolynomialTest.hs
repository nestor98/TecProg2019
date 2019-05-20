import ArrayPolynomial
--import TupleListPolynomial

main = do
    

        print (x)
        print (p2)
        print (psuma)
        
        print (peval psuma 3)
        print (pderv psuma)
        print (pmulCte psuma 3)
        print (p1p3)
        print (pmultip)
        print (pcuad)
        where 
            p1 = x
            p2 = coef 3
            p3 = coef 4
            lp = [p1,p2,p3,[]]
            psuma = (padd lp)
            p1p3 = pmulVble p1 p3
            pmultip = pmulVble psuma p1p3
            pcuad = pmulTwo pmultip pmultip

        -- print p
        -- print (peval p  2.0)
        -- print dp
        -- print (peval dp 2.0)
        -- where
        --  p  = padd [(pmul [x,x]),(coef 3.0),(pmul [(coef 2.0),x])]
        --  dp = pderv p

