CFLAGS = -g -Wall -Werror -O3
CC = g++

PROGRAM = lcs.out
CFILES = lcs.cc

${PROGRAM} :
	${CC} ${CFLAGS} lcs.cc 

test:
	./a.out input.small
	./a.out input1.small
	./a.out input.txt
	./a.out input1.txt
	./a.out input2.txt

clean:
	/bin/rm -f *.o ${PROGRAM} 