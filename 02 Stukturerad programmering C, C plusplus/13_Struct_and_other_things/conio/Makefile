CC=clang
CFLAGS=-I.
DEPS = conio.h

%.o: %.c $(DEPS)
	$(CC) -v -c -o $@ $< $(CFLAGS)

all: main.o conio.o 
	$(CC) -v -o main main.o conio.o 

clean:
	rm main main.o conio.o
