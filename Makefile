CC = gcc
CFLAGS = -Wall -I./src
OBJDIR = build

MODULES = shell history proc fs mm utils
OBJS = $(addprefix $(OBJDIR)/, main.o \
        shell/shell.o shell/history.o \
        proc/proc.o fs/fs.o mm/mm.o utils/utils.o)

all: MiniOS

MiniOS: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) MiniOS

.PHONY: all clean