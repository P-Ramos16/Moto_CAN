CC = gcc
CFLAGS = -Wall -g -O0

files = main receiver sender

$(files):	%:	%.o


makeall: $(files)

$(progs):	%:
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *~ *.o

cleanall:	clean
	rm -f $(files)