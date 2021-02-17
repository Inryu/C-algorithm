#include <stdio.h>

int main(){

    int N, a[100],b[100],i;

    scanf("%d",&N);

    //A가 낸 거
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }

    //B가 낸 거
    for(i=0;i<N;i++){
        scanf("%d",&b[i]);
    }

    for(i=0;i<N;i++){

        //비기는 경우
        if(a[i]==b[i]) printf("D\n");

        //A가 이기는 경우
        else if(a[i]==1&&b[i]==3) printf("A\n");
        else if(a[i]==2&&b[i]==1) printf("A\n");
        else if(a[i]==3&&b[i]==2) printf("A\n");

        //나머지 전부
        else printf("B\n");

    }
    
}