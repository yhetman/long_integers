NAME = algos

CC = g++

FLAGS = -Wall  -g

HEADER = long_num.hpp

OBJ = main.o long_num.o

SRCS = main.cpp long_num.cpp 

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ) 

$(OBJ): $(SRCS) $(HEADER) 
		$(CC) $(FLAGS) -c $(SRCS) $(HEADER)

clean:
	rm -rf $(OBJ)
	rm -rf *.gch

fclean: clean
	rm -f $(NAME)

re: fclean all