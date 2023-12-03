# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 18:19:18 by fmaqdasi          #+#    #+#              #
#    Updated: 2023/12/04 00:34:19 by fmaqdasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        := push_swap
CC          := cc
AR          := ar rcs
CFLAGS       := -Wall -Wextra -Werror
RM		    := rm -f

SRCS        :=            libft/ft_atoi.c \
                          libft/ft_bzero.c \
                          libft/ft_calloc.c \
                          libft/ft_isalnum.c \
                          libft/ft_isalpha.c \
                          libft/ft_isascii.c \
                          libft/ft_isdigit.c \
                          libft/ft_isprint.c \
                          libft/ft_itoa.c \
                          libft/ft_lstadd_back.c \
                          libft/ft_lstadd_front.c \
                          libft/ft_lstclear.c \
                          libft/ft_lstdelone.c \
                          libft/ft_lstiter.c \
                          libft/ft_lstlast.c \
                          libft/ft_lstmap.c \
                          libft/ft_lstnew.c \
                          libft/ft_lstsize.c \
                          libft/ft_memchr.c \
                          libft/ft_memcmp.c \
                          libft/ft_memcpy.c \
                          libft/ft_memmove.c \
                          libft/ft_memset.c \
                          libft/ft_putchar_fd.c \
                          libft/ft_putendl_fd.c \
                          libft/ft_putnbr_fd.c \
                          libft/ft_putstr_fd.c \
                          libft/ft_split.c \
                          libft/ft_strchr.c \
                          libft/ft_strdup.c \
                          libft/ft_striteri.c \
                          libft/ft_strjoin.c \
                          libft/ft_strlcat.c \
                          libft/ft_strlcpy.c \
                          libft/ft_strlen.c \
                          libft/ft_strmapi.c \
                          libft/ft_strncmp.c \
                          libft/ft_strnstr.c \
                          libft/ft_strrchr.c \
                          libft/ft_strtrim.c \
                          libft/ft_substr.c \
                          libft/ft_tolower.c \
                          libft/ft_toupper.c \
                          parsing.c \
                          printf/ft_printf.c \
                          printf/ft_printf_cs.c \
                          printf/ft_printf_du.c \
                          printf/ft_printf_fun.c \
                          printf/ft_printf_p.c \
                          printf/ft_printf_xX.c \
                          push_swap.c \
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


                          
OBJS        := $(addsuffix .o,$(basename $(SRCS)))

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			@echo "\033[1;32m $(NAME) created"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o
			@ echo "\033[1;31m Deleting objs"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "\033[1;31m Deleting $(NAME)"

re:			fclean all

.PHONY:		all clean fclean re