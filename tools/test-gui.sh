#! /bin/bash

project="$(cd -- "$(dirname "$0")/.." > /dev/null 2>&1 ; pwd -P)"
results="${project}/bin/test/gui/"
logfile="${project}/bin/test/gui.log"

if [ $(basename ${project}) != "synthesizer" ]
then
	echo $(basename ${project})
	echo "${project} != project directory. Update ${sources}/$(basename $0)"
	exit 1
fi

mkdir -p ${results}
{
	cmake ${project}/src/gui -B ${results}
	cmake --build ${results}
} > $logfile

