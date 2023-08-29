
# ./tmp/score.txt
def read_TXT(url:str)->list:
    ret=[]
    with open(url,encoding="UTF-8") as filesTxt:
        for line in filesTxt:
            line=line[:-1]
            ret.append(line.split(","))

    return ret
def sort_score(txtlist:list)->list:
    return sorted(txtlist,key=lambda x:x[2],reverse=True)

def write_fileTxt(sortList:list)->bool:
    ret =False
    try:
        with open("./tmp/sorted_list.txt","w") as fileTxt:
            for data in sortList:
                fileTxt.write(','.join(data)+"\n")
        ret=True
    except:
        print("写入失败")
        return ret

    return ret

# 读取文件
retList=read_TXT("./tmp/score.txt")
print(retList)

# 排序数据
retSortData=sort_score(retList)
print(retSortData)
# 写入文件

print(write_fileTxt(retSortData))

