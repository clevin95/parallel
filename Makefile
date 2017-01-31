CC = icc 
CFLAGSa = -g -O0 -fno-alias -std=c99
CFLAGSb = -g -O1 -fno-alias -std=c99
CFLAGSc = -g -O3 -no-vec -no-simd -fno-alias -std=c99
CFLAGSd = -g -O3 -xHost -fno-alias -std=c99

all: piBench0 piBench1 piBench2 piBench3 vectorTri

piBench0: piBench.c
	$(CC) $(CFLAGSa) -o piBench0 piBench.c /home/fas/cpsc424/ahs3/utils/timing/timing.o	

piBench1: piBench.c
	$(CC) $(CFLAGSb) -o piBench1 piBench.c /home/fas/cpsc424/ahs3/utils/timing/timing.o	

piBench2: piBench.c
	$(CC) $(CFLAGSc) -o piBench2 piBench.c /home/fas/cpsc424/ahs3/utils/timing/timing.o	

piBench3: piBench.c
	$(CC) $(CFLAGSd) -o piBench3 piBench.c /home/fas/cpsc424/ahs3/utils/timing/timing.o	

vectorTri: vectorTri.c dummy.o
	$(CC) $(CFLAGS) -o vectorTri vectorTri.c /home/fas/cpsc424/ahs3/utils/timing/timing.o dummy.o

dummy.o: dummy.c dummy.h
	$(CC) $(CFLAGSa) -c dummy.c

clean : 
	rm piBench0 piBench1 piBench2 piBench3 vectorTri
