#!/bin/bash

checkmk clean_mode=1 test.check > test.c
make clean
make test