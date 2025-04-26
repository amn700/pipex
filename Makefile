MANDATORY_DIR = mandatory
BONUS_DIR = bonus
MANDATORY_EXEC = $(MANDATORY_DIR)/pipex
BONUS_EXEC = $(BONUS_DIR)/pipex_bonus

all: $(MANDATORY_EXEC)

$(MANDATORY_EXEC):
	$(MAKE) -C $(MANDATORY_DIR)

bonus: $(BONUS_EXEC)

$(BONUS_EXEC):
	$(MAKE) -C $(BONUS_DIR)

clean:
	$(MAKE) -C $(MANDATORY_DIR) clean
	$(MAKE) -C $(BONUS_DIR) clean

fclean:
	$(MAKE) -C $(MANDATORY_DIR) fclean
	$(MAKE) -C $(BONUS_DIR) fclean

re: fclean all

.PHONY: all clean fclean re