build() {
    mkdir -p build
    cd build
    cmake ..
    make
}

rebuild() {
    if [ -d "build" ]; then
        rm -rf build
    fi

    build
}

run() {
    build
    cd ..
    ./run.sh
}

usage() {
    echo "build.sh <options>"
    echo "  - build: make the lraspi executable"
    echo "  - rebuild: clear build folder and make the executable"
    echo "  - run: make the executable and run it"
    echo "  - help: print usage"
}

if [ -z $1 ] || [ $1 = "build" ]; then
    build
elif [ $1 = "rebuild" ]; then
    rebuild
elif [ $1 = "run" ]; then
    run
elif [ $1 = "help" ]; then
    usage
else
    echo "command $1 not found"
    usage
fi
