main: main.o eserciziCorsoAlgoritmi.o corsoAlgoritmi.o
	g++  main.o eserciziCorsoAlgoritmi.o corsoAlgoritmi.o

main.o: main.cpp
	g++  -c main.cpp

corsoAlgoritmi.o: corsoAlgoritmi.cpp
	g++  -c corsoAlgoritmi.cpp

eserciziCorsoAlgoritmi.o: eserciziCorsoAlgoritmi.cpp
	g++  -c eserciziCorsoAlgoritmi.cpp

test:
	cppcheck --enable=warning,style -i ~/Projects/C++/Algoritmi/.ccls-cache  ~/Projects/C++/Algoritmi/

test_valgrind:
	make && valgrind ./a.out
clean:
	rm *.o *.out	
