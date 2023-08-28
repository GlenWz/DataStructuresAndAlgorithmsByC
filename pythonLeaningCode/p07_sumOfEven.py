
# 求给定范围内所有偶数和

def sumOfEven(beginNum:int,endNum:int)->int:
    ret=0
    retList=[]
    for i in range(beginNum,endNum):
        if i %2==0:
            ret+=i
            retList.append(i)

    return ret,retList

sum,retList=sumOfEven(2,50)
print(sum)
print(retList)

