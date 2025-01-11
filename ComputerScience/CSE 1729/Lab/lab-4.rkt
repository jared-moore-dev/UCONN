;1
(define (windchill W F)
  (let ((s (sqrt W)))
    (+ 1.05 (* .93 F) (* -3.65 W) (* 3.62 s) (* .103 F s) (* .0439 W W))
    )
  )
;2
(define (iradius A B C)
  (let ((s (/ (+ A B C) 2)))
    (sqrt (/ (* (- s A) (- s B) (- s C)) s))
    )
  )
;3
(define (pressure h)
  (let ((po 101325) (L .0065) (To 288.15) (g 9.80665) (M .0289644) (R 8.31447))
    (let ((main (- 1 (/ (* L h) To))) (xpo (/ (* g M) (* R L))))
      (* po (expt main xpo))
      )
    )
  )
;4
(define (compose f g)
  (define (compose-helper x)
    (f (g x))
    )
  compose-helper)
;5
;prob
(define (repeated f n)
  (cond
    ((= n 2) (compose f f))
    ((> n 2) (compose f (repeated f (- n 1))))
  )
)