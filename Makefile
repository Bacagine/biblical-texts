# Makefile for biblical-texts
# 
# Description: Makefile of the biblical-texts project
#
# Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
# 
# Date: 16/10/2023

TARGET       = biblical-texts

# Directories
SRCDIR       = src
INCDIR       = include
INCLOGDIR    = include/trace
INCCUTILS    = include/cutils
OBJDIR       = obj
LIBDIR       = lib
BINDIR       = bin

# Binary
BIN        = $(BINDIR)/$(TARGET)

# .c files
SRC        = $(wildcard $(SRCDIR)/*.c)

# .o files
OBJ        = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

# .so or .a files
#LIB        = $(LIBDIR)

# Compilation flags
LDFLAGS      = -L $(LIBDIR)
LDLIBS       = -lm -pthread -ltrace -lcutils
CFLAGS       = -I $(INCDIR) -I $(INCLOGDIR) -I $(INCCUTILS) -Wall -Wextra 
DEBUGFLAGS   = -g -O0 -DDEBUG_COMPILATION

# Compiler
CC         = gcc

ifdef DEBUG_COMPILATION
	CFLAGS += $(DEBUGFLAGS) 
	LDFLAGS += $(DEBUGFLAGS)
else
	CFLAGS += -O3
endif

all: distclean $(OBJDIR) $(BINDIR) $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS) $(LDLIBS) $(LDFLAGS)

$(BINDIR):
	mkdir $@
$(OBJDIR):
	mkdir $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS) $(LDLIBS) $(LDFLAGS)

clean:
	rm -rvf $(OBJDIR)

strip: all

install: all strip
	./install.sh

uninstall:
	./uninstall.sh

distclean: clean
	rm -rvf *.log
	rm -rvf $(BINDIR)
	
.PHONY: all clean install uninstall distclean

