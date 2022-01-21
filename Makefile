ticket_impl: ticket_impl.c ticket_lock.h
	clang ticket_impl.c -o ticket_impl
clean:
	rm *.o ticket
