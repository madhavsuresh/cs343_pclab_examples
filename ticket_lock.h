// ticket_lock.h
// https://gist.github.com/matteobertozzi/1490264

union ticket_lock {
    volatile unsigned int data;
    struct {
        volatile unsigned short next_ticket;
        volatile unsigned short now_serving;
    } s;
};

void ticket_init (union ticket_lock *lock) {
    lock->s.now_serving = 0;
    lock->s.next_ticket = 0;
}

void ticket_destroy (union ticket_lock *lock) {
    lock->s.now_serving = 0;
    lock->s.next_ticket = 0;
}

int ticket_acquire (union ticket_lock *lock) {
    unsigned int my_ticket;

    my_ticket = __sync_fetch_and_add(&(lock->s.next_ticket), 1);
    while (lock->s.now_serving != my_ticket);
}

void ticket_release (union ticket_lock *lock) {
    lock->s.now_serving += 1;
}
