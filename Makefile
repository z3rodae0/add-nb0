all: add-nbo

sum-test: add-nbo.o
	g++ -o sum-test add-nbo.o
main.o: add-nbo.cpp

clean: 
	rm -f add-nbo
	rm -f *.o
