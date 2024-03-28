mh = src/main_header.h

diff:	file_reader.o expr_reader.o expr_reader.o graph_create.o global.o calc_expr.o
	g++ -Wall -o bin/differentiator bin/file_reader.o bin/expr_reader.o bin/graph.o bin/global.o bin/main.o bin/calc_expr.o

diff_debug:	 file_reader.o expr_reader.o expr_reader.o graph_create.o global.o calc_expr.o
	g++ -Wall -o -DDEBUG bin/differentiator bin/file_reader.o bin/expr_reader.o bin/graph.o bin/global.o bin/main.o bin/calc_expr.o


graph:	file_reader.o expr_reader.o graph_create.o global.o
	g++ -Wall -o graph/graph bin/file_reader.o bin/expr_reader.o bin/graph.o bin/global.o


main.o: src/main.cpp $(mh)
	g++ -Wall -g -c src/main.cpp -o bin/main.o

calc_expr.o: src/calculate_expressions.cpp src/expr_calc.h
	g++ -Wall -g -c src/calculate_expressions.cpp -o bin/calc_expr.o

file_reader.o:	src/file_reader.cpp	$(mh)
	g++ -Wall -g -c src/file_reader.cpp -o bin/file_reader.o

expr_reader.o:	src/expression_reader.cpp $(mh)
	g++ -Wall -g -c src/expression_reader.cpp -o bin/expr_reader.o

graph_create.o:	graph/create_graph.cpp graph/create_graph.h $(mh)
	g++ -Wall -g -c graph/create_graph.cpp -o bin/graph.o

global.o:	src/global.cpp src/main_header.h
	g++ -Wall -g -c src/global.cpp -o bin/global.o

rg:
	valgrind --track-origins=yes --show-leak-kinds=all graph/graph

rd:
	valgrind --track-origins=yes --show-leak-kinds=all bin/differentiator



log:
	g++ -Wall -g -S ../common/log.cpp -o bin/log.s

m:
	as bin/file_reader.s bin/expr_reader.s bin/graph.s bin/log.s	-o graph.o