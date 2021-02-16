#include <stdio.h>

//숫자만 추출
int main(){

    char a[100];
    int res=0,cnt=0,i;

    scanf("%s",&a);
    
    for(i=0;i<a[i]!='\0';i++){
        if(a[i]>=48&&a[i]<=57){ //아스키를 이용해서 숫자인지{
            res=res*10+(a[i]-48); //이전 res에 10을 곱해줘서 자연수로 만든다
        }   
    }

    printf("%d\n",res);

    //약수 개수
    for(i=1;i<=res;i++){
        if(res%i==0) cnt++;
    }

    printf("%d\n",cnt);
    return 0;

}