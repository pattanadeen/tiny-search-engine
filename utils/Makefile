CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:   			test_success dev_qapply test_failed dev_hash test_hash

%.o:			%.c %.h
				gcc $(CLAGS) -c $<

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
				rm -f *.o test_success dev_qapply test_failed dev_hash test_hash