### VARIABLES ###

CC = gcc
CFLAGS = -lgraph
SRCDIR = ./src
HDIR = ./include
ODIR = ./out
OFILES = $(subst src/,out/,$(subst .c,.o,$(shell find $(SRCDIR)/ -type f)))
EXE = game

### BUT PAR DEFAUT ###

but : $(EXE)

### REGLES ESSENTIELLES ###

$(ODIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

$(EXE) : $(OFILES)
	$(CC) $(CFLAGS) -o $(EXE) $(OFILES)

### REGLES OPTIONNELLES ###

start : $(EXE)
	./$(EXE)

clean :
	-rm -rf $(ODIR)

### BUTS FACTICES ###

.PHONY : but start clean
