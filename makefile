cpkmeans: bin/cpkmeans.o bin/test.o
	g++ -g -pthread -Iinclude/ -o bin/cpkmeans bin/*

bin/cpkmeans.o: src/cpkmeans.cc include/cpkmeans.hh
	g++ -g -c -pthread -Iinclude/ src/cpkmeans.cc -o bin/cpkmeans.o

bin/test.o: src/test.cc include/test.hh
	g++ -g -c -pthread -Iinclude/ src/test.cc -o bin/test.o

run: cpkmeans
	./bin/cpkmeans
clean:
	rm bin/*
