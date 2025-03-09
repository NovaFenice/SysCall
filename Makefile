CC = g++
CFLAGS = -Iinclude

TARGET = syscall

SRCS = main.cpp $(wildcard lib/*.cpp)

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

install:
	make
	cp ./syscall /usr/local/bin/syscall
