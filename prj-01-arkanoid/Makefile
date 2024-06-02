CXX = g++
CC = $(CXX)

CXXFLAGS = -std=c++17 -pedantic -Wall -Wconversion -Werror 

CPPFLAGS = -I ./src -I ./inc

SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

check: main
	./main

main: main.o \
    src/screens/home.o \
    src/screens/screen_manager.o \
    src/screens/game.o \
    src/screens/over.o \
    src/screens/buten.o \
    src/game_manager.o \
    src/paddel/manage_pad.o \
    src/ball/manage_ball.o \
    src/blocks/manage_blocks.o \
    src/paddel/pad.o \
    src/blocks/block.o \
    src/ball/ball.o \
    src/sprite.o\
    src/live.o
	$(CXX) $(CXXFLAGS) -o main $^ $(SFML_LIBS)

		



main.o: main.cpp inc/screens/screen_manager.hpp inc/setting.hpp
src/screens/home.o: src/screens/home.cpp inc/screens/home.hpp inc/screens/screen.hpp
src/screens/screen_manager.o: src/screens/screen_manager.cpp inc/screens/screen_manager.hpp inc/screens/screen.hpp
src/screens/game.o: src/screens/game.cpp inc/screens/game.hpp inc/screens/screen.hpp
src/screens/buten.o: src/screens/buten.cpp inc/screens/buten.hpp 
src/screens/over.o: src/screens/over.cpp inc/screens/over.hpp inc/screens/screen.hpp
src/game_manager.o: src/game_manager.cpp inc/game_manager.hpp
src/pad.o: src/paddel/pad.cpp inc/paddel/pad.hpp
src/ball.o: src/ball/ball.cpp inc/ball/ball.hpp
src/block.o: src/blocks/block.cpp inc/blocks/block.hpp
src/paddel/manage_pad.o: src/paddel/manage_pad.cpp inc/paddel/manage_pad.hpp
src/manage_ball.o: src/ball/manage_ball.cpp inc/ball/manage_ball.hpp
src/manage_blocks.o: src/manage_blocks.cpp inc/manage_blocks.hpp
src/sprite.o: src/sprite.cpp inc/sprite.hpp
src/live.o: src/live.cpp inc/live.hpp




clean:
	@$(RM) *.o */*.o */*/*.o main