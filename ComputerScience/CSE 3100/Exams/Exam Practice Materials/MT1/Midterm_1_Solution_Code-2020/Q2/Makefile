all: striptest st2

striptest : striptest.o strip.o
	cc -g -o $@ $^

st2 : st2.o strip.o
	cc -g -o $@ $^

%.o : %.c
	cc -c $<

clean:
	rm -rf *.o striptest *~

