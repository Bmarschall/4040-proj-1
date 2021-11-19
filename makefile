CFLAGS = -g -Wall -Werror -O3
CC = g++

PROGRAM = lcs
CFILES = lcs.cc

${PROGRAM} :
	${CC} ${CFLAGS} ${PROGRAM}

test:
	./a.exe input.small
	./a.exe input.txt
	./a.exe input1.txt
	./a.exe input2.txt

clean:
	/bin/rm -f *.o ${PROGRAM} 