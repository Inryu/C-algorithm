#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n,k,i,cnt=0,pos=0;
    int bp=0; //n-1명 아웃시키면 끝!!

    scanf("%d %d",&n,&k);

    vector<int> a(n+1);// 모두 0으로 초기화, 나가리 된 애들은 1로 바꿀 것임

    while (1){
        pos++;

        if(pos>n){
            pos=1;
        } //회전

        if(a[pos]==0){ //나가리 아님
            cnt++; //숫자 세주고
            if(cnt==k){ //k를 외쳤다면
                a[pos]=1; //나가리
                cnt=0; //다시 세야 함
                bp++;
            }

        }
        if(bp==n-1) break;
    }

    for(i=1;i<=n;i++){
        if(a[i]==0){
            printf("%d\n",i);
        }

    }
    



}