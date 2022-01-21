#!/bin/bash
make ticket_impl
for i in {1..1000}; do ./ticket_impl; done | sort -n | uniq -c
