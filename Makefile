export BINDIR = bin
export SRCDIR = src
export LIBDIR = lib
export INCDIR = include

APP_NAME = valgrind_test

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I $(INCDIR)

ifeq ($(DEBUG),1)
CFLAGS += -g
endif

C_SRC = $(wildcard $(SRCDIR)/*.c)
OBJ=$(patsubst %,$(BINDIR)/$(SRCDIR)/%, $(notdir $(C_SRC:.c=.o)))

.PHONY: clean
.PHONY: help

all: dir $(APP_NAME)

dir:
	@mkdir -p $(BINDIR)
	@mkdir -p $(BINDIR)/$(SRCDIR)
	@mkdir -p $(BINDIR)/static
	@mkdir -p $(BINDIR)/shared

$(APP_NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BINDIR)/$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(BINDIR)
	rm $(APP_NAME)

help:
	@echo "src: $(C_SRC)"
	@echo "bin: $(OBJ)"
