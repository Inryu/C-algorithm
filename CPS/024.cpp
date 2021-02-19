#include <stdio.h>
#include <vector>
#include<algorithm>    //abs()
using namespace std;

int main(){

    int n,i,now, pre, pos;
    
    scanf("%d",&n);
    
    vector<int> ch(n); //체크 배열

    scanf("%d",&pre); //첫 번째 숫자 읽기
    
    for(i=1;i<n;i++){
        scanf("%d",&now);
        pos=abs(pre-now);

        if(pos>0&&pos<n&&ch[pos]==0){ //범위에 있다면 중복이 있는지 확인 -> 중복 있으면 바로 탈락!
            ch[pos]=1;
        }
        else{ //범위에 없거나 중복됐으면 바로 탈락!
            printf("NO\n");
            return 0;
        }
        pre=now; //하나씩 밀림
    }
    printf("YES\n")
}