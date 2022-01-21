#!/bin/bash
clang spinlock_second_impl.c -o spinlock_second_impl
for i in {1..1000}; do ./spinlock_second_impl; done | sort -n | uniq -c
