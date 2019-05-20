import ArrayPolynomial
--import TupleListPolynomial

main = do
    

        print (x)
        print (p2)
        print (psuma)
        
        print (peval psuma 3)
        print (pderv psuma)
        print (pmulCte psuma 0)
        print (p1p3)
        print (pmultip)
        print (pcuad)   -- [16.0,224.0,784.0,0.0,1.0]                 [16.0,224.0,784.0,0.0,0.0]
        print (pcubo)   -- [64.0,1344.0,9408.0,21952.0,4.0,28.0,1.0]  [64.0,1344.0,9408.0,21952.0,0.0,0.0,0.0]
        print (pcubo2)  -- [64.0,1344.0,9408.0,21952.0,5.0,31.0,6.0]  [64.0,1344.0,9408.0,21952.0,0.0,0.0,0.0]
                        ------------  DEVUELVE -------------------- || ------ DEBERIA DEVOLVER -------------
        print (pcubo_pmul)
        where 
            p1 = x
            p2 = coef 3
            p3 = coef 4
            lp = [p1,p2,p3]
            psuma = (padd lp)
            p1p3 = pmulVble p1 4 0
            pmultip = pmulVble psuma 4 1
            pcuad = pmulTwo pmultip pmultip
            pcubo = pmulTwo pcuad pmultip
            pcubo2 = pmulTwo pmultip pcuad 
            pcubo_pmul = pmul [pmultip, pmultip, pmultip]



        -- print p
        -- print (peval p  2.0)
        -- print dp
        -- print (peval dp 2.0)
        -- where
        --  p  = padd [(pmul [x,x]),(coef 3.0),(pmul [(coef 2.0),x])]
        --  dp = pderv p

