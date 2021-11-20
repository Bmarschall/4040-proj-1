CFLAGS = -g -Wall -Werror -O3 -o
CC = g++

PROGRAM = lcs
CFILES = lcs.cc

${PROGRAM} :
	@${CC} ${CFLAGS} prog1 lcs.cc 

test:
	@echo "should be \n2 \nzwafee"
	@echo "-------------------\n"
	@./prog1 input.small
	@echo "-------------------\n"
	@echo "should be \n2 \nzwafee"
	@echo "-------------------\n"
	@./prog1 input1.small
	@echo "-------------------\n"
	@echo "should be \n7\nGTTCCTTGTGGAGTTCTGTCTAGGTTGC"
	@echo "-------------------\n"
	@./prog1 input.txt
	@echo "-------------------\n"
	@echo "should be \n7\nCGTAGAATCGGGGCGGGTACGATAAGTC"
	@echo "-------------------\n"
	@./prog1 input1.txt
	@echo "------------------\n"
	@echo "should be \n4\nCTTGAGTAGCTAGGCTGACT"
	@echo "-------------------\n"
	@./prog1 input2.txt
	@echo "-------------------\n"

clean:
	/bin/rm -f *.out prog1 ${PROGRAM} 