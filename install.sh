#!/bin/bash

echo "> Building differentiator on your computer"

cmake . -B build

make -C build

chmod +x ./run.sh

sudo cp ./run.sh /usr/bin/differentiator