cb: src/main.o  src/graph_MST.o src/directed_MST.o
	g++ -O3 -o cb src/main.o src/graph_MST.o src/directed_MST.o
src/main.o:src/main.cpp
	g++ -c -O3 src/main.cpp -o src/main.o
src/graph_MST.o:src/graph_MST.cpp  src/graph_MST.hpp
	g++ -c -O3 src/graph_MST.cpp -o src/graph_MST.o
src/directed_MST.o:src/directed_MST.cpp  src/directed_MST.hpp
	g++ -c -O3 src/directed_MST.cpp -o src/directed_MST.o

clean:
	rm -rf *.o src/*.o *.outputs
