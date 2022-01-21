#!/bin/bash
clang spinlock_first_impl.c -o spinlock_first_impl
for i in {1..1000}; do ./spinlock_first_impl; done | sort -n | uniq -c
