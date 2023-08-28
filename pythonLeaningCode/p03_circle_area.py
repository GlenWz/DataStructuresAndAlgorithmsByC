import math


# 求圆的面积
# 写一个抽象类之后矩形、圆、三角继承

class Polygon:
    pass
    def get_area(self):
        pass

class Triangle(Polygon):
    def get_area(self,a:float,b:float,c:float)->float:
        ret=0.0
        if a+b>c and a+c>b and b+c>a:
            p=0.5*(a+b+c)
            ret=float(p*(p-a)*(p-b)*(p-c)**0.5)
        else:
            print("error,边错误")
        return ret

class Rectangle(Polygon):
    def get_area(self,a:float,b:float)->float:
        return a*b

class Circle(Polygon):
    def get_area(self,r:float)->float:
        return math.pi*r*r

t1=Triangle()
print(t1.get_area(3.0,4.0,5.0))
r1=Rectangle()
print(r1.get_area(3.5,4.5))
c1=Circle()
print(c1.get_area(2.5))

