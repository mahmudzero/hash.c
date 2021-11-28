CC        = clang
CFLAGS    =
DBGCFLAGS = -g
FILES     = hash.c
OUTPUT    = -o a.out

all:
	$(CC) $(FILES) $(CFLAGS) $(OUTPUT)

debug:
	$(CC) $(FILES) $(DBGCFLAGS) $(OUTPUT)
clean:
	rm -rf a.out a.out.dSYM;
