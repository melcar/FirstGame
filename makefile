all : build
build: Game.cpp fct.cpp
			g++ -c fct.cpp
			g++ -c Game.cpp  -lSDL2 -g  `sdl2-config --cflags --libs` `pkg-config --libs sdl2 --cflags sdl2` -Wall
			g++ fct.o Game.o  -lSDL2 -g  `sdl2-config --cflags --libs` `pkg-config --libs sdl2 --cflags sdl2` -Wall
			./a.out
clean :  fct.o Game.o
				rm fct.o Game.o
