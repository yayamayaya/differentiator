#!/bin/bash

valgrind -s --leak-check=full --show-leak-kinds=all build/main_src/differentiator $1