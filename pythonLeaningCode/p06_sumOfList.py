
# 求列表中所有数字的和

def sumOfList(inputList:list)->int:
    ret=0
    for item in inputList:
        ret+=item

    return ret

list1=[1,3,5,7,9]
list2=[1,3,5,7,9,2,4,6,8,10]

print(sumOfList(list1))
print(sumOfList(list2))