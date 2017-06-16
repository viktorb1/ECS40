p8.out : indexpager.o main.o pager.o  
	g++ -ansi -Wall -g -o p8.out  indexpager.o main.o pager.o

indexpager.o : indexpager.cpp indexpager.h 
	g++ -ansi -Wall -O3 -g -c  indexpager.cpp

main.o : main.cpp pager.h indexpager.h 
	g++ -ansi -Wall -g -c  main.cpp

pager.o : pager.cpp pager.h 
	g++ -ansi -Wall -g -c  pager.cpp

clean : 
	rm -f p8.out indexpager.o main.o pager.o  
