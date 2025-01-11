;1
(define (square-pair x)
  (cons x (* x x)))
;2
(define (rev p)
  (cons (cdr p) (car p)))
;3
;a
(define (c->p p)
  (let* ((x (car p)) (y (cdr p)) (r (sqrt(+ (* x x) (* y y)))) (theta (atan(/ y x))))
    (cons r theta)
    )
  )
;b
(define (p->c p)
  (let* ((r (car p)) (theta (cdr p)) (x (* r (cos theta))) (y (* r (sin theta))))
    (cons x y)
    )
  )
;4
(define (y p1 p2)
  (let* ((x1 (car p1)) (x2 (car p2)) (y1 (cdr p1)) (y2 (cdr p2)))
    (let* ((m (/ (- y2 y1) (- x2 x1))) (b (- y1 (* m x1))))
      (lambda (x)(+ (* m x) b))
      )
    )
  )