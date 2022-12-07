NAME = libmx.a
SRC = $(wildcard src/*.c)
HEADER = $(wildcard inc/*.h)

all: $(NAME) clean

$(NAME):
	mkdir -p obj
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc -c $(SRC)	
	mv *.o obj/
	ar rsc $(NAME) obj/*.o
	ranlib $(NAME)

clean:
	rm -rf obj

uninstall:
	rm -rf obj
	rm -rf $(NAME)

reinstall: uninstall all