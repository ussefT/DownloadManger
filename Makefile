CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC=src/main.c src/file.c
OUT = download-manager


ifeq (($OS),Windows_NT)
OUT:=download-manager.exe
endif

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f download-manager download-manager.exe
