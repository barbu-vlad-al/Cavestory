all:
	g++ -I /usr/include/SDL2 ./source/src/*.cpp -o cavestory -lSDL2 -lSDL2_image
