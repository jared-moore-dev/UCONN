;1
;a
(define (pell n)
  (cond
    ((= n 0) 0)
    ((= n 1) 1)
    ((> n 1) (+ (* 2 (pell (- n 1))) (pell (- n 2))))
    )
  )
(pell 2)
(pell 3)
(pell 5)
(pell 6)
;b
(define (find-pell n)
  (find-pell-helper n 1))
(define (find-pell-helper n x)
(cond
((> n (pell x)) (find-pell-helper n (+ x 1)))
((< n (pell x)) (pell (- x 1)))
)
)
(find-pell 100)

;c
(define (comp-pell n)
  (cond
    ((= n 0) 2)
    ((= n 1) 2)
    ((> n 1) (+ (* 2 (comp-pell (- n 1))) (comp-pell (- n 2))))
    )
  )
;d
(define (sqrt-2-approx n)
  (/ (pell n) (comp-pell n))
  )
(sqrt-2-approx 6)
(pell 6)
(comp-pell 6)

;2
(define (num x)
  (cond
    ((> x 0) (sqrt (+ 2 (num (- x 1)))))
    ((= x 0) (sqrt 2))
    )
  )

(define (viete n)
  (cond
    ((> n 0) (* (/ (num n) 2) (viete (- n 1))))
    ((= n 0) (/ (sqrt 2) 2))
    )
  )

;3
(define (recourse x n)
  (cond
    ((> n 0) (/ (- x 1) (+ 2 (recourse x (- n 1)))))
    ((= n 0) 1)
    )
  )
(define (new-sqrt x n)
 (+ 1 (recourse x n))
  )
;4
(define (m91 n)
  (cond
    ((> n 100) (- n 10))
    ((< n 100) (m91 (m91 (+ n 11))))
    ((= n 100) (m91 (m91 (+ n 11))))
    )
  )