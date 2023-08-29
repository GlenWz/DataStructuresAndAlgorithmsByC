
# list排序

lista=[9,5,6,7,1,2,3,4,6,9,8,2,0]
listb=['aa','ddd','bb','cc','aaa','bbb','ccc']
def bubble_sort(lista):
    for i in range(0,len(lista)):
        for j in range(i+1,len(lista)):
            if lista[i]>lista[j]:
                lista[i],lista[j]=lista[j],lista[i]
    return lista

print(bubble_sort(lista))

# 直接调方法
listc=sorted(lista)
listd=sorted(lista,reverse=True)
print(listc)
print(lista.sort())
print(listd)
