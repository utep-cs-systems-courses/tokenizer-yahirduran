OBJS = uimain.o history.o tokenizer.o

CFLAGS=-g -O3

all: uimain

uimain: $(OBJS)

	cc -o tokenizer  $(CFLAGS) $(OBJS)

$(OBJS):history.h tokenizer.h

clean:
	rm -f *.o uimain

run:uimain
	./uimain
