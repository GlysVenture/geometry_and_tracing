CFLAGS := ${CFLAGS}
CFLAGS += -Wall -Wextra -Werror

CC     ?= gcc

MAKEFLAGS += --no-print-directory

NAME = minitrace

INC_FLAGS := -Ilib
LIB := lib/libgeotrace.a

LIBS := -Llib -lgeotrace -lm

TEST_DIRS ?= tests

TEST_SRC = $(wildcard $(TEST_DIRS)/*.c)
TEST_BINS = $(patsubst $(TEST_DIRS)/%.c, $(TEST_DIRS)/bin/%, $(TEST_SRC))
TEST_INC = -I/Users/tkondrac/.brew/Cellar/criterion/2.3.3-bleeding4/include

SRCS = main.c
OBJS = ${SRCS:%=%.o}

%.c.o: %.c
	@echo Compiling $@
	@$(CC) -c  $(CFLAGS) $(INC_FLAGS) $< -o $@

all:	library
	@$(MAKE) $(NAME)

$(NAME):	$(LIB) $(OBJS)
	@echo Linking $@
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LIBS) -o $(NAME)

library:
	@$(MAKE) -C lib

$(LIB):
	@$(MAKE) -C lib

$(TEST_DIRS)/bin/%:	$(TEST_DIRS)/%.c
	$(CC) $(CFLAGS) $< $(INC_FLAGS) $(TEST_INC) $(LIBS) -o $@ -L/Users/tkondrac/.brew/Cellar/criterion/2.3.3-bleeding4/lib -lcriterion

$(TEST_DIRS)/bin:
	mkdir $@

test: $(LIB) $(TEST_DIRS)/bin $(TEST_BINS)
	@for test in $(TEST_BINS) ; do echo Testing: $$test ; ./$$test ; done

clean:
	@rm -rf $(OBJS)
	@rm -rf $(TEST_DIRS)/bin
	@$(MAKE) -C lib clean
	@echo Clean done

fclean:
	@rm -rf $(OBJS)
	@rm -f $(NAME)
	@$(MAKE) -C lib fclean
	@echo Fclean done

re:		fclean all

.PHONY:	all clean fclean re test