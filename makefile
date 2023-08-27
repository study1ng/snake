CC = g++
RM = rm -f
CFLAGS = -Wall -g -O0
LIBS = -lncurses -pthread

OBJS = MapElement.o Snake.o SnakeMap.o ConsoleScreen.o SnakeGame.o
TARGET = snake
MAIN = main.cpp

all: $(OBJS)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJS) $(LIBS) $(MAIN)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) *.o $(TARGET)

log: $(OBJS)
	$(CC) -o $(TARGET) $(LIBS) $(CFLAGS) $(OBJS) -DLOGGING

debug: $(OBJS)
	$(CC) -o $(TARGET) $(LIBS) $(CFLAGS) $(OBJS) -DDEBUG

debuglog: $(OBJS)
	$(CC) -o $(TARGET) $(LIBS) $(CFLAGS) $(OBJS) -DDEBUG -DLOGGING
