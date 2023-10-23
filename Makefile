NAME=physics01
CC=gcc
CFLAGS=$(shell pkg-config --cflags glfw3 glew) -g -Wall
LDFLAGS=$(shell pkg-config --libs glfw3 glew) -lm
OBJECTS=physics01.o mathlib.o object.o res.o r_shader.o scene.o r_camera.o

$(NAME): $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	rm -f $(NAME)

