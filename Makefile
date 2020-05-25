# kompilator c
CCOMP = gcc

# konsolidator
LOADER = gcc

# opcje optymalizacji:
# wersja do debugowania
#OPT = -g -DEBUG 
# wersja zoptymalizowana do mierzenia czasu
OPT = -O3

# pliki naglowkowe
INC =

# biblioteki
LIB =  -lm 

F =  -fopenmp 

zad2: zad2.o 
	$(LOADER) $(F) $(OPT) zad2.o -o zad2 $(LIB)

zad2.o: zad2.c 
	$(CCOMP) $(F) -c $(OPT) zad2.c $(INC)

zad4w: zad4w.o 
	$(LOADER) $(F) $(OPT) zad4w.o -o zad4w $(LIB)

zad4w.o: zad4w.c 
	$(CCOMP) $(F) -c $(OPT) zad4w.c $(INC)

zad4z: zad4z.o 
	$(LOADER) $(F) $(OPT) zad4z.o -o zad4z $(LIB)

zad4z.o: zad4z.c 
	$(CCOMP) $(F) -c $(OPT) zad4z.c $(INC)

test: test.o 
	$(LOADER) $(F) $(OPT) test.o -o test $(LIB)

test.o: test.c 
	$(CCOMP) $(F) -c $(OPT) test.c $(INC)

clean:
	rm -f *.o
