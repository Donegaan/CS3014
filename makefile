
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
	$(CC) -Wall -g -fopenmp -o linearparallel linearPara.c

runparallelsearch: linearparallel
	./linearparallel

sortserial: mergesort.c
	$(CC) -Wall -g -o merge mergesort.c

runserialsort: 
	./merge
	
clean: 
	rm linear linearparallel createitems

createitems: createItems.c
	$(CC) -Wall -g -o createitems createItems.c

runcreate: createitems
	./createitems