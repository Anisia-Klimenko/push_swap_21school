NAME	=	push_swap

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

OBJDIR	=	obj
SRCDIR	=	src
LIBDIR	=	libft

HEADER	=	push_swap.h

SRC		=	$(SRCDIR)/main.c	\
			$(SRCDIR)/args.c	\
			$(SRCDIR)/push_swap.c	\
			$(SRCDIR)/stack.c	\
			$(SRCDIR)/prepare.c	\
			$(SRCDIR)/instructions.c	\
			$(SRCDIR)/instructions2.c	\
			$(SRCDIR)/process.c	\
			$(SRCDIR)/process2.c

OBJ		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

LIBFT	=	libft.a

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			@printf "\nCompiling libft ...\n"
			@make -C $(LIBDIR)/
			@cp $(LIBDIR)/$(LIBFT) ./
			@printf "DONE libft!\n\nCompiling push_swap ...\n"
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
			@printf "DONE push_swap! \n\n"

$(OBJDIR)/$(SRCDIR)/%.o: 	$(SRCDIR)/%.c $(HEADER)
				@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) :
	@mkdir $@ $@/$(SRCDIR)

$(OBJ) : | $(OBJDIR)

clean:
	@printf "clean... \n"
	@make fclean -C $(LIBDIR)/
	@rm -rf $(OBJDIR)

fclean: clean
	@printf "fclean... \n"
	@rm -rf $(NAME)
	@rm -f $(LIBFT)

re: fclean all
