# 这个需要在MacOS上运行

# 进入项目的根目录
cd $(dirname "$0")
cd ..

# 当前目录全路径
ROOT_DIR=`pwd`

ibtool --auto-activate-custom-fonts  \
    --minimum-deployment-target 11.0 \
    --output-format human-readable-text\
    --compile $ROOT_DIR/precompile/MainMenu.nib $ROOT_DIR/src/MainMenu.xib
