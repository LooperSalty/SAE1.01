CFILES = main.c mystere.c cache.c mastermind.c
CFLAGS = -Wall -Wextra -g
BINFILE = sae

$(BINFILE): $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o $(BINFILE)

.PHONY: clean run
clean:
	rm $(BINFILE)

run: $(BINFILE)
	./$(BINFILE)
