#!/bin/bash
clang read_write.c -o read_write
for i in {1..1000}; do ./read_write; done | sort -n | uniq -c
