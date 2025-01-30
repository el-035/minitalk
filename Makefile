CC = cc

CLIENT_CFILES = client.c c_utils.c ft_libft.c err_free.c
SERVER_CFILES = server.c s_utils.c ft_libft.c err_free.c

BONUS_CC = client_bonus.c c_utils_bonus.c ft_libft_bonus.c err_free_bonus.c
BONUS_SC = server_bonus.c s_utils_bonus.c ft_libft_bonus.c err_free_bonus.c
#LIBFT_DIR = libft
#LIBFT = $(LIBFT_DIR)/libft.a
#LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_MAKEFILE = $(FT_PRINTF_DIR)/Makefile

#creates object files from the c files given
CLIENT_OFILES = $(CLIENT_CFILES:.c=.o)
SERVER_OFILES = $(SERVER_CFILES:.c=.o)

BONUS_CO = $(BONUS_CC:.c=.o)
BONUS_SO = $(BONUS_SC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

# all compiles all the c files into o files and archive them into libft.a
all: server client

client: $(CLIENT_OFILES) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OFILES) $(FT_PRINTF) -o client

server: $(SERVER_OFILES) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OFILES) $(FT_PRINTF) -o server

# this sets the rule to compile all c files into o files $< is the prerequisite (aka the c files) and $@ is the target (aka the o files)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@  

#$(LIBFT):
#	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

#gets rid of all o files after creating application
clean:
	rm -f $(CLIENT_OFILES) $(SERVER_OFILES)
	$(MAKE) -C $(FT_PRINTF_DIR) clean
#	$(MAKE) -C $(LIBFT_DIR) clean

#removes o files and library
fclean: clean
	rm -f client server
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
#	$(MAKE) -C $(LIBFT_DIR) fclean

#to rebuild the whole project after cleaning everything
re: fclean all

#tells make that all, clean, re, and fclean should always be treated as commands and not as files to be created.
.PHONY: all clean re fclean