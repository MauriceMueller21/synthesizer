#!/bin/bash

if [ "$1" == "core" ]
then
	source_file_pattern="core"
	macro="CORETEST"
elif [ "$1" == "sound" ]
then
	source_file_pattern="core|sound"
	macro="SOUNDTEST"
elif [ "$1" == "tui" ]
then
	source_file_pattern="core|sound|tui"
	macro="TUITEST"
else
	if [ "$1" == "" ]
	then
		echo "Parameter is missing."
	fi
	echo "Parameter must be 'core', 'sound' or 'tui'."
	exit 1
fi

source_file_pattern="src/(${source_file_pattern})/"

input_path="src/$1/test/"
output_path="bin/test/$1/"

program="${output_path}test-$1"
log_file="${output_path}output.log"

libraries="-lX11"
flags="-Wall -Wextra -Werror"
source_files="$(find src/ -name '*.c' | grep -E ${source_file_pattern})"

mkdir -p ${output_path}

gcc -D $macro $flags $libraries ${source_files} -o $program

echo -en "" > "${log_file}"
$program >> "${log_file}"
