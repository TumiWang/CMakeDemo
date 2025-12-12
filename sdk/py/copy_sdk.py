# 拷贝 SDK 到当前目录

import os
import shutil

all_items = ['/lib', 'lib64', '/usr/include', '/usr/lib', '/usr/lib64', '/usr/share']

if __name__ == '__main__':
    current_file_path = os.path.dirname(os.path.abspath(__file__))
    sdk_path = os.path.join(current_file_path, 'sdk')
    if os.path.exists(sdk_path):
        shutil.rmtree(sdk_path)
    os.mkdir(sdk_path)
    for item in all_items:
        if (os.path.exists(item)):
            shutil.copytree(item, sdk_path + item, symlinks=True)
