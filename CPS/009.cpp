#include <stdio.h>

int cnt[50001]; //동적할당은 안해도 되는겨?
int main(){

    //1초 안에 할 수 없음..시간 복잡도가 너무 크다
    // int n,i,j;

    // scanf("%d",&n);

    // for(i=1;i<=n;i++){
    //     int cnt=0;
    //     for(j=1;j<=i;j++){
    //         if(i%j==0){
    //             cnt++;
    //         }
    //     }

    //     printf("%d ",cnt);

    // }

    // return 0;

    //!!만약 n=8이면 8크기의 배열을 만들고 0으로 초기화!(앞에서부터 1,2..8)
    //for문을 한 번만 돌면서, 1에 있을 때는 1의 배수들 원소에게 모두 +1을 해준다.
    //2에서는 2의 배수에 ++;

    int n,i,j;
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        for(j=i;j<=n;j=j+i){ //j는 i의 배수만큼씩 증가하면서 돈다.
            cnt[j]++; //자기 자신을 포함한 자신의 배수들에게 ++
        }
    }

    for(i=1;i<=n;i++){
        printf("%d",cnt[i]);
    }

}