# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 18:19:18 by fmaqdasi          #+#    #+#              #
#    Updated: 2023/12/07 20:18:00 by fmaqdasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := push_swap
NAMEB        := checker
CC          := cc
CFLAGS       := -Wall -Wextra -Werror
RM		    := rm -f
INCLUDE = -Ift_printf/ -Ilibft/
LIBFT_DIR = libft/
PRINTF_DIR = printf/
LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a

SRCS        :=            parsing.c \
						  parsingextra.c \
                          smallalgo.c \
                          sortedcheck.c \
                          stack.c \
                          stack_op_p.c \
                          stack_op_r.c \
                          stack_op_rr.c \
                          stack_op_s.c \
                          sorting.c \
                          sorting_util.c \
                          sorting_util2.c \
                          sorting_util3.c \
                          chunking_util.c \
                          freemem.c \
                          parsing_util.c \
                          main_util.c \

SRCS2        :=           checker_error.c \
                          checker_util.c \

SRCSM1       :=            push_swap.c \

SRCSM2       :=            checker.c \

                          
OBJS        := $(SRCS:.c=.o)
OBJS2        := $(SRCS2:.c=.o)
OBJSNAME    := $(SRCSM1:.c=.o)
OBJSNAME2   := $(SRCSM2:.c=.o)

LIBS = -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf

.c.o:
	@${CC} ${CFLAGS} $(INCLUDE) -c $< -o $@
    
${NAME}:	${OBJS} ${OBJSNAME} $(LIBFT) $(PRINTF)
			@${CC} ${CFLAGS} $(INCLUDES) ${OBJS} ${OBJSNAME} $(LIBS) -o ${NAME} 
			@echo "\033[0;32mPush swap compiled successfully"
$(LIBFT):
	        @make -C $(LIBFT_DIR) -s

$(PRINTF):
			@make -C $(PRINTF_DIR) -s
			
all:		${NAME}

bonus:	${OBJS} ${OBJS2} ${OBJSNAME2} $(LIBFT) $(PRINTF)
			@${CC} ${CFLAGS} $(INCLUDES) ${OBJS} ${OBJS2} $(LIBS) ${OBJSNAME2} -o ${NAMEB}
			@echo "\033[0;32mChecker compiled successfully"
	

clean:
			@${RM} *.o
			@make -C $(LIBFT_DIR) clean -s
			@make -C $(PRINTF_DIR) clean -s
			@echo "\033[0;31mObjects removed successfully"


fclean:		clean
			@${RM} ${NAME} ${NAMEB}
			@make -C $(LIBFT_DIR) fclean -s
			@make -C $(PRINTF_DIR) fclean -s
			@echo "\033[0;31mAll created objects were removed successfully"

re:			fclean all
			@echo "\033[0;32mPush swap was recompiled successfully"

.PHONY:		all clean fclean re bonus