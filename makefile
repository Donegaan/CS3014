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

sortparallel: mergeParallel.c
	$(CC) -Wall -g -fopenmp -o mergepara mergeParallel.c

runparallelsort: 
	./mergepara

createitems: createItems.c
	$(CC) -Wall -g -o createitems createItems.c

runcreate: createitems
	./createitems

clean: 
	rm linear linearparallel createitems merge mergepara