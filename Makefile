CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -Werror -pedantic
CXFXLAGS = -Wall -Wextra -Werror -pedantic

SERVER_FILES = server.c ndr_net.c
CLIENT_FILES = client.c ndr_net.c

.PHONY: all
all: server client

server:
	$(CC) $(CFLAGS) -o server $(SERVER_FILES)

client:
	$(CC) $(CFLAGS) -o client $(CLIENT_FILES)
