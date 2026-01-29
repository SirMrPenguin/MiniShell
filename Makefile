LIBFT_URL = https://github.com/SirMrPenguin/libft_updated.git
LIBS_PATH = libs
LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT_ARCH = $(LIBFT_PATH)/libft.a
BUILD_DIR = .build

NAME = minishell

FILES =

SRC_PATH = src
SRC = $(addprefix $(SRC_PATH)/, $(FILES))
OBJS = $(SRC:$(SRC_PATH)/%.c=$(BUILD_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) $< -o $@


$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -fr $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
