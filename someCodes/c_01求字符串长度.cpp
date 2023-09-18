#include <stdio.h>
#include <string.h>

int main() {
    char str[5000];
    int len=0;
    while(scanf("%s",str)!=EOF){
    	
        len=strlen(str);
    }
    printf("%d\n",len);
    return 0;
}
