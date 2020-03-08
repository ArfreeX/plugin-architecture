#!/bin/bash

ROOT_PROJECT_DIR='pluginArchitecture'
ROOT_PROJECT_PATH=''

error() {
        echo 'Error occured'
        exit 1
}

get_project_path() {
        FULL_DIR_SCRIPT_PATH=$(dirname $(realpath $0))

        if [[ $FULL_DIR_SCRIPT_PATH != *$ROOT_PROJECT_DIR* ]]; then
                echo "Could not find project folder. Check ROOT_PROJECT_DIR."
                error
        fi

        ROOT_PROJECT_PATH=$(sed "s/$ROOT_PROJECT_DIR.*/$ROOT_PROJECT_DIR/"<<<$FULL_DIR_SCRIPT_PATH)
}

build() {
        if [[ ! -d "$ROOT_PROJECT_PATH/build" ]]; then
		echo 'Creating build folder...'
		if mkdir 'build'; then
			echo 'Created build folder.'
		fi
	fi

	echo 'Trying to generate Makefile...'
        cd "$ROOT_PROJECT_PATH/build"
        if cmake $ROOT_PROJECT_PATH; then
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
        if [[ ! -d "$ROOT_PROJECT_PATH/build/bin" ]]; then
		error
	else
		echo 'Running programm...'
		echo '==================='
                $ROOT_PROJECT_PATH/build/bin/plugin_system
	fi
}

if test $# -gt 0; then
	case "$1" in
		-h|--help)
			echo " "
			echo "options:"
			echo "-h, --help                show brief help"
                        echo "-r, --run                 run binary after build"
			exit 0
			;;
		-r|--run)
                        get_project_path
                        build
                        run
			;;
		*)
			break
			;;
	esac
else
        get_project_path
	build
fi
