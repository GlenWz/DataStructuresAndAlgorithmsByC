
# list去重
lista=[1,3,5,7,9,1,5,9]
def get_undeduplicate(lisata:list)->list:
    ret=[]
    for item in lista:
        if item not in ret:
            ret.append(item)

    return ret
print(get_undeduplicate(lista));

# 2、利用set的特性，也就是不会存在重复元素的集合
print(list(set(lista)))