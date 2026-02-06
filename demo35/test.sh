cd $(dirname $0)

if [ -d build ]; then
    rm -rf build
fi

if [ -d product ]; then
    rm -rf product
fi

cd fibonacci

# cmake --workflow --list-presets

# Linux
# cmake --workflow --preset linux
cmake --workflow --preset TestWithLinuxNinja

# MacOS
# cmake --workflow --preset xcode
