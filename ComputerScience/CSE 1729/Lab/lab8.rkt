;givens
(define (create-heap v H1 H2)
  (list v H1 H2))
(define (h-min H) (car H))
(define (left H) (cadr H))
(define (right H) (caddr H))

;1
;a
(define (heap-insert f x H)
  (if (null? H)
      (create-heap x '() '())
      (let ((root-value (if (f x (h-min H)) x (h-min H)))
            (child-value (if (f x (h-min H)) (h-min H) x)))
               (create-heap root-value
                            (right H)
                            (heap-insert f child-value (left H))))))
;b
(define (combine f Ha Hb)
  (cond ((null? Ha) Hb)
        ((null? Hb) Ha)
        ((f (h-min Ha) (h-min Hb))
         (create-heap (h-min Ha)
                      Hb
                      (combine f (left Ha) (right Ha))))
        (else
         (create-heap (h-min Hb)
                      Ha
                      (combine f (left Hb) (right Hb))))))
;c
(define (empty? H)
  (if (null? H)
      #t
      #f))
;d
(define (heap-remove f H)
  (combine f (left H) (right H)))
