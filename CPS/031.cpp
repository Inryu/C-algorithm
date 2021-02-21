#include <stdio.h>
#include <vector>
#include<algorithm> 
using namespace std;

int main(){
    char a[10];
    int c=0,h=0,i,pos;

    scanf("%s",&a);


    //1. 탄소의 개수
    //C다음에 숫자인지 H인지
    if(a[1]=='H'){
        c=1;
        pos=1; //H의 포지션
    }

    //숫자이면 H만날 때까지
    else{
        for(i=1;a[i]!='H';i++){
            c=c*10+(a[i]-48)
        }
        pos=i; //H위치
    }

    //2. 수소의 개수
    if(a[pos+1]=='\0') h=1;
    else{
        for(i=p+1;a[i]!='\0';i++){
            h=h*10+(a[i]-48);
        }
    }
    printf("%d\n", c*12+h)

}