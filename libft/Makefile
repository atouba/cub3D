# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atouba <atouba@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 16:03:32 by atouba            #+#    #+#              #
#    Updated: 2021/11/20 13:28:55 by atouba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES_A = \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

FILES_B = 	ft_lstnew.c \
	  		ft_lstsize.c \
	  		ft_lstlast.c \
	  		ft_lstadd_back.c \
	  		ft_lstdelone.c \
	  		ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			
FILES = $(FILES_A) 

OBJS_O = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_O)
	ar -rc $(NAME) $(OBJS_O)
	
OBJS_B = $(FILES_B:.c=.o)

bonus: $(OBJS_B)
	ar -rc $(NAME) $(OBJS_B)

clean:
	$(RM) $(OBJS_O) $(OBJS_B)

fclean: clean
	$(RM) $(NAME) 

re: fclean all