# 文件 rebuild.sh

# 进入当今脚本所在目录
cd $(dirname "$0")

# 当前目录全路径
ROOT_DIR=`pwd`

# 设置三个变量 分别表示安装目录、编译目录和编译类型
PRODUCT_DIR=product
BUILD_DIR=build
BUILD_TYPE=Release

# 清除 
if [ -d "$BUILD_DIR" ]; then
    rm -rf "$BUILD_DIR"
fi
if [ -d "$PRODUCT_DIR" ]; then
    rm -rf "$PRODUCT_DIR"
fi

cmake -B "$BUILD_DIR" -S src -DCMAKE_BUILD_TYPE=$BUILD_TYPE

cmake --build "$BUILD_DIR"

# cmake --install "$BUILD_DIR" --config $BUILD_TYPE --prefix "$ROOT_DIR/$PRODUCT_DIR"

# cd "$BUILD_DIR"

# # 打包为 .tar.gz
# # POSIX
# cpack -G TGZ

# # 打包为 .tar.xz
# # POSIX
# cpack -G TXZ

# # 打包为 .deb
# # Linux
# cpack -G DEB

# # 打包为 .rpm
# # ubuntu 需要先运行安装工具 apt-get -y install rpm
# # Linux
# cpack -G RPM

# # 打包为 .dmg 拖拽
# # MacOS
# # 拖拽安装应该是应用程序(有界面的), 所以，我们这个例子不合适
# cpack DragNDrop

# # 打包为 pkg
# # MacOS
# cpack -G productbuild

# 打包为 .dmg
# MacOS
# cpack -G Bundle