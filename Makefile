main: main.o eserciziCorsoAlgoritmi.o corsoAlgoritmi.o
	g++ -std=c++11 main.o eserciziCorsoAlgoritmi.o corsoAlgoritmi.o 


main.o: main.cpp
	g++ -std=c++11 -c main.cpp

corsoAlgoritmi.o: corsoAlgoritmi.cpp
	g++ -std=c++11 -c corsoAlgoritmi.cpp

eserciziCorsoAlgoritmi.o: eserciziCorsoAlgoritmi.cpp
	g++ -std=c++11 -c eserciziCorsoAlgoritmi.cpp

clean:
	rm *.o *.out
