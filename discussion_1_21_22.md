# Notes on GDB
- how to run: r 2 4 16 1024
- Note: try to have easiest test case for running GDB
- Question: How to find thread with deadlock?

## I have a deadlock help!
1. run `gdb harness`
2. it deadlocks!
3. send ctrl-c signal to gdb
4. `info threads` gives thread information, lists all threads
5. `backtrace`
6. `win` opens up a window with code. this shows where my instruction pointer is. (NOTE! needs debug flags on, and needs to be able to find source files. This will work for pclab, ymmv in other projects)

# What to do for Task 4
- What are ways in which our lock is _not_ performant?
	1Q. Threads just wait in a while loop, wasting time.
	1A. What if we yield in our wait loop?  Can set it to spin for a certain number of cycles?
	2Q: Are there other synchronization primitives that we can use? What about pthread_mutex(...)?
	3Q: What are the appropriate metrics to measure? Throughput? Missed pulls/push
 

# How do interrupts come into play? 

Imagine I have Thread 1, and Thread 2, locking on _lock_. 

- Thread 1-> holds _lock_
- Thread 2-> interrupts thread 1 (so now it has control over execution, won't give up control)
- It runs a spinlock to acquire _lock_, except that Thread 1 holds _lock_. Now there is deadlock. 

## Why is this interrupt happening in the first place?
- Imagine I have a multiple thermometers that logs to a shared data structure and an application which 
reads temperature readings and does some analytics on it. 
- The thermometer only writes when the temperature falls below 5 degrees. 
- In this case, a reasonable implementation will try to acquire a lock on the shared 
data structure, through an interrupt. 
