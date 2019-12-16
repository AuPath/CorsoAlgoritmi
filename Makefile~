main: main.o eserciziCorsoAlgoritmi.o corsoAlgoritmi.o
	g++ main.o eserciziCorsoAlgoritmi.o corsoAlgoritmi.o 


main.o: main.cpp
	g++ -c main.cpp

corsoAlgoritmi.o: corsoAlgoritmi.cpp
	g++ -c corsoAlgoritmi.cpp

eserciziCorsoAlgoritmi.o: eserciziCorsoAlgoritmi.cpp
	g++ -c eserciziCorsoAlgoritmi.cpp

clean:
	rm *.o *.out
