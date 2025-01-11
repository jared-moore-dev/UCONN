;1
;a
(define (harmonic n)
  (cond
    ((= n 1) 1)
    ((> n 1) (+ (/ 1 n) (harmonic (- n 1))))
    )
  )
(harmonic 10)
;b
(define (Eulerest n)
  (- (harmonic n) (log n)))
(Eulerest 100)

;2
;given
(define (prime? n)
  (define (divisor? k) (= 0 (modulo n k)))
  (define (divisors-upto k)
    (and (> k 1)
         (or (divisor? k) (divisors-upto (- k 1)))))
  (not (divisors-upto (- n 1))))
;count primes
(define (count-primes m)
  (define (cphelp m i)
    (cond
      ((= m 1) i)
      ((and (> m 1) (prime? m)) (cphelp (- m 1) (+ i 1)))
      (else (cphelp (- m 1) i))
      )
    )
  (cphelp m 0)
  )
(count-primes 10)

;3
;given
(define (rel-prime a b)
  (define (divides-both d)
    (and (= 0 (modulo a d))
         (= 0 (modulo b d))))
  (define (divisor-upto k)
    (and (> k 1)
         (or (divides-both k)
             (divisor-upto (- k 1)))))
  (not (divisor-upto (min a b))))
;count
(define (count-rel-prime n)
  (define (crphelp a b i)
    (cond
      ((= b 1) (+ i 1))
      ((and (> b 1) (<= a 1) (rel-prime a b)) (crphelp (- b 1) (- b 1) (+ i 1)))
      ((and (> b 1) (>= a 1) (rel-prime a b)) (crphelp (- a 1) b (+ i 1)))
      ((and (> b 1) (<= a 1)) (crphelp (- b 1) (- b 1) i))
      ((and (> b 1) (>= a 1)) (crphelp (- a 1) b i))
      )
    )
  (crphelp n n 0)
  )
(count-rel-prime 10)
;4
;a
(define (lucas n)
  (cond
    ((= n 0) 2)
    ((= n 1) 1)
    ((> n 1) (+ (lucas (- n 1)) (lucas (- n 2))))
    )
  )
(lucas 0)
(lucas 1)
(lucas 5)
;b
(define (Lucas-ratio n)
  (+ 0.0 (/ (lucas n) (lucas (- n 1))))
  )
(Lucas-ratio 20)
(Lucas-ratio 21)
(Lucas-ratio 22)
;fib def
(define (fib n)
  (cond
    ((= n 0) 0)
    ((= n 1) 1)
    ((> n 1) (+ (fib (- n 1)) (fib (- n 2))))
    )
  )
(fib 3)
(fib 4)
(fib 5)
;fib ratio
(define (Fibonacci-ratio n)
  (+ 0.0 (/ (fib n) (fib (- n 1))))
  )
(Fibonacci-ratio 20)
(Fibonacci-ratio 21)
(Fibonacci-ratio 22)
;c
;given 1
(define (fast-Lucas-help n k luc-a luc-b)
  (if (= n k)
      luc-a
      (fast-Lucas-help n (+ k 1) (+ luc-a luc-b) luc-a)))
;given 2
(define (fast-Lucas n) (fast-Lucas-help n 1 1 2))
(fast-Lucas 50)
(fast-Lucas 500)

;Table 1
(define (rec-call-lucas k)
 (cond ((= k 1) 0)
  ((= k 2) 2)
  ((= k 3) 4)
  ((= k 4) 8)
  ((= k 5) 14)
  ((= k 6) 24)
))
;Table 2
(define (rec-call-fast-lucas-helper k)
(cond ((= k 1) 0)
((= k 2) 1)
((= k 3) 2)
((= k 4) 3)
((= k 5) 4)
((= k 6) 5)
))

;5
;a
(define (H n)
  (if (= n 0)
      1
      (+ (H (- n 1)) (* 2 (P (- n 1))))))
;b
(define (P n)
  (if (= n 0)
      0
      (+ (H (- n 1)) (P (- n 1)))))
;c
(define (t n)
  (if (even? n)
      (* 2 (* (P n) (P n)))
      (* (H n) (H n))))
;d
(define (s n)
  (* (H n) (P n)))
;e
(define (tri-square n)
  (/ (* (t n) (+ (t n) 1)) 2))
;f
(define (square-tri n)
  (* (s n) (s n)))

;6
;a
(define (golden n)
  (cond
    ((= n 1) 2)
    ((> n 1) (+ 1 (/ 1 (golden (- n 1)))))
    )
  )
;b
(define (golden-sqrt n)
  (cond
    ((= n 0) 1)
    ((> n 0) (sqrt (+ 1 (golden-sqrt (- n 1)))))
    )
  )
;7
(define (explain-interval-sum)
  (define a "One can never do  an induction on both inputs at once.")
  (define b "The base case isn't quite right. It needs to be updated to account for the two inductive calls.")
  (define c "The inductive case should be adding three things together.")
  (define d "The predicate to recognize the base case is wrong. One can go from m > n to m < n without ever seeing n = m.")
  (define e "I have no idea.")
  d)
;8
(define (ack m n)
  (cond
    ((= m 0) (+ n 1))
    ((and (> m 0) (= n 0)) (ack (- m 1) 1))
    ((and (> m 0) (> n 0)) (ack (- m 1) (ack m (- n 1))))
    )
  )
(ack 3 4)
(ack 4 0)
;9
(define (catalan n)
  (define (cat-help n k)
    (cond
      ((= k 0) 1)
      ((= k 1) 1)
      (else (* (/ (+ n k) k) (cat-help n (- k 1))))
      )
    )
  (cat-help n n)
  )
(catalan 10)