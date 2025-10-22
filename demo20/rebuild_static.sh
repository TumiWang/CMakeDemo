# 文件 rebuild_static.sh

# 进入当今脚本所在目录
cd $(dirname "$0")

# 设置两个变量 分别表示编译目录和编译类型
BUILD_DIR=build
BUILD_TYPE=Release

if [ -d "$BUILD_DIR" ]; then
    rm -rf "$BUILD_DIR"
fi

# 和之前的 rebuild.sh 脚本相比 差别就是下面这句 多了 -DBUILD_SHARED_LIBS=OFF
cmake -B "$BUILD_DIR" -S src -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DBUILD_SHARED_LIBS=OFF
if [ $? != 0 ]; then
    echo "cmake创建项目失败"
    exit 0
fi

cmake --build "$BUILD_DIR" --config $BUILD_TYPE
if [ $? != 0 ]; then
    echo "cmake编译失败"
    exit 0
fi