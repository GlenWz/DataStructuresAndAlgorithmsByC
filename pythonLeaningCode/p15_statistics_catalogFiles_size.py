import os


# 统计当前目录下的所有文件的大小

# print(os.path.getsize("./tmp/paper.txt"))
ret = 0
for file in os.listdir("."):
    if os.path.isfile(file):
        print(file)
        ret+=os.path.getsize(file)

print(ret)