cpkmeans: bin/cpkmeans.o bin/test.o
	g++ -g -pthread -o cpkmeans bin/*

bin/cpkmeans.o: src/cpkmeans.cc include/cpkmeans.hh
	g++ -g -c -pthread src/cpkmeans.cc -o bin/cpkmeans.o

bin/test.o: src/test.cc include/test.hh
	g++ -g -c -pthread src/test.cc -o bin/test.o

run: cpkmeans
	./cpkmeans
clean:
	rm bin/*
