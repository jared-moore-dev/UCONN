;given
(define (make-tree value left right)
  (list value left right))
(define (value T) (car T))
(define (right T) (caddr T))
(define (left T) (cadr T))
;1
(define (tree-size t)
  (if (null? t)
      0
      (+ 1 (tree-size (right t)) (tree-size (left t)))))
;2
(define (tree-depth t)
  (cond ((or (null? t) (and (null? (left t)) (null? (right t)))) 0)
        (else (let* ((left-depth (tree-depth (left t))) (right-depth (tree-depth (right t))))
                (if (> left-depth right-depth)
                    (+ 1 left-depth)
                    (+ 1 right-depth))))))
;3
(define (count-pred P t)
  (cond ((null? t) 0)
        ((P (value t)) (+ 1 (count-pred P (right t)) (count-pred P (left t))))
        (else (+ 0 (count-pred P (right t)) (count-pred P (left t))))))
;4
(define (count-one-child t)
  (cond ((null? t) 0)
        ((and (null? (right t)) (null? (left t))) 0)
        ((and (null? (right t)) (not (null? (left t)))) (+ 1 (count-one-child (left t))))
        ((and (not (null? (right t))) (null? (left t))) (+ 1 (count-one-child (right t))))
        (else (+ 0 (count-one-child (right t)) (count-one-child (left t))))))

(count-one-child (list 11 (list 22 (list 33 (list) (list)) (list)) (list)))


;5
(define (invert-bst t)
  (if (null? t)
      '()
      (make-tree (value t) (invert-bst (right t)) (invert-bst (left t)))))