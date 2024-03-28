CFLAGS=-std=c++17 -Wall -Werror -Wextra
LIBS=-lmingw32
SOURCES=main.cpp selection.cpp messages.cpp user_choice.cpp

all: 
	g++ $(SOURCES) -o rpsls $(CFLAGS) -L$(LIBS)