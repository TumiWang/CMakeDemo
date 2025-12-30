# 文件 rebuild.sh

# 进入当今脚本所在目录
cd $(dirname "$0")

# 当前目录全路径
ROOT_DIR=`pwd`

PRODUCT_DIR=product/linux-aarch64
BUILD_DIR=build
BUILD_TYPE=Release

# 工具链文件使用绝对路径
# 如果使用相对路径，相对的目录是 $BUILD_DIR
TOOLCHAIN_FILE=$ROOT_DIR/toolchain/ubuntu20_04-aarch64.cmake

if [ -d "$BUILD_DIR" ]; then
    rm -rf "$BUILD_DIR"
fi

cmake -B "$BUILD_DIR" -S src --toolchain $TOOLCHAIN_FILE -DCMAKE_BUILD_TYPE=$BUILD_TYPE
if [ $? != 0 ]; then
    echo "cmake创建项目失败"
    exit 0
fi

cmake --build "$BUILD_DIR"
if [ $? != 0 ]; then
    echo "cmake编译失败"
    exit 0
fi

cmake --install "$BUILD_DIR" --prefix "$ROOT_DIR/$PRODUCT_DIR"
if [ $? != 0 ]; then
    echo "cmake安装失败"
    exit 0
fi