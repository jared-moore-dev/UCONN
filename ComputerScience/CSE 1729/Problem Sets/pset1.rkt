; 1
;a
(* (+ 22 42) (* 54 99))
;b
(* (* (+ 22 42) 54) 99)
;c
(+ (* 64 102) (* 16 (/ 44 22)))
;d
(define limerick (+ (/ (+ 12 144 20 (* 3 (sqrt 4))) 7) (* 5 11)))
limerick

;2
;a. While the two evaluate the same, their order of opperations is 
;   different and therefore they are evaluated in a differnt order,
;   despite coming to the same answer.
;b. Rules of precedence are not necessary for scheme, as functions
;   are embedded inside each other. Whichever function is to be run
;   first goes on the "inside" of another function.

;3
;a
(define (inc x) (+ x 1))
;b
(define (inc2 x) (+ 1 (inc x)))
;c
(define (cube x) (* x x x))
;d
(define (p x) (expt (+ (* x x x x x) (* 16 x x x x) (* 22 (* x x x)) x 9) 2))
;e
(define (ninth x) (cube (cube x)))
;f
(define (eighty-first x) (ninth (ninth x)))

;4
;a. This would have been difficult (without the expt function)
;   due to the need for 81 x's. It is much easier to write and build
;   function after function to deal with this problem

;5
;a
(define (isbn10-checkdigit x10 x9 x8 x7 x6 x5 x4 x3 x2)
  (
   (define (isbnsum)
     (+ (* 10 x10) (* 9 x9) (* 8 x8) (* 7 x7) (* 6 x6) (* 5 x5) (* 4 x4) (* 3 x3) (* 2 x2))
    )
   (if
     (equal? (modulo isbnsum 11) 11)
     0
     (modulo isbnsum 11)
   )
   )
 )
;b
(define (is-isbn10? x10 x9 x8 x7 x6 x5 x4 x3 x2 x1)
  (
   (equal? (isbn10-checkdigit x10 x9 x8 x7 x6 x5 x4 x3 x2) x1)
  )
 )

;6
(define (fspiral theta)
  (
   (expt 1.618  (* theta (/ 2 3.142)))
   )
)
;7
;a
(define (root1 a b c)
  (
   (/ (+ (* -1 b) (sqrt (- (* b b) (* 4 a c))) (* 2 a)))
  )
)
;b
(define (root2 a b c)
  (
   (/ (- (* -1 b) (sqrt (- (* b b) (* 4 a c))) (* 2 a)))
  )
)
;c
(define (number-of-roots a b c)
  (
   (define disc (- (* b b) (* 4 a c)))
   (cond
     [(> disc 0) 2]
     [(= disc 0) 1]
     [(< disc 0) ("2cmplx")]
  )
)
;d
(define (real-roots? a b c)
   (
    (not(equal? (number-of-roots a b c) "2cmplx"))
   )
)

;8
;a
(define (slant-height h a)
  (
   (define r (/ a 2))
   (sqrt (+ (* h h) (* r r)))
  )
)
;b
(define (side-area h a)
  (
   (/ (* (slant-height h a) a) 2)
  )
)
;c
(define (pyramid-area h a)
  (
   (+ (* 4 (side-area h a)) (* a a))
  )
)
;d
(define (pyramid-volume h a)
  (
   (/ (* a a h) 3)
  )
)
  
  