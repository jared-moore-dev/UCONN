;1
;a
(define (list-at l i)
  (define (lahelp l n)
    (if (= n 0)
        (car l)
        (lahelp (cdr l) (- n 1))))
  (lahelp l i)
  )
;b
(define (selSort l)
  (define (smallest l)
    (define (smaller a b) (if (< a b) a b))
    (if (null? (cdr l))
        (car l)
        (smaller (car l) (smallest (cdr l)))))
  (define (remove v l)
    (if (null? l)
        l
        (if (equal? v (car l))
            (cdr l)
            (cons (car l) (remove v (cdr l))))))
  (if (null? l)
      '()
      (let* ((first (smallest l))
             (rest (remove first l)))
        (cons first (selSort rest)))))

(define (list-median l)
  (let* ((sorted (selSort l)) (leng (length sorted)) (half (floor (/ leng 2))))
    (cond
      ((even? leng) (/ (+ (list-at sorted half) (list-at sorted (- half 1))) 2))
      (else (list-at sorted half))
      )
    )
  )
;2
;a
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
(explode 451)
(explode 56)
;b
(define (implode l)
  (let* ((x (length l)))
   (if (null? l)
        0
        (+ (* (expt 10 (- x 1)) (car l)) (implode (cdr l))))))
;c
(define (sum-list list)
  (if (null? list)
      0
      (+ (car list)
         (sum-list (cdr list)))))
(define (has-property x)
  (let* ((sum (sum-list (explode x))) (t2 (implode (reverse (explode sum)))))
    (if (= x (* sum t2))
        #t
        #f)))
;d
(define (find sequence test n)
  (define (helper n k)
    (cond
      ((and (= n 0) (test (sequence (- k 1)))) (sequence (- k 1)))
      ((test (sequence k)) (helper (- n 1) (+ k 1)))
      (else (helper n (+ k 1))))
    )
  (helper n 1)
  )
;e
(define (fujiwara n)
  (find (lambda (x) x) (has-property x) n)
  )