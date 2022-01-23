CFLAGS := ${CFLAGS}
CFLAGS += -Wall -Wextra -Werror

CC     ?= gcc

MAKEFLAGS += --no-print-directory

NAME = minitrace

INC_FLAGS := -Ilib
LIB := lib/libgeotrace.a

LIBS := -Llib -lgeotrace -lm

SRCS = main.c
OBJS = ${SRCS:%=%.o}

%.c.o: %.c
	@echo Compiling $@
	@$(CC) -c  $(CFLAGS) $(INC_FLAGS) $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME):	$(LIB) $(OBJS)
	@echo Linking $@
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIB):
	@$(MAKE) -C lib
	@echo $@ done

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C lib clean
	@echo Clean done

fclean:
	@rm -rf $(OBJS)
	@rm -f $(NAME)
	@$(MAKE) -C lib fclean
	@echo Fclean done