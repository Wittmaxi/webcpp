
compile:
	-mkdir build
	g++ -c ./src/attributes.cpp -o ./build/attributes.o -O3
	g++ -c ./src/basic_tags.cpp -o ./build/basic_tags.o -O3
	g++ -c ./src/body_tags.cpp -o ./build/body_tags.o -O3
	g++ -c ./src/env_variables.cpp -o ./build/env_variables.o -O3
	g++ -c ./src/header_tags.cpp -o ./build/header_tags.o -O3
	g++ -c ./src/specialized_tags.cpp -o ./build/specialized_tags.o -O3
	g++ -c ./src/util.cpp -o ./build/util.o -O3
	ar rvs ./build/libwcp.a ./build/*.o

install: compile
	-sudo mkdir /usr/local/include/webcpp
	sudo cp ./build/libwcp.a /usr/local/lib/libwcp.a
	sudo cp ./src/header/* /usr/local/include/webcpp/

uninstall:
	sudo rm -r /usr/local/include/webcpp
	sudo rm /usr/local/lib/libwcp.a