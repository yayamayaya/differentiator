mh = src/main_header.h

main:
	echo empty

graph:	file_reader.o expr_reader.o graph_create.o global.o
	g++ -o bin/graph bin/file_reader.o bin/expr_reader.o bin/graph.o bin/global.o

file_reader.o:	src/file_reader.cpp	$(mh)
	g++ -Wall -g -c src/file_reader.cpp -o bin/file_reader.o

expr_reader.o:	src/expression_reader.cpp $(mh)
	g++ -Wall -g -c src/expression_reader.cpp -o bin/expr_reader.o

graph_create.o:	graph/create_graph.cpp graph/create_graph.h $(mh)
	g++ -Wall -g -c graph/create_graph.cpp -o bin/graph.o

global.o:	src/global.cpp src/main_header.h
	g++ -Wall -g -c src/global.cpp -o bin/global.o

rg:
	valgrind --track-origins=yes --show-leak-kinds=all bin/graph
