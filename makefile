
# sortserial: compiles the serial sorting code
# sortparallel: compiles the parallel sorting code
# runserialsort: run the serial sort program
# runparallelsort: run the parallel sort program


# files = linear.c
CC = gcc

searchserial: linear.c
	$(CC) -Wall -g -o linear linear.c

runserialsearch: linear
	./linear

searchparallel: linearPara.c
	$(CC) -Wall -g -o linearparallel linearPara.c

runparallelsearch: linearparallel
	./linearparallel

clean: 
	rm linear linearparallel createitems

createitems: createItems.c
	$(CC) -Wall -g -o createitems createItems.c

runcreate: createitems
	./createitems