;1
;usd to euro exchange function and rate
(define usd-euro-rate .84)
(define (usd-to-euro x)
  (* x usd-euro-rate))
;test
(usd-to-euro 250)

;euro to yen exchange function and rate
(define euro-yen-rate 125.92)
(define (euro-to-yen x)
  (* x euro-yen-rate))
;test
(euro-to-yen 250)

;usd to yen exchnage function
(define (usd-to-yen x)
  (euro-to-yen
   (usd-to-euro x)
  )
 )
;test
(usd-to-yen 250)

;2
;Defining e
(define e 2.71828)
;Defining the function
(define (tanh x)
  (/ (- (expt e (* 2 x)) 1) (+ (expt e (* 2 x)) 1)))
;test
(tanh .3)

;3
;Defining det2x2
(define (det2x2 a b c d)
  (- (* a d) (* b c ))
  )
;test
(det2x2 2 -4 -6 12)

;Defining Invertible
(define (invertible? a b c d)
  (not(= (det2x2 a b c d)  0 ))
  )
;test
(invertible? 2 -4 -6 12)

;Compute Product Direct
(define (prod-inv-direct? a1 b1 c1 d1 a2 b2 c2 d2)
  (invertible? (+ (* a1 a2) (* b1 c2)) (+ (* a1 b2) (* b1 d2)) (+ (* c1 a2) (* d1 c2)) (+ (* c1 b2) (* d1 d2) ) )
  )

;Compute Product Indirect
(define (prod-inv-indirect? a1 b1 c1 d1 a2 b2 c2 d2)
  (not(= (* (det2x2 a1 b1 c1 d1) (det2x2 a2 b2 c2 d2)) 0))
  )
