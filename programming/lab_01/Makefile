all: test
bin:
	mkdir bin
bin/main.o: bin src/main.cpp | bin
	g++ src/main.cpp -c -Iinclude -o bin/main.o -Wall -Wextra -Werror
bin/functions.o: bin src/functions.cpp | bin
	g++ src/functions.cpp -c -Iinclude -o bin/functions.o -Wall -Wextra -Werror
test: bin/main.o bin/functions.o | bin
	g++ -o lab_01 bin/main.o bin/functions.o -Wall -Wextra -Werror
	./lab_01
clean:
	rm bin/*.o lab_01
	rmdir bin

