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
;1
(define (change k l)
  (let* ((ol (selSort l)))
    (define (change-aux n ol)
      (cond ((null? ol) 0)
            ((< n 0) 0)
            ((< (abs n) .0001) 1)
            (else (+ (change-aux (- n (car ol)) ol)
                     (change-aux n (cdr ol))))))
    (change-aux k ol)))
;2
(define (make-change n den)
  (if (null? den)
      (list '())
  (let* ((ol (selSort den)))
    (define (make-change-aux n ol cur)
      (cond ((null? ol)'())
            ((< n 0) '())
            ((= n 0) (list cur))
            (else (append (make-change-aux (- n (car ol)) ol (cons (car ol) cur))
                          (make-change-aux n (cdr ol) cur)))))
    (make-change-aux n ol '()))))
(make-change 11 '(25 10 5 1))
;3
(define (rle coins)
  (define (rle-help coins i prv)
    (cond ((null? coins) (list (cons i prv)))
          ((= prv 0) (rle-help (cdr coins) (+ i 1) (car coins)))
          ((= prv (car coins)) (rle-help (cdr coins) (+ i 1) (car coins)))
          (else (cons (cons i prv) (rle-help (cdr coins) 1 (car coins))))))
  (rle-help coins 0 0))

(rle (list 1 1 1 3 3 7 3 4 4 5))

;4
(define (rle-all lcoins)
  (cond ((null? lcoins) '())
        (else (cons (rle (car lcoins)) (rle-all (cdr lcoins))))))
;5
;a
(define (list-sum l)
  (cond ((null? l) 0)
        (else (+ (car l) (list-sum (cdr l))))))
;b
(define (average l)
  (* (/ 1 (length l)) (list-sum l)))
;c
(define (var-map l)
  (let* ((avg (average l)))
    (map (lambda (n) (expt (- n avg) 2)) l)))
;d
(define (stdev l)
  (sqrt (average (var-map l))))
;e
(define (map2 f x y)
  (cond ((null? x) '())
        (else (cons (f (car x) (car y))
                    (map2 f (cdr x) (cdr y))))))
;f
(define (covar-elements x y)
  (let* ((avgx (average x)) (avgy (average y)))
    (map2 (lambda (x y) (* (- x avgx) (- y avgy))) x y)))
;g
(define (pearson x y)
  (/ (average (covar-elements x y)) (* (stdev x) (stdev y))))
;6
;a
(define (best-fit x y)
  (let* ((a (* (pearson x y) (/ (stdev y) (stdev x))))
         (b (- (average y) (* a (average x)))))
    (cons a b)))
;b
(define (best-fit-fn px py)
  (let* ((a (* (pearson px py) (/ (stdev py) (stdev px))))
         (b (- (average py) (* a (average px)))))
    (lambda (x) (+ (* a x) b))))
;7
(define (merge l l2)
  (cond ((null? l) l2)
        ((null? l2) l)
        ((< (car l) (car l2)) (cons (car l)
                                    (merge (cdr l) l2)))
        (else (cons (car l2)
                    (merge l (cdr l2))))))
;8
(define (split l)
  (define (split-help l l2 l3)
    (cond ((null? l) (cons l2 (list l3)))
          ((even? (length l)) (split-help (cdr l) (cons (car l) l2) l3))
          (else (split-help (cdr l) l2 (cons (car l) l3)))))
  (split-help l '() '()))
(split (list 1 7 2 11 3 4 16 5 6 8 9))

(define (mergesort ul)
  (cond ((<= (length ul) 1) ul)
        (else (merge (mergesort (car (split ul))) (mergesort (cadr (split ul)))))))

(mergesort (list 7 5 3 4))

       

    