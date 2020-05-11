#!/bin/bash

# Use paths relative to this script's location
SCRIPT=$(readlink -f "$0")
BASEDIR=$(dirname "$SCRIPT")

# If you want to build into a different directory, change this variable
BUILDDIR="$BASEDIR/build"

# Create our build folder if required and clear it
mkdir -p $BUILDDIR
rm -rf $BUILDDIR/*

# Generate the build system using Ninja
cmake -B"$BUILDDIR" -GNinja -DCMAKE_TOOLCHAIN_FILE=$BASEDIR/cmake/arm-gcc-toolchain.cmake $BASEDIR
# Generate the build system using the system default
# cmake -B"$BUILDDIR" -DCMAKE_TOOLCHAIN_FILE=$BASEDIR/cmake/arm-gcc-toolchain.cmake $BASEDIR

# And then do the build
cmake --build $BUILDDIR
