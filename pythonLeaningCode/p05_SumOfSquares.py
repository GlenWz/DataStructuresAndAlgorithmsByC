
# 给定一个数字N求平方和

def sumOfSquare(num:int)->int:
    ret=0
    for i in range(1,num+1):
        ret+=i*i

    return ret


print(sumOfSquare(8))
print(sumOfSquare(10))
print(sumOfSquare(1))
print(sumOfSquare(2))
print(sumOfSquare(3))