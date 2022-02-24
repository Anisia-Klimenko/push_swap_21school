NAME	=	push_swap
NAMEB	=	checker

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

OBJDIR	=	obj
SRCDIR	=	src
SRCDIRB	=	srcb
LIBDIR	=	libft

HEADER	=	push_swap.h
HEADERB	=	push_swap_bonus.h

SRC		=	$(SRCDIR)/main.c	\
			$(SRCDIR)/args.c	\
			$(SRCDIR)/push_swap.c	\
			$(SRCDIR)/stack.c	\
			$(SRCDIR)/prepare.c	\
			$(SRCDIR)/instructions.c	\
			$(SRCDIR)/instructions2.c	\
			$(SRCDIR)/process.c	\
			$(SRCDIR)/process2.c

SRCB	=	$(SRCDIRB)/checker_bonus.c	
			# $(SRCDIRB)/instructions_bonus.c	\
			# $(SRCDIRB)/instructions2_bonus.c	\
			# $(SRCDIRB)/stack_bonus.c

OBJ		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
OBJB	=	$(addprefix $(OBJDIR)/, $(SRCB:.c=.o))

LIBFT	=	libft.a

GRN 	=	\033[0;32m
RED 	=	\033[0;31m
YEL 	=	\033[1;33m
END 	=	\033[0m
TICK	=	\xE2\x9C\x94

.PHONY	:	all bonus clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			@make -C $(LIBDIR)/
			@cp $(LIBDIR)/$(LIBFT) ./
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
			@echo "\n\t$(GRN) $(TICK) PUSH_SWAP compiled!$(END)\n"

bonus	: 
# make OBJ="$(OBJB)" NAME="$(NAMEB)" SRCDIR="$(SRCDIRB)" HEADER="$(HEADERB)" all
# $(OBJB)
# $(CC) $(CFLAGS) $(OBJB) $(LIBFT) -o $(NAMEB)
		@echo "\n\t$(GRN) $(TICK) CHECKER compiled!$(END)\n"

$(OBJDIR)/$(SRCDIR)/%.o: 	$(SRCDIR)/%.c $(HEADER) Makefile
				$(CC) $(CFLAGS) -c $< -o $@

# $(OBJDIR)/$(SRCDIRB)/%.o: 	$(SRCDIRB)/%.c $(HEADERB) Makefile
# 				$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) :
	@mkdir $@ $@/$(SRCDIR) 
# $@/$(SRCDIRB)

$(OBJ) : | $(OBJDIR)
$(OBJB) : | $(OBJDIR)

clean:
	@echo "$(RED)clean ...$(END)"
	@make fclean -C $(LIBDIR)/
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)fclean ...$(END)"
	@rm -rf $(NAME)
	@rm -f $(LIBFT)

re: fclean all
