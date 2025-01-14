#!/bin/bash

g++ -g -fsanitize=address $@ -o exec
./exec
