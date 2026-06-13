NAME        = pendu

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

INC_DIR     = inc

SRCS        = main.c srcs/pendu.c

# Transformation des .c en .o (Fichiers Objets)
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INC_DIR) $(OBJS) -o $(NAME)
	@echo "✨ Exécutable '$(NAME)' créé avec succès !"

# Règle pour compiler les fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "🧹 Fichiers objets (.o) supprimés."

fclean: clean
	rm -f $(NAME)
	@echo "🗑️  Exécutable '$(NAME)' supprimé."

re: fclean all

.PHONY: all clean fclean re