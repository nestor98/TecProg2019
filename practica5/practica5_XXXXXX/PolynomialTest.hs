import ArrayPolynomial
--import TupleListPolynomial

main = do
    

        print (x)
        print (p2)
        print (psuma)
        --print (pmulCte psuma 3)
        --print (pmulVble p1 p3)
        --print (pmultip)
        print (peval psuma 3)
        where 
            p1 = x
            p2 = coef 3
            p3 = coef 4
            lp = [p1,p2,p3,[]]
            psuma = (padd lp)
            --pmultip = pmulVble psuma (pmulVble p1 p3)

        -- print p
        -- print (peval p  2.0)
        -- print dp
        -- print (peval dp 2.0)
        -- where
        --  p  = padd [(pmul [x,x]),(coef 3.0),(pmul [(coef 2.0),x])]
        --  dp = pderv p

