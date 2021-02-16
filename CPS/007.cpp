#include <stdio.h>

int main(){
    // freopen("input.txt","rt",stdin); //cin이 읽을 때마다 지정 파일에서 읽어줌

    char a[100],b[100];
    int i,p=0;

    //줄바꿈을 포함해서 다 읽어야함!!
    gets(a);

    for(i=0;a[i]!='\0';i++){
        if(a[i]!=' ')//공백이 아니라면
            if(a[i]>=65&&a[i]<=90){ //아스키..대문자..
                b[p++]=a[i]+32; //소문자로 변환..
            }else {b[p++]=a[i];}
    }

    b[p]='\0'; //문자열의 마지막을 알려줘야 함

    printf("%s\n",b);




    return 0;
}