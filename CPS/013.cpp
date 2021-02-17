#include <stdio.h>

int cnt[10]; //전역변수는 자동으로 0으로 초기화!!!

//지역변수로 초기화 해야하면
// int arr[100] = {0,};
 // 전부 0으로

int main(){

    // freopen("input.txt","rt",stdin); //cin이 읽을 때마다 지정 파일에서 읽어줌

    int i,max=-21470000,index;

    char n[100];
    
    scanf("%s",&n);

    for(i=0;n[i]!='\0';i++){
        cnt[n[i]-48]++;
    }

    for(i=0;i<=9;i++){
        if(cnt[i]>=max) {
            max=cnt[i];
            index=i;
        }


    }

    printf("%d\n",index);

    return 0;



}