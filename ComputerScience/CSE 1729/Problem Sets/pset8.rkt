;1
;givens
(define (make-tree value left right) (list value left right))
(define (value tree) (car tree))
(define (left tree) (cadr tree))
(define (right tree) (caddr tree))
;problem
(define (arithvalue T)
  (cond ((equal? (value T) #\*)
         (* (arithvalue (left T)) (arithvalue (right T))))
        ((equal? (value T) #\+)
         (+ (arithvalue (left T)) (arithvalue (right T))))
        ((equal? (value T) #\-)
         (* -1 (arithvalue (left T))))
        ((equal? (value T) #\/)
         (/ 1 (arithvalue (left T))))
        (else (value T))))

;2
;helper
(define (l-max T)
  (if (null? (right T))
      (value T)
      (l-max (right T))))
;problem
(define (delete-value v T)
  (cond ((null? T) '())
        ((< (value T) v)
         (make-tree (value T) (left T) (delete-value v (right T))))
        ((> (value T) v)
         (make-tree (value T) (delete-value v (left T)) (right T)))
        ((null? (left T))
         (right T))
        (else (make-tree (l-max (left T))
                         (delete-value (l-max (left T)) (left T))
                         (right T)))))
;3
;given functions
(define (create-heap v H1 H2)
  (list v H1 H2))
(define (h-min H) (car H))

(define (insert x H)
  (if (null? H)
      (create-heap x '() '())
      (let ((child-value (max x (h-min H)))
            (root-value (min x (h-min H))))
        (create-heap root-value
                     (right H)
                     (insert child-value (left H))))))
(define (combine-heaps H1 H2)
  (cond ((null? H1) H2)
        ((null? H2) H1)
        ((< (h-min H1) (h-min H2))
         (create-heap (h-min H1)
                      H2
                      (combine-heaps (left H1) (right H1))))
        (else
         (create-heap (h-min H2)
                      H1
                      (combine-heaps (left H2) (right H2))))))
(define (heap-insert-l list H)
  (if (null? list)
      H
      (heap-insert-l (cdr list) (insert (car list) H))))

(define (remove-minimum H)
  (combine-heaps (left H) (right H)))

(define (heap-extract H)
  (if (null? H) '()
      (cons (h-min H)
            (heap-extract (remove-minimum H)))))

(define (hsort elements)
  (heap-extract (heap-insert-l elements '())))
;4
;helpers
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

(define (heap-remove f H)
  (combine f (left H) (right H)))

(define (heap-insert f x H)
  (if (null? H)
      (create-heap x '() '())
      (let ((root-value (if (f x (h-min H)) x (h-min H)))
            (child-value (if (f x (h-min H)) (h-min H) x)))
               (create-heap root-value
                            (right H)
                            (heap-insert f child-value (left H))))))

;a
(define (equalize-heaps heap-pair)
  (let ((l1 (caar heap-pair))
        (l2 (cadr heap-pair))
        (min-h (cdar heap-pair))
        (max-h (cddr heap-pair)))
    (cond ((>= 1 (abs (- l1 l2)))
           (cons (cons l1 min-h) (cons l2 max-h)))
          ((> l1 l2)
           (equalize-heaps (cons
                            (cons (- l1 1) (heap-remove > min-h))
                            (cons (+ l2 1) (heap-insert < (h-min min-h) max-h)))))
          ((< l1 l2)
           (equalize-heaps (cons
                            (cons (+ l1 1) (heap-insert > (h-min max-h) min-h))
                            (cons (- l2 1) (heap-remove < max-h))))))))
;b
(define (add-number x heap-pair)
  (let ((l1 (caar heap-pair))
        (l2 (cadr heap-pair))
        (min-h (cdar heap-pair))
        (max-h (cddr heap-pair)))
    (cond ((> x (h-min min-h))
           (equalize-heaps (cons
                            (cons l1 min-h)
                            (cons (+ l2 1) (heap-insert < x max-h)))))
          (else
           (equalize-heaps (cons
                            (cons (+ l1 1) (heap-insert > x min-h))
                            (cons l2 max-h)))))))

(add-number 2 '((1 1 ()()) 1 10 ()()))

(define (get-median heap-pair)
  (let ((l1 (caar heap-pair))
        (l2 (cadr heap-pair))
        (min-h (cdar heap-pair))
        (max-h (cddr heap-pair)))
    (cond ((= l1 l2) (/ (+ (h-min min-h) (h-min max-h)) 2))
          ((> l1 l2) (h-min min-h))
          (else (h-min max-h)))))
          
