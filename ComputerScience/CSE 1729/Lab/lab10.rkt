;1
;a
(define (head s) (car s))
(define (rest s) (force (cdr s)))

(define (lucas-stream)
  (define (counter current next)
    (cons current
          (delay (counter next (+ next current)))))
  (counter 1 3))
;b
(define (lucas-pseudoprime p)
  (define (luc n stream)
    (if (= n 1)
        (head stream)
        (luc (- n 1) (rest stream))))
  (let ((temp-luc (luc p (lucas-stream))))
    (= (modulo (- temp-luc 1) p) 0)))
;2
;a
(define (ll-stream)
  (define (ll-count i)
    (cons i
          (delay (ll-count  (- (* i i) 2)))))
  (ll-count 4))
;b
(define (ll-test-stream c)
  (define (ll-test-count i)
    (cons i
          (delay (ll-test-count (modulo (- (* i i) 2) c)))))
  (ll-test-count 4))
;3
(define (mprime? p)
  (define (ll-tester l-stream n)
    (if (= n 2)
        (= (head l-stream) 0)
        (ll-tester (rest l-stream) (- n 1))))
  (ll-tester (ll-test-stream (- (expt 2 p) 1)) p))