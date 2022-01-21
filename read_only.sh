#!/bin/bash
clang read_only.c -o read_only
for i in {1..1000}; do ./read_only; done | sort -n | uniq -c
