;1a Harmonic Numbers


;1b Euler Estimate


;2 Primality test

(define (prime? n)
  (define (divisor? k) (= 0 (modulo n k)))
  (define (divisors-upto k)
    (and (> k 1)
         (or (divisor? k) (divisors-upto (- k 1)))))
  (and (> n 1)
       (not (divisors-upto (- n 1)))))

; 2 Count Primes


; 3 Relatively Prime


; 4a Lucas Numbers


; 4b Lucas Number Ratios


; 4c

;; This function represents the table shown in the PDF.
;; Simply "hard-code" the number of recursive call you believe
;; take place for inputs 3 through 6
(define (rec-call-lucas k)
    (cond ((= k 1)  -1)
          ((= k 2)  -1)
          ((= k 3)  -1)
          ((= k 4)  -1)
          ((= k 5)  -1)
          ((= k 6)  -1)
    ))

;; Do the same for the fast-lucas-helper
(define (rec-call-fast-lucas-helper k)
    (cond ((= k 1)  -1)
          ((= k 2)  -1)
          ((= k 3)  -1)
          ((= k 4)  -1)
          ((= k 5)  -1)
          ((= k 6)  -1)
    ))
;5a Half-Companion Pells



;5b Pells﻿


;5c (t n)


;5d (s n)


;5e Triangular Squares


;5f (square-tri n)


;6a Golden Ratio by continued fractions


;6b Golden Ratio by continued square root



;7 explain
(define (explain-interval-sum)
  (define a "One can never do  an induction on both inputs at once.")
  (define b "The base case isn't quite right. It needs to be updated to account for the two inductive calls.")
  (define c "The inductive case should be adding three things together.")
  (define d "The predicate to recognize the base case is wrong. One can go from m > n to m < n without ever seeing n = m.")
  (define e "I have no idea.")
  e)


; 8 Ackermann Function



; 9 Catalan numbers

