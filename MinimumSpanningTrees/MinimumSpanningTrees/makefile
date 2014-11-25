mst.out : main.o EdgeWeightedGraph.o
	g++ main.o EdgeWeightedGraph.o -o ../mst.out
main.o : main.cpp
	g++ -c main.cpp -std=c++1y -O3 -I..
EdgeWeightedGraph.o : EdgeWeightedGraph.cpp
	g++ -c EdgeWeightedGraph.cpp -std=c++1y -O3
clean :
	rm -r -f *.o *.out
