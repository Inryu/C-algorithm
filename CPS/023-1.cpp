//풀이 코드
//배열을 쓰지 않고, 전의 값 pre, 현재 읽는 값 now를 둠
#include <stdio.h>

int main(){

    int n,i,pre,now,cnt=1,max=0;
    scanf("%d",&n);
    scanf("%d",&pre); //첫 값은 역시 읽어주기

    for(i=2;i<=n;i++){
        scanf("%d",&now);

        if(now>=pre){
            cnt++;
            if(cnt>max) max=cnt;
        }
        else cnt=1;
        pre=now; //하나씩 밀기
    }

    printf("%d\n",max);
    return 0;
}
