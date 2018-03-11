# https://www.gnu.org/software/make/manual/make.html
CFLAGS      := -Wall
SRCS        := $(wildcard *.c)
PROG_SUFFIX := .out
PROGS       := $(patsubst %.c, %, $(SRCS))

all: clean build

clean:
		rm -f $(addsuffix $(PROG_SUFFIX), $(PROGS))

build: $(PROGS)
    
$(PROGS): %: %.c
		$(CC) $(CFLAGS) -o $@$(PROG_SUFFIX) $<
