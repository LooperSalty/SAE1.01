CFILES = main.c mystere.c cache.c mastermind.c commun.c
CFLAGS = -Wall -Wextra -g
BINFILE = sae

$(BINFILE): $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o $(BINFILE)

.PHONY: static
static: $(CFILES)
	$(CC) -static $(CFLAGS) $(CFILES) -o $(BINFILE)

.PHONY: clean run
clean:
	rm $(BINFILE)

run: $(BINFILE)
	./$(BINFILE)
