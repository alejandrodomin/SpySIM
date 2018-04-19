#!/bin/bash

make
valgrind -v --leak-check=full ./SpySIM
