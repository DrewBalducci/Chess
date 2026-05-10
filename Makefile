build:
	g++ -c *.cpp
clean:
	rm *.o
test:
	make build
	make clean
