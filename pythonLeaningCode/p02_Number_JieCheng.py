
# 求数字的阶乘

def factorial(num):
    ret=1
    while num>0:
        ret*=num
        num-=1
    return ret

def factorialFor(num):
    ret=1
    for i in range(1,num+1):
        ret*=i

    return ret

print("factorial 6=",factorial(6))
print("factorial 10=",factorial(10))

print("factorialFor 6=",factorialFor(6))
print("factorialFor 10=",factorialFor(10))

