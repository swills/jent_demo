CFLAGS=-I/usr/local/include -L/usr/local/lib -ljitterentropy
SRC=	jent.c
all: jent

clean:
	rm jent

test: all
	./jent
	ent -b jent_out
