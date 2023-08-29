CC = g++
RM = rm -f
CFLAGS = -Wall -g -O3
LIBS = -lncurses -pthread -L/usr/local/lib -lboost_program_options

OBJS = MapElement.o Snake.o SnakeMap.o ConsoleScreen.o SnakeGame.o 
TARGET = snake
MAIN = main.cpp

all: $(OBJS)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJS) $(MAIN) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) *.o $(TARGET)
