mh = src/headers/main.h
dh = src/differentiation/differentiate.h
sh = src/simplification/simplificate.h

g = -DGRAPH
d = -DDEBUG

diff:	file_reader.o graph_create.o global.o calc_expr.o differen.o create_node.o rec_parsing.o tokenizator.o main.o simplificate.o
	g++ -Wall -o bin/differentiator bin/file_reader.o bin/graph.o bin/global.o bin/main.o bin/calc_expr.o bin/differen.o bin/create_node.o bin/tokenizator.o bin/rec_parsing.o bin/simplificate.o

parsing_test: tokenizator.o file_reader.o graph_create.o global.o create_node.o pars_test.o rec_parsing.o
	g++ -Wall -o bin/pars_test bin/tokenizator.o bin/file_reader.o bin/graph.o bin/global.o bin/pars_test.o bin/rec_parsing.o bin/create_node.o


graph:	file_reader.o expr_reader.o graph_create.o global.o
	g++ -Wall -o graph/graph bin/file_reader.o bin/expr_reader.o bin/graph.o bin/global.o


main.o: src/main.cpp $(mh)
	g++ -Wall -g $(d) $(g) -c src/main.cpp -o bin/main.o

calc_expr.o: src/simplification/calculate_expressions.cpp src/simplification/expr_calc.h
	g++ -Wall -g $(d) $(g) -c src/simplification/calculate_expressions.cpp -o bin/calc_expr.o

file_reader.o:	src/file_reading/file_reader.cpp	$(mh)
	g++ -Wall -g $(d) $(g) -c src/file_reading/file_reader.cpp -o bin/file_reader.o

expr_reader.o:	src/file_reading/expression_reader.cpp $(mh)
	g++ -Wall -g $(d) $(g) -c src/file_reading/expression_reader.cpp -o bin/expr_reader.o

graph_create.o:	graph/create_graph.cpp graph/create_graph.h $(mh)
	g++ -Wall -g $(d) $(g) -DGRAPH -c graph/create_graph.cpp -o bin/graph.o

global.o:	src/global.cpp $(mh)
	g++ -Wall -g $(d) $(g) -c src/global.cpp -o bin/global.o

differen.o: src/differentiation/differentiate.cpp $(mh) $(dh)
	g++ -Wall -g $(d) $(g) -c src/differentiation/differentiate.cpp -o bin/differen.o

create_node.o: ../common/tree_func/create_node.cpp $(mh)
	g++ -Wall -g $(d) $(g) -c ../common/tree_func/create_node.cpp -o bin/create_node.o

rec_parsing.o: src/parsing/rec_parsing.cpp $(mh)
	g++ -Wall -g $(d) $(g) -c src/parsing/rec_parsing.cpp -o bin/rec_parsing.o

tokenizator.o: src/parsing/tokenizator.cpp src/parsing/tokenizator.h $(mh)
	g++ -Wall -g $(d) $(g) -c src/parsing/tokenizator.cpp -o bin/tokenizator.o

pars_test.o: src/parsing/pars_test.cpp $(mh)
	g++ -Wall -g $(d) $(g) -c src/parsing/pars_test.cpp -o bin/pars_test.o

simplificate.o: src/simplification/simplificate.cpp $(sh)
	g++ -Wall -g $(d) $(g) -c src/simplification/simplificate.cpp -o bin/simplificate.o

rdv:
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all bin/differentiator

rd:
	bin/differentiator
	
rpt:
	valgrind --track-origins=yes --show-leak-kinds=all --leak-check=full bin/pars_test