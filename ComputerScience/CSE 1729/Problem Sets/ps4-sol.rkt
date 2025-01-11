;1
;Given
(define (sum term a next b)
  (if (> a b)
      0
      (+ (term a)
         (sum term (next a) next b))))
;my code
(define (harmonic n)
  (define (inc x)
    (+ x 1))
  (define (inv x)
    (/ 1 x))
  (sum inv 1 inc n)
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
  (define (func x)
    (* (/ (* 2 x) (- (* 2 x) 1)) (/ (* 2 x) (+ (* 2 x) 1))))
  (define (inc x)
    (+ x 1))
  (product func 1 inc n)
  )
;3
(define (frac-sum f g n)
  (define (frac-help f g n i)
    (cond
      ((< n i) 0)
      ((= (g n) 0) (frac-help f g (- n 1) i))
      (else (+ (/ (f n) (g n)) (frac-help f g (- n 1) i)))
      )
    )
  (frac-help f g n (- n))
  )
;4
;a
(define (der f h)
  (define (der-help x)
     (/ (- (f (+ x h)) (f x)) h)
  )
  der-help
  )
;b
(define (der-n f n h)
  (cond
    ((= n 0) f)
    (else (der-n (der f h) (- n 1) h))
    )
  )
;5
;a
(define (newton f x n)
  (cond
    ((<= n 0) x)
    (else (newton f (- x (/ (f x) ((der f .01) x))) (- n 1)))
    )
  )
;b
(define (func x)
  (- (- (* x x) x) 1))
(newton func 2 10)
;6
;first
(define (sum-term term a b)
  (if (> a b)
      0
      (+ (term a)
         (sum-term term (+ a 1) b))))
;second
(define (simpson-integrate f a b n)
  (let* ((deltax (/ (- b a) n)))
    (define (term-finder i)
      (cond
        ((= i n) (* 1 (f (+ a (* deltax i)))))
        ((= i 0) (* 1 (f (+ a (* deltax i)))))
        ((even? i) (* 2 (f (+ a (* deltax i)))))
        ((odd? i) (* 4 (f (+ a (* deltax i)))))
        )
      )
  (* (/ deltax 3) (sum-term term-finder 0 n))
  ))


