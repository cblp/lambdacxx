#!/bin/bash
set -eux -o pipefail

mkdir -p build
cd build
cmake ..
sos ..                                                                  \
    --pattern='../CMakeLists.txt' --pattern='\.cpp$' --pattern='\.hpp$' \
    --command='make' --command='./lambdacxx'
