(define (head s) (car s))
(define (rest s) (force (cdr s)))
;1
(define (take s k)
  (cond ((= k 0) '())
        (else (cons (head s) (take (rest s) (- k 1))))))
;2
(define (squaref x) (* x x))
(define (s-map f s)
  (if (null? s)
      '()
      (cons (f (car s))
            (delay (s-map f (rest s))))))
(define (square s)
  (s-map squaref (int-stream k)))
(define (square s)
  (cons (* (head s) (head s))
        (delay (square (rest s)))))
;3
(define (cubef x) (* x x x))
(define (cube s)
  (cons (* (head s) (head s) (head s))
        (delay (cube (rest s)))))
;4
(define (merge-streams s t)
  (cond ((null? s) t)
        ((null? t) s)
        ((< (head s) (head t))
         (cons (head s)
               (delay (merge-streams (rest s) t))))
        (else
         (cons (head t)
               (delay (merge-streams s (rest t)))))))
;5
(define (repeat x)
  (cons x
        (delay (repeat x))))
;6
(define (weave s1 s2)
  (cond ((null? s1) s2)
        ((null? s2) s1)
        (else
         (cons (head s1)
               (delay (weave s2 (rest s1)))))))
;7
(define (mul s1 s2)
  (cons (* (head s1) (head s2))
        (delay (mul (rest s1) (rest s2)))))
;8
(define (frac s)
  (cons (/ 1 (head s))
        (delay (frac (rest s)))))
;9
(define (pow x)
  (cons 1
        (delay (mul (pow x) (repeat x)))))
;10
(define (facts)
  (define (facts-help cur next)
  (cons cur
        (delay (facts-help (* cur next) (+ next 1)))))
  (facts-help 1 1))
;11
(define (expts x k)
  (fold-right (take (mul (pow x) (frac (facts))) k) + 0))