
# 打印输出范围内的所有质数
def is_primeNumber(num:int)->bool:
    isPrime:bool=True
    ret=0
    for i in range(2,int(num/2)+1):
        if(num%i==0):
            isPrime=False

    return isPrime
def confirm_primeNumber(beginNum:int,endNum:int):
    for i in range(beginNum,endNum):
        if is_primeNumber(i):
            print(i)

confirm_primeNumber(2,50)