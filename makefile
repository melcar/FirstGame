all : build
build: rpg.cpp fct.cpp
			g++ -c fct.cpp
			g++ -c rpg.cpp  -lSDL2 -g  `sdl2-config --cflags --libs` `pkg-config --libs sdl2 --cflags sdl2` -Wall
			g++ fct.o rpg.o  -lSDL2 -g  `sdl2-config --cflags --libs` `pkg-config --libs sdl2 --cflags sdl2` -Wall
			./a.out
clean :  fct.o rpg.o
				rm fct.o rpg.o 
