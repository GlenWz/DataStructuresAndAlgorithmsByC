#include <stdio.h>
#include <string.h>

/*
����ĳ�ַ����ִ���
����
д��һ�����򣬽���һ������ĸ�����ֺͿո���ɵ��ַ�������һ���ַ���Ȼ����������ַ����и��ַ��ĳ��ִ������������ִ�Сд��ĸ��
���ݷ�Χ�� 
1��1000
1 ��n ��1000 
����������
��һ������һ������ĸ�����ֺͿո���ɵ��ַ������ڶ�������һ���ַ�����֤���ַ���Ϊ�ո񣩡�
��������� 
��������ַ����к��и��ַ��ĸ������������ִ�Сд��ĸ�� 
ʾ��1
���룺
ABCabc
A
����
�����
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

//����˼·��ͨ��ASCII�����ж�������ַ���Χ��Ȼ����м��� 
