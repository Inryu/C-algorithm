#include <stdio.h>

int main(){
    // freopen("input.txt","rt",stdin); //cin이 읽을 때마다 지정 파일에서 읽어줌
    int n,i,cnt=0,tmp;

    scanf("%d",&n);

    for(i=1;i<=n;i++){

            tmp=i; //n을 바꿔버리면 안 됨!!

            while(tmp>0){
                tmp/=10; //뒤에서부터 하나씩 자리 지우면서 카운트
                cnt++;
        }
    }

    printf("%d",cnt);
    return 0;

}