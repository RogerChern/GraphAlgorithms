sp.out : main.o EdgeWeighedDiGraph.o
	g++ main.o ../EdgeWeighedDiGraph.o -o sp.out
main.o : main.cpp
	g++ -c main.cpp -std=c++1y -O3 -I..
EdgeWeighedDiGraph.o : ../EdgeWeighedDiGraph.cpp
	g++ -c ../EdgeWeighedDiGraph.cpp -o../EdgeWeighedDiGraph.o -std=c++1y -O3
clean :
	rm -r -f *.o *.out
