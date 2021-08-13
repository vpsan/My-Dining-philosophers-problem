NAME = philo

SRCS	=	$(ALL)

# *********************** ALL ************************************************ #

ALL_DIR 	= 	./
ALL		= 	$(ALL_DIR)philo_mandatory_main.c \
			$(ALL_DIR)philo_mandatory_libft.c

# *********************** HDRS ************************************************ #

INCLD 	= 	./
HDRS	=	$(INCLD)philo_mandatory.h\

# *********************** LIBFT *********************************************** #

OBJ		=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
.c.o:
			@$(CC) $(CFLAGS) -I$(INCLD) -c $< -o $(<:.c=.o)

clean:
			@rm -rf $(OBJ)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all