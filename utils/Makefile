CFLAGS=-Wall -pedantic -std=c11 -I. -g
OFILES=queue.o hash.o webpage.o
TESTFILES=test_success  test_failed  test_hash
DEVFILES=dev_qapply dev_hash

all:   			$(OFILES)
				ar cr ../lib/libutils.a $(OFILES)

%.o:			%.c %.h
				gcc $(CFLAGS) -c $<

clean:
				rm -f $(OFILES)