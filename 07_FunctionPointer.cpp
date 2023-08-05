#include <stdio.h>

typedef int (* Calc)(int,int);

int add(int a,int b){
    int result=a+b;
    return result;
}

int sub(int a,int b){
    int result=a-b;
    return result;
}


int main(){
    int x=100;
    int y=200;
    int z=0;
    z=add(x,y);
    printf("add:%d\n",z);
    z=sub(x,y);
    printf("sub:%d\n",z);
    Calc cPoint1=&add;
    Calc cPoint2=&sub;

    z=cPoint1(x,y);
    printf("add:%d\n",z);
    z=cPoint2(x,y);
    printf("add:%d\n",z);
    return 0;
}
