udg.out : CC.o Graph.o Path.o Search.o StringProcess.o SymbolGraph.o BreathFirstPath.o main.o 
	g++ CC.o Graph.o Path.o Search.o StringProcess.o SymbolGraph.o BreathFirstPath.o main.o -o udg.out
BreathFirstPath.o : BreathFirstPath.cpp
	g++ -std=c++1y -c BreathFirstPath.cpp -O3
CC.o : CC.cpp
	g++ -std=c++1y -c CC.cpp -O3
Graph.o : Graph.cpp
	g++ -std=c++1y -c Graph.cpp -O3
Path.o : Path.cpp
	g++ -std=c++1y -c Path.cpp -O3
Search.o : Search.cpp
	g++ -std=c++1y -c Search.cpp -O3
StringProcess.o : StringProcess.cpp
	g++ -std=c++1y -c StringProcess.cpp -O3
SymbolGraph.o : SymbolGraph.cpp
	g++ -std=c++1y -c SymbolGraph.cpp -O3
main.o : main.cpp
	g++ -std=c++1y -c main.cpp -O3 
clean : 
	rm -r -f *.o *.out
