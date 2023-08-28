
# 移除给定元素

lista=[1,3,5,7,9,11]
relist=[7,11]

def remove_item_in_list(lista:list,listb:list)->list:
    for item in listb:
        lista.remove(item)
    return lista

datalist=[item for item in lista if item not in relist]
print(remove_item_in_list(lista,relist))
print(datalist)
