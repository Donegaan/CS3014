
# sortparallel: compiles the parallel sorting code
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

sortserial: mergesort.c
	$(CC) -Wall -g -o merge mergesort.c

runserialsort: 
	./merge

clean: 
	rm linear linearparallel createitems merge

createitems: createItems.c
	$(CC) -Wall -g -o createitems createItems.c

runcreate: createitems
	./createitems