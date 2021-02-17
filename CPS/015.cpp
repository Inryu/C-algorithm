#include <stdio.h>

//015 소수의 개수
int main(){

    int n,i,j,
    cnt=0,flag;

    scanf("%d",&n); //자연수
    
    
    //시간 초과!!!!
    // for(i=2;i<=n;i++){

    //     flag=0;
    //     for(j=2;j<i;j++){ 
    //         if(i%j==0){
    //             flag=1; //소수가 아니라는 뜻
    //             break;
    //         }
    //     }

    //     if(flag==0) cnt++;
    // }


    //제곱근까지만 돌려도 된다
    for(i=2;i<=n;i++){

        flag=0;
        for(j=2;j*j<=i;j++){ 
            if(i%j==0){
                flag=1; //소수가 아니라는 뜻
                break;
            }
        }

        if(flag==0) cnt++;
    }


    printf("%d",cnt);

}