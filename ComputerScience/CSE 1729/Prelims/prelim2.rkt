;1
;a
(define (sum-digits n)
  (if (= n 0)
      0
      (+ n (sum-all-digits (- n 1)))))
;b

;2
(define (listmax l)
  (if (null? (cdr l))
      (car l)
      (max (car l)
           (listmax (cdr l)))))
(define (listmin l)
  (if (null? (cdr l))
      (car l)
      (min (car l)
           (listmin (cdr l)))))
(define (list-range l)
  (let* ((min (listmin l)) (max (listmax l)))
    (cons (- max min) (/ (- max min) (+ max min)))))
(list-range (list 1 2 3 4 5 6 7 8 9 10))
;3
;given
(define (maketree v left-tree right-tree)
(list v left-tree right-tree))
(define (value T) (car T))
(define (left T) (cadr T))
(define (right T) (caddr T))

;a
;i
(define (make-tree root left right)
  (list root left right))
;ii
(define (root T) (car T))
;iii
(define (value T) (car (root T)))
;iv
(define (count T) (cadr (root T)))

;b
(define (bst-insert val tree)
  (cond ((null? T) (maketree (cons val 1) '() '()))
        ((= v (value T)) (make-tree (cons val (+ (count T) 1))
                                    (left T)
                                    (right T)))
        ((< v (value T)) (make-tree (value T)
                                    (bst-insert val (left T))
                                    (right T)))
        ((> v (value T)) (make-tree (value T)
                                    (left T)
                                    (bst-insert val (right T))))))
;c
(define (bst-number v T)
  (cond ((null? T) 0)
        ((= v value T) (count T))
        ((< v (value T)) (bst-number v (left T)))
        ((> v (value T)) (bst-number v (right T)))))
;4
(define (is-heap? T)
  (cond ((null? T) #t)
        ((< (left T) (value T)) #f)
        ((< (right T) (value T)) #f)
        (else (is-heap? (right T))
              (is-heap? (left T)))))

