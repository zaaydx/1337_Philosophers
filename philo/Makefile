
NAME			= philo

CC 				= gcc

SRCS			= 	main.c \
					philosophers.c \
				  	arguments.c \
					threads.c \
				  	utiles1.c \
				  	utiles2.c \
				  	Initialization.c \

OBJS			= $(SRCS:.c=.o)

FLAGS			= -Wall -Wextra -Werror

RM				= rm -rf 

all:			$(NAME)

$(NAME):		$(OBJS)
		$(CC) ${FLAGS} -o ${NAME} ${OBJS}

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re