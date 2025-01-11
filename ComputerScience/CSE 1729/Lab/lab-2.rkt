d;1
(define (geom-series-np2 n)
   (if (> n 0)(+ (/ 1 (expt 2 n)) (geom-series-np2 (- n 1))) 1)
)
;2
(define (num-digits n)
   (if (> n 10)(+ 1 (num-digits(/ n 10))) 1)
)
;3
;a
(define (a n) (expt 2 n))
;b
(define (num-ancestors n)
   (if (> n 1)(+ (a n) (num-ancestors (- n 1))) 2)
)
;4
;def of factorial
(define (factorial n)
(if (= n 0) 1 (* n (factorial (- n 1)))))
;recoursive
(define (n-choose-k n k)
   (cond
     ((< n k) 0)
     ((< k 0) 0)
     (#t (/ (factorial n)(* (factorial(- n k)) (factorial k))))
   )
)

;5
(define (pascals-triangle n k)
  (cond
     ((and (= n 0) (= k 0)) 1)
     ((< k 0) 0)
     ((< n k) 0)
     ( #t (+ (pascals-triangle (- n 1) k) (pascals-triangle (- n 1) (- k 1))))
  )
)
