
NAME = philo

# *********************** SRCS ************************************************ #

SRCS_DIR		= 	./
SOURSEC_FILES	= 	philo.c\
					philo_1_prsng_vldtn.c\
					philo_1_prsng_atoi.c\
					philo_1_vldtn_isdigits.c\
					philo_2_init.c\
					philo_3_time.c\
					philo_4_threads.c\
					philo_5_free.c\

SRCS			= $(addprefix $(SRCS_DIR)/, $(SOURSEC_FILES))

# *********************** HDRS ************************************************ #

INCLD_DIR 		= 	./
HEADERES		=	$(INCLD_DIR)philo.h\

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
