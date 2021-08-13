
NAME = philo

# *********************** SRCS ************************************************ #

SRCS_DIR		= 	./
SOURSEC_FILES	= 	philo_mandatory_main.c\
					philo_mandatory_libft.c

SRCS			= $(addprefix $(SRCS_DIR)/, $(SOURSEC_FILES))

# *********************** HDRS ************************************************ #

INCLD_DIR 		= 	./
HEADERES		=	$(INCLD_DIR)philo_mandatory.h\

INCS			= $(addprefix $(INCLD_DIR)/, $(HEADERES))

# *********************** OBJ ************************************************* #

OBJS_DIR		= ./objects

OBJS			= $(addprefix $(OBJS_DIR)/, $(SOURSEC_FILES:.c=.o))

$(OBJS_DIR)/%.o: 	$(SRCS_DIR)/%.c $(INCS) Makefile
					@mkdir -p ${@D}
					$(CC) $(CFLAGS) -c $< -o $@

# ***************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -rf $(OBJS_DIR)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all
