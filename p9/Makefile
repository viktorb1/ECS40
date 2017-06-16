all: p9.out p9b.out

p9.out: main.cpp stack.cpp stack.h queue.cpp queue.h BST.h BST.cpp
	g++ -ansi -Wall main.cpp -o p9.out -DNDEBUG -g

p9b.out: main.cpp stack.cpp stack.h queue.cpp queue.h BST.h BST.cpp
	g++ -ansi -Wall main.cpp -o p9b.out

clean:
	rm -f p9.out p9b.out