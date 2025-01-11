CC = cc
CFLAGS = -g

all: freq rpn  poly

freq: freq.o
	$(CC) $(CFLAGS) -o $@ $<

rpn: rpn.o token.o stack.o
	$(CC) $(CFLAGS) -o $@ $^

poly: poly.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o *~ freq rpn poly *.dSYM
