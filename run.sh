#!/bin/bash

error() {
	echo 'Error occured'
	exit 1
}

build() {
	if [[ ! -d './build' ]]; then
		echo 'Creating build folder...'
		if mkdir 'build'; then
			echo 'Created build folder.'
		fi
	fi

	echo 'Trying to generate Makefile...'
	cd 'build'
	if cmake '../'; then
		echo 'Generated Makefile.'
	else
                echo 'In case of problems with cmake`s version, \
                please refer to the first line of CMakeLists.txt'
                error
	fi

	echo 'Running build...'
	if make; then
		echo 'Build successful.'
	else
		error
	fi
}

run() {
	if [[ ! -d './bin' ]]; then
		error
	else
		cd './bin'
		echo 'Running programm...'
		echo '==================='
		./plugin_system
	fi
}

if test $# -gt 0; then
	case "$1" in
		-h|--help)
			echo " "
			echo "options:"
			echo "-h, --help                show brief help"
			echo "-r, --run                 run programm after build is finished"
			exit 0
			;;
		-r|--run)
			build
			run
			;;
		*)
			break
			;;
	esac
else
	build
fi
