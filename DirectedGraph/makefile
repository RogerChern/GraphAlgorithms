all : sdg dg

sdg : SymbolMain.o SymbolDiGraph.o DirectedGraph.o DirectedAuxiliary.o
	clang++ SymbolMain.o SymbolDiGraph.o DirectedGraph.o DirectedAuxiliary.o -o sdg.out
SymbolMain.o : SymbolMain.cpp
	clang++ -c SymbolMain.cpp -std=c++1y -stdlib=libc++ -O3
SymbolDiGraph.o : SymbolDiGraph.cpp
	clang++ -c SymbolDiGraph.cpp -std=c++1y -stdlib=libc++ -O3

dg : DirectedGraph.o DirectedCycle.o DirectedAuxiliary.o main.o
	clang++ DirectedGraph.o DirectedCycle.o DirectedAuxiliary.o main.o -o dg.out
DirectedGraph.o : DirectedGraph.cpp
	clang++ -c DirectedGraph.cpp -std=c++1y -stdlib=libc++ -O3
DirectedCycle.o : DirectedCycle.cpp
	clang++ -c DirectedCycle.cpp -std=c++1y -stdlib=libc++ -O3
DirectedAuxiliary.o : DirectedAuxiliary.cpp
	clang++ -c DirectedAuxiliary.cpp -std=c++1y -stdlib=libc++ -O3
main.o : main.cpp
	clang++ -c main.cpp -std=c++1y -stdlib=libc++ -O3
clean :
	rm -r -f *.o *.out
