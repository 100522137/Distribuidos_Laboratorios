BIN_FILES  = test_con cliente_con server_con

CC = gcc


CFLAGS =	-Wall  -g

LDFLAGS = -L$(INSTALL_PATH)/lib/
LDLIBS = -lpthread


all: $(BIN_FILES)
.PHONY : all

test_con: test_con.o lines.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

cliente_con: cliente_con.o lines.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

server_con: server_con.o lines.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@ 

%.o: %.c
	$(CC) $(CFLAGS) $(CFLAGS) -c $<

clean:
	rm -f $(BIN_FILES) *.o

.SUFFIXES:
.PHONY : clean
