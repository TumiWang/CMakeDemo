# 
import os

def update_link(src):
    target = os.readlink(src)
    if target.startswith('/'):
        src_items = src.splite('/')
        target_items = src.splite('/')
        while len(src_items) > 0 and len(target_items) > 0:
            if src_items[0] == target_items[0]:
                del src_items[0]
                del target_items[0]
            else:
                break
        if len(src_items) == 0:
            return
        if len(target_items) == 0:
            return
        result = ''
        for _ in range(len(src_items) - 1):
            result += '../'
        result += '/'.join(target_items)
        os.symlink(src, result, target_is_directory=os.path.isdir(target))

def check_dir(path):
    for root, dirs, files in os.walk(path, followlinks=True):
        for file in files:
            fullname = os.path.join(root, file)
            if os.path.islink(fullname):
                update_link(fullname)
        for dir in dirs:
            fullname = os.path.join(root, dir)
            if os.path.islink(fullname):
                update_link(fullname)
            else:
                check_dir(fullname)

if __name__ == '__main__':
    current_file_path = os.path.dirname(os.path.abspath(__file__))
    sdk_path = os.path.join(current_file_path, 'sdk')
    if os.path.exists(sdk_path):
        check_dir(sdk_path)
