#! /bin/bash

filenames="$(find -name "*.cpp")"
libraries="-lX11 -lasound"
flags="-Wall -Wextra -Werror"

g++ $flags $libraries $filenames -o synthesizer

if [ $? -eq 0 ]
then
	./synthesizer $@
fi

