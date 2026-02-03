cd $(dirname $0)

BUILD_DIR=build

if [ -d $BUILD_DIR ]; then
    rm -rf $BUILD_DIR
fi

cmake -S src -B $BUILD_DIR -DCMAKE_BUILD_TYPE=Release
cmake --build $BUILD_DIR
ctest --test-dir $BUILD_DIR -j 3