CPPFLAGS=-g -O2 -Wall -Wextra -Iinclude -rdynamic
CC=g++
LDFLAGS=
NAME=minesweeper

VPATH=src

SOURCES=$(wildcard src/**/*.cpp src/*.cpp)
OBJECTS=$(patsubst src/%.cpp,src/%.o,$(SOURCES))

TARGET_EX=bin/$(NAME)

all: exec
exec: $(TARGET_EX)

$(TARGET_EX): $(OBJECTS) bin
	$(CC) -o $@ $(LDFLAGS) $(CFLAGS) $(OBJECTS)

bin:
	@mkdir -p bin

.PHONY:
clean:
	@$(RM) -r bin $(OBJECTS)
