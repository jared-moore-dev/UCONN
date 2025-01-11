;1
;Given
(define (sum term a next b)
  (if (> a b)
      0
      (+ (term a)
         (sum term (next a) next b))))
;my code
(define (harmonic n)
  (sum (/ 1 a) n (- n 1) 0)
  )   
;2
;a
(define (product term a next b)
  (if (> a b)
      1
      (* (term a)
         (product term (next a) next b))))
;b
(define (wallis-pi n)
  (product (* (/ (* 2 n) (- (* 2 n) 1)) (/ (* 2 n) (+ (* 2 n) 1))) 1 (- n 1) n)
  )
;3
(define (frac-sum f g n)
  (cond
    ((= (g n) 0) 0)
    (else (/ (f n) (g n)))
    )
  )
;4
;a
(define (der f h)
  (/ (- (f (+ x h)) (f x)) h)
  )
;b
(define (der-n f n h)
  (cond
    ((> n 0) 1)
    (else (der-n (der f h) (- n 1) h))
    )
  )
;5
;a
(define (newton f x n)
  (cond
    ((<= n 0) x)
    (else (- x (/ (f x) ((der f .01) x))) (- n 1))
    )
  )
;b

;6
;first
(define (sum-term term a b)
  (cond
    ((>= a b) 0)
    (else (+ (term a) (sum-term term (+ a 1) b)))
    )
  )


