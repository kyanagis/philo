
NAME_M := philosophers
NAME_B := philosophers_bonus

INCDIR    := include
MANDIR    := src
BONUSDIR  := philo_bonus
OBJDIR_M  := obj/mandatory
OBJDIR_B  := obj/bonus

INCS := -I$(INCDIR)

SRCS_M := \
	$(MANDIR)/main.c \
	$(MANDIR)/config.c \
	$(MANDIR)/error.c \
	$(MANDIR)/time.c \
	$(MANDIR)/init/forks_init.c \
	$(MANDIR)/init/philos_init.c \
	$(MANDIR)/init/shared_init.c\
	# $(MANDIR)/init.c \
	# $(MANDIR)/utils.c \
	# $(MANDIR)/libft_utils.c \
	# $(MANDIR)/philos_init.c \
	# $(MANDIR)/run.c \


SRCS_B := \

OBJS_M := $(SRCS_M:%.c=$(OBJDIR_M)/%.o)
OBJS_B := $(SRCS_B:%.c=$(OBJDIR_B)/%.o)

CC     := cc
CFLAGS := -Wall -Wextra -Werror -pthread -g3 $(INCS)
ifdef DEBUG
CFLAGS += -g3 -O0
endif

all: $(NAME_M)

$(NAME_M): $(OBJS_M)
	$(CC) $(CFLAGS) $(OBJS_M) -o $@

$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $@

$(OBJDIR_M)/%.o: %.c $(INCDIR)/philo.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_B)/%.o: %.c $(INCDIR)/philo.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_B)

clean:
	$(RM) -rf $(OBJDIR_M) $(OBJDIR_B)

fclean: clean
	@if [ -f "$(NAME_M)" ]; then $(RM) "$(NAME_M)"; fi
	@if [ -f "$(NAME_B)" ]; then $(RM) "$(NAME_B)"; fi

re:
	$(MAKE) fclean
	$(MAKE) all


.PHONY: all bonus clean fclean re 
