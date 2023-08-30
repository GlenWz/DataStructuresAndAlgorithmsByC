
# 获取当前文件夹中文件的后缀名

import os,shutil

# 输出当前文件夹中的文件和文件后缀名
for file in os.listdir("."):
    if os.path.isfile(file):
        print(file)
        print(os.path.splitext(file)[1])


# 移动文件
# 将aaa.txt 移动道tmp
shutil.move("aaa.txt","./tmp")
