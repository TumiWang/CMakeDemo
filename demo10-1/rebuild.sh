# 文件 rebuild.sh

# 进入当今脚本所在目录
cd $(dirname "$0")

# 当前目录全路径
ROOT_DIR=`pwd`

# 设置三个变量 分别表示安装目录、编译目录和编译类型
PRODUCT_DIR=product
BUILD_DIR=build
BUILD_TYPE=Release

# 清除 编译目录
# 如果之前编译过，这样就是重新编译
if [ -d "$BUILD_DIR" ]; then
    rm -rf "$BUILD_DIR"
fi
# 清理安装目录
if [ -d "$PRODUCT_DIR" ]; then
    rm -rf "$PRODUCT_DIR"
fi

cmake -B "$BUILD_DIR" -S . -DCMAKE_BUILD_TYPE=$BUILD_TYPE
if [ $? != 0 ]; then
    echo "cmake创建项目失败"
    exit 0
fi

cmake --build "$BUILD_DIR" --config $BUILD_TYPE
if [ $? != 0 ]; then
    echo "cmake编译失败"
    exit 0
fi

# 和cmake --build一样
# 如果是makefile或ninja等项目
# 实际上不需要 --config $BUILD_TYPE 这个参数
# 添加这个参数后，反而可能有警告 -- 因为这个参数没用
# --prefix 这个参数是指定安装目录 -- 注意这里通常使用全路径
cmake --install "$BUILD_DIR" --config $BUILD_TYPE --prefix "$ROOT_DIR/$PRODUCT_DIR"
if [ $? != 0 ]; then
    echo "cmake安装失败"
    exit 0
fi
