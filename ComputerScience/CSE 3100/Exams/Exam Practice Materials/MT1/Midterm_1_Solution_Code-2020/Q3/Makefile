all: strupr strupr2

strupr : strupr.o upper.o
	cc -g -o $@ $^

strupr2: strupr2.o upper.o
	cc -g -o $@ $^

%.o : %.c
	cc -c $<

clean:
	rm -rf *.o strupr *~
