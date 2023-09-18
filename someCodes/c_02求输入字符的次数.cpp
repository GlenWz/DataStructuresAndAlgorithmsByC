#include <stdio.h>
#include <string.h>

/*
计算某字符出现次数
描述
写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字符，然后输出输入字符串中该字符的出现次数。（不区分大小写字母）
数据范围： 
1≤1000
1 ≤n ≤1000 
输入描述：
第一行输入一个由字母、数字和空格组成的字符串，第二行输入一个字符（保证该字符不为空格）。
输出描述： 
输出输入字符串中含有该字符的个数。（不区分大小写字母） 
示例1
输入：
ABCabc
A
复制
输出：
2
*/

int main() {
    char str[1000];
   	char pattern;
    int count=0;
    gets(str);
	pattern=getchar();
    for(int i=0;i<strlen(str);i++){
        if(pattern>=97){
            if(str[i]+32==pattern||str[i]==pattern){
                count++;
            }
        }else if(pattern>=64&&pattern<97){
            if(str[i]-32==pattern||str[i]==pattern){
                count++;
            }
        }else{
            if(pattern==str[i]){
                count++;
            }
        }
    }
    printf("%d",count);
}

//解题思路，通过ASCII码来判定输入的字符范围，然后进行计算 
