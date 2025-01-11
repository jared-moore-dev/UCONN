;1
;a
(define (devis x y)
  (zero? (remainder x y)))
         
(define (fizzbuzz x)
  (cond
    ((and (devis x 3) (devis x 5)) "fizzbuzz")
    ((devis x 3) "fizz")
    ((devis x 5) "buzz")
    ((#t) (x))
    )
  )
(fizzbuzz 6)

;b
(define (fizz x)
  (if (devis x 3) "fizz"))
(define (buzz x)
  (if (devis x 5) "buzz"))
(define (fizzbuzz2 x)
  (string-append (fizz x) (buzz x)))

;2
(define (peicewise x)
  (cond
    ((> x (* 2 3.142)) (- x (* 2 3.142)))
    ((and (or (> x -3.142) (= x -3.142)) (or (< x (* 2 3.142)) (= x (* 2 3.142)))) (sin x))
    ((< x -3.142) (- (- x) 3.142))
    )
  )
(peicewise -5)
(peicewise 0)
(peicewise 3)
(peicewise 10)
;3
(define (inc x) (+ x 1))
(define (dec x) (- x 1))

(define (add n m)
  (cond
    ((> n 0) (add (dec n) (inc m)))
    ((= n 0) m)
    ((< n 0) (add (inc n) (dec m)))
    )
  )
(add 3 4)

;4

(define (mult n m)
  (cond
    ((or (= n 0) (= m 0)) 0)
    ((<= n m) (add m (mult (dec n) m)))
    ((> n m) (add n (mult n (dec m))))
    )
  )
(mult 2 3)

;5
(define (power b n)
  (cond
    ((= n 0) 1)
    ((> n 0) (mult b (power b (dec n))))
    )
  )
(power 2 3)

;6
(define (raise b n)
  (cond
    ((= n 0) 1)
    ((= (modulo n 2) 1) (* b b))
    ((= (modulo n 2) 0) b)
    )
  )

;7
;a
(define (sumEven n)
  (cond
    ((= n 0) 0)
    ((= (remainder n 2) 0) (+ n (sumEven (- n 2))))
    ((#t) (+ n (sumEven (- n 1))))
    )
  )
;b
(define (sumOdd n)
  (cond
    ((= n 1) 1)
    ((= (remainder n 2) 0) (+ n (sumOdd (- n 1))))
    ((#t) (+ n (sumOdd (- n 2))))
    )
  )
;8
(define (h-product k)
  (cond
    ((= k 2) (- 1 (/ 1 k)))
    ((> k 2) (* (- 1 (/ 1 k)) (h-product (- k 1))))
    ((< k 2) 0)
    )
  )
;9
(define (divides a b) (= 0 (modulo b a)))

(define (divisors-upto n k)
  (cond
    ((= n 0) 0)
    ((= k 0) 0)
    ((= k 1) 1)
    ((divides k n) (+ 1 (divisors-upto n (- k 1))))
    ((#t) (divisors-upto n (- k 1)))
    )
  )

(define (divisors n) (divisors-upto n n))

;10
(define (subfact n)
  (cond
    ((= n 0) 1)
    ((= n 1) 0)
    ((> n 1) (* (- n 1) ( + (subfact (- n 1)) (subfact(- n 2)))))
    )
  )
;11
;def of factorial
(define (factorial n)
(if (= n 0) 1 (* n (factorial (- n 1)))))

(define (new-cos x n)
  (cond
    ((= n 0) 1)
    ((> n 0) (+ (* (expt x n) (/ (expt x (* n 2)) (factorial (* 2 n)))) (new-cos x (- n 1))))
    )
  )
