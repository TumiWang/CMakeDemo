# 文件 rebuild.sh

# 进入当今脚本所在目录
cd $(dirname "$0")

#  当前目录全路径
ROOT_DIR=`pwd`

# 设置两个变量 分别表示编译目录和编译类型
BUILD_DIR=build
BUILD_TYPE=Release

# 清除 编译目录
# 如果之前编译过，这样就是重新编译
if [ -d "$BUILD_DIR" ]; then
    rm -rf "$BUILD_DIR"
fi

# 在这里使用工具链(文件) -- 注意：通常要使用全路径
cmake -B "$BUILD_DIR" -S src  -DCMAKE_TOOLCHAIN_FILE=$ROOT_DIR/cmake/mytool.cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE
if [ $? != 0 ]; then
    echo "cmake创建项目失败"
    exit 0
fi

cmake --build "$BUILD_DIR" --config $BUILD_TYPE
if [ $? != 0 ]; then
    echo "cmake编译失败"
    exit 0
fi
