CFLAGS=-Wall -pedantic -std=c11 -I. -g
OFILES=queue.o hash.o webpage.o
TESTFILES=test_success  test_failed  test_hash
DEVFILES=dev_qapply dev_hash

all:   			$(OFILES)
				ar cr ../lib/libutils.a $(OFILES)

%.o:			%.c %.h
				gcc $(CFLAGS) -c $<

dev_qapply: 	queue.o car.o dev_qapply.o
				gcc $(CFLAGS) queue.o car.o dev_qapply.o -o $@

dev_hash:		queue.o car.o hash.o dev_hash.o
				gcc $(CFLAGS) queue.o car.o hash.o dev_hash.o -o $@

test_hash:		queue.o car.o hash.o test_hash.o
				gcc $(CFLAGS) queue.o car.o hash.o test_hash.o -o $@

test_success:   queue.o car.o test_success.o
				gcc $(CFLAGS) queue.o car.o test_success.o -o $@

test_failed:   	queue.o car.o test_failed.o
				gcc $(CFLAGS) queue.o car.o test_failed.o -o $@

clean:
				rm -f *.o $(DEVFILES) $(TESTFILES)