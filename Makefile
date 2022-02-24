NAME = push_swap
NAMEB = checker

CC  = gcc
CFLAGS = -Wall -Wextra -Werror

OBJDIR = ./obj/
OBJDIRB = ./objb/
SRCDIR = ./src/
SRCDIRB = ./srcb/
LIBDIR = libft

HEADER = push_swap.h
HEADERB = push_swap_bonus.h

SRC_LIST = main.c \
   args.c \
   push_swap.c \
   stack.c \
   prepare.c \
   instructions.c \
   instructions2.c \
   process.c \
   process2.c

SRCB_LIST = main_bonus.c \
   checker_bonus.c \
   instructions_bonus.c \
   instructions2_bonus.c \
   stack_bonus.c \
   args.c \
   get_next_line.c	\
   get_next_line_utils.c


SRC = $(addprefix $(SRCDIR), $(SRC_LIST))
SRCB = $(addprefix $(SRCDIRB), $(SRCB_LIST))

OBJ  = $(addprefix $(OBJDIR), $(notdir $(SRC:.c=.o)))
OBJB = $(addprefix $(OBJDIRB), $(notdir $(SRCB:.c=.o)))

LIBFT = libft.a

GRN  = \033[0;32m
RED  = \033[0;31m
YEL  = \033[1;33m
END  = \033[0m
TICK = \xE2\x9C\x94

.PHONY : all bonus clean fclean re

all: 		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBDIR)/
			@cp $(LIBDIR)/$(LIBFT) ./
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
			@echo "\n\t$(GRN) $(TICK) PUSH_SWAP compiled!$(END)\n"


bonus: 		all $(NAMEB)

$(NAMEB): 	$(OBJB)
			@$(CC) $(CFLAGS) $(OBJB) $(LIBFT) -o $@
			@echo "\n\t$(GRN) $(TICK) CHECKER compiled!$(END)\n"

$(OBJDIR)%.o:  $(SRCDIR)%.c $(HEADER) Makefile
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIRB)%.o: $(SRCDIRB)%.c $(HEADERB) Makefile
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
		@mkdir $@ 

$(OBJDIRB):
		@mkdir $@ 

$(OBJ) : | $(OBJDIR)
$(OBJB) : | $(OBJDIRB)

clean:
	@echo "$(RED)clean ...$(END)"
	@make fclean -C $(LIBDIR)/
	@rm -rf $(OBJDIR)
	@rm -rf $(OBJDIRB)

fclean: clean
	@echo "$(RED)fclean ...$(END)"
	@rm -rf $(NAME)
	@rm -rf $(NAMEB)
	@rm -f $(LIBFT)

re: fclean all