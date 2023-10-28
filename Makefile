prog: set.o main.o test.o
	g++ -fno-elide-constructors -std=c++11 set.o main.o test.o -o prog
	
main.o: main.cpp set.h
	g++ -fno-elide-constructors -std=c++11 main.cpp -c

set.o: set.cpp set.h
	g++ -fno-elide-constructors -std=c++11 set.cpp -c
	
test.o: test.cpp test.h
	g++ -fno-elide-constructors -std=c++11 test.cpp -c
	
clean: 
	rm -f *.o prog
