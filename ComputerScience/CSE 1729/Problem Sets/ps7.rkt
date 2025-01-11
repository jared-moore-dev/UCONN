;1
(define (ins x l)
  (cond ((null? l) (list x))
        ((<= x (car l)) (cons x l))
        (else (cons (car l) (ins x (cdr l))))))
(ins 5 (list 1 2 4 6 8))
;2
(define (insSort ul)
  (define (is-help ul l)
    (cond ((null? ul) l)
          (else (is-help (cdr ul) (ins (car ul) l)))))
  (is-help ul '()))
(insSort (list 1 4 2 5 6 3 9 5))
;3
;helper

;b
(define (fold-left op init seq)
  (cond ((null? seq) init)
        (else (fold-left op (op (car seq) init) (cdr seq)))))

(define (fold-right op init seq)
  (fold-left op init (reverse seq)))
;a

;c
(define (my-map p sequence)
  (fold-right (lambda (x y) (cons (p x) y)) '() sequence))
;d
(define (my-append seq1 seq2) (fold-right cons seq2 seq1))
;e
(define (my-length sequence)
  (fold-right (lambda (x y) (+ y 1)) 0 sequence))
;f
(define (reverse-r sequence)
  (fold-right (lambda (x y) (append y (list x))) '() sequence))
;g
(define (reverse-l sequence)
  (fold-left (lambda (x y) (cons x y)) '() sequence))
;h
(define (horner-eval x cl)
  (fold-right (lambda (a b) (+ a (* x b))) 0 cl))
;4
;helper
(define (prime? n)
  (define (divisor? k) (= 0 (modulo n k)))
  (define (divisors-upto k)
    (and (> k 1)
         (or (divisor? k) (divisors-upto (- k 1)))))
  (if (= n 1)
      #f
  (not (divisors-upto (- n 1)))))

(define (reverse-and-append r-items rest)
(if (null? r-items) rest
(reverse-and-append (cdr r-items) (cons (car r-items) rest))))
(define (explode x)
  (define (exp-help x)
    (let* ((lnum (- x (* (floor (/ x 10)) 10))))
      (cond
        ((= 0 (floor (/ x 10))) (list x))
        (else (cons lnum (exp-help (floor (/ x 10)))))
        )
      )
    )
  (reverse-and-append (exp-help x) '()))
(explode 456)

(define (implode l)
  (let* ((x (length l)))
   (if (null? l)
        0
        (+ (* (expt 10 (- x 1)) (car l)) (implode (cdr l))))))

(define (find sequence test n)
(define (findhelper x i)
(cond ((and (test (sequence x)) (= (+ i 1) n )) (sequence x))
((test (sequence x)) (findhelper (+ x 1) (+ i 1)))
(else (findhelper (+ x 1) i))))
(findhelper 1 0))
  
;a
;i
(define (left-truncatable-prime? p)
  (cond ((and (prime? p) (> 10 p)) #t)
        ((prime? p)
         (let ((ep (explode p)))
           (if (or (= 0 (cadr ep)) (= 0 (car ep)))
               #f
           (left-truncatable-prime?
                     (implode (cdr ep))))))
        (else #f)))
(left-truncatable-prime? 9137)
(left-truncatable-prime? 6912950)
;ii
(define (nth-left-trunc-prime n)
  (find (lambda (x) x) left-truncatable-prime? n))
(nth-left-trunc-prime 5)
;b
;i
(define (right-truncatable-prime? p)
   (cond ((and (prime? p) (> 10 p)) #t)
        ((prime? p)
         (let ((ep (explode p)))
           (if (or (= 0 (cadr ep)) (= 0 (car ep)))
               #f
           (right-truncatable-prime?
                     (implode (reverse (cdr (reverse ep))))))))
        (else #f)))
;ii
(define (nth-right-trunc-prime n)
  (find (lambda (x) x) right-truncatable-prime? n))
;c
;i
(define (two-sided-prime? p)
  (if (and (right-truncatable-prime? p)(left-truncatable-prime? p))
      #t
      #f))
;ii
(define (nth-two-sided-prime n)
  (find (lambda (x) x) two-sided-prime? n))
;5
(define (make-tree value left right) (list value left right))
(define (value tree) (car tree))
(define (left tree) (cadr tree))
(define (right tree) (caddr tree))

;a
(define (tree-map t f)
  (if (null? t)
      '()
      (make-tree (f (value t))
                 (tree-map (left t) f)
                 (tree-map (right t) f))))
;6
(define (tree-equal? t t2)
  (define (eq-count t t2)
    (cond ((and (null? t) (null? t2)) 0)
          ((null? t) 1)
          ((null? t2) 1)
          ((eq? (value t) (value t2))
           (+ 0 (eq-count (left t) (left t2))
                (eq-count (right t) (right t2))))
          (else 1)))
  (if (= 0 (eq-count t t2))
      #t
      #f))
;7
;lecture
(define (insert x T)
  (cond ((null? T) (make-tree x '() '()))
        ((eq? x (value T)) T)
        ((< x (value T)) (make-tree (value T)
                                    (insert x (left T))
                                    (right T)))
        (else (make-tree (value T)
                         (left T)
                         (insert x (right T))))))

;ins-list
(define (insert-list L T)
  (if (null? L)
      T
      (insert-list (cdr L) (insert (car L) T))))
;sort-extract
(define (sort-extract T)
  (if (null? T)
      '()
      (append (sort-extract (left T))
              (list (value T))
              (sort-extract (right T)))))
;tree-sort
(define (tree-sort l)
  (sort-extract (insert-list l '())))