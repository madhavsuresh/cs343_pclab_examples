# PCLab Examples
## Operating Systems, CS343, Winter 2022, Northwestern University

- This code base includes examples of a spinlock and ticketlock used in discussion section for CS343. 
- Example taken from https://www.classes.cs.uchicago.edu/archive/2014/spring/12300-1/labs/lab4/


## Files
1. read_only.c
   - demonstrates read only, multithreaded workload
2. read_write.c
   - demonstrates read/write workload with multiple threads. No synchronization
3. spinlock_first_impl.c
  - attempt to implement spinlock. It should fail. Lock is accessed without atomics
4. spinlock_second_impl.c
  - correct implementation of spinlock. Utilizes atomic instructions to acquire lock. 

## How to run
- Each file has a \*.sh file which will compile, and run the code 1000 times. This allows us to catch failures and non-deterministic behavior. 
