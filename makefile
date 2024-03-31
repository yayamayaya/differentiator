mh = src/headers/main.h
dh = src/headers/differentiate.h

diff:	file_reader.o expr_reader.o expr_reader.o graph_create.o global.o calc_expr.o differen.o create_node.o main.o
	g++ -Wall -o bin/differentiator bin/file_reader.o bin/expr_reader.o bin/graph.o bin/global.o bin/main.o bin/calc_expr.o bin/differen.o bin/create_node.o

diff_debug:	 file_reader.o expr_reader.o expr_reader.o graph_create.o global.o calc_expr.o
	g++ -Wall -o -DDEBUG bin/differentiator bin/file_reader.o bin/expr_reader.o bin/graph.o bin/global.o bin/main.o bin/calc_expr.o


graph:	file_reader.o expr_reader.o graph_create.o global.o
	g++ -Wall -o graph/graph bin/file_reader.o bin/expr_reader.o bin/graph.o bin/global.o


main.o: src/main.cpp $(mh)
	g++ -Wall -g -c src/main.cpp -o bin/main.o

calc_expr.o: src/simplification/calculate_expressions.cpp src/headers/expr_calc.h
	g++ -Wall -g -c src/simplification/calculate_expressions.cpp -o bin/calc_expr.o

file_reader.o:	src/file_reading/file_reader.cpp	$(mh)
	g++ -Wall -g -c src/file_reading/file_reader.cpp -o bin/file_reader.o

expr_reader.o:	src/file_reading/expression_reader.cpp $(mh)
	g++ -Wall -g -c src/file_reading/expression_reader.cpp -o bin/expr_reader.o

graph_create.o:	graph/create_graph.cpp graph/create_graph.h $(mh)
	g++ -Wall -g -c graph/create_graph.cpp -o bin/graph.o

global.o:	src/global.cpp $(mh)
	g++ -Wall -g -c src/global.cpp -o bin/global.o

differen.o: src/differentiation/differentiate.cpp $(mh) $(dh)
	g++ -Wall -g -c src/differentiation/differentiate.cpp -o bin/differen.o

create_node.o: src/create_node.cpp $(mh)
	g++ -Wall -g -c src/create_node.cpp -o bin/create_node.o

rd:
	valgrind --track-origins=yes --show-leak-kinds=all bin/differentiator