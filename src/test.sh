#! /bin/bash

testdir="graphics/"
logfile="build/graphics.log"

cd $testdir
echo " " > $logfile

cmake . -B build >> $logfile

if [ $? -eq 0 ]
then
	cmake --build build >> $logfile
fi

if [ $? -eq 0 ]
then
	./build/tests
fi

cd - >> /dev/null

