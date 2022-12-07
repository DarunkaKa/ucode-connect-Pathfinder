NAME = pathfinder

INC = $(wildcard inc/*.h)
SRC = $(wildcard src/*.c)
OBJ = $(addprefix obj/, $(notdir $(SRC:%.c=%.o)))

LIBMX = libmx
SRC_LIB = $(LIBMX)/libmx.a
INC_LIB = $(LIBMX)/inc

all: $(SRC_LIB) $(NAME)

$(NAME): $(OBJ)
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -g $(OBJ) -L$(LIBMX) -lmx -o $@

obj/%.o: src/%.c $(INC)
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -g -c $< -o $@ -I inc -I $(INC_LIB)

$(OBJ): | obj

obj:
	mkdir -p $@

$(SRC_LIB):
	make -sC $(LIBMX)
	
clean:
	rm -rf obj

uninstall:
	make -sC $(LIBMX) $@
	rm -rf obj
	rm -rf $(NAME)

reinstall: uninstall all
