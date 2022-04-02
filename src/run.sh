#! /bin/bash

filenames="$(find -name "*.cpp" -not -path "./graphics/tests/*" -not -path "./graphics/build/*")"
libraries="-lX11 -lasound"
flags="-Wall -Wextra -Werror"
g++ $flags $libraries $filenames -o synthesizer

if [ $? -eq 0 ]
then
	./synthesizer $@
fi

