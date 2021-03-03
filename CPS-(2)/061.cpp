#include<stdio.h>
#include<vector>
#include<algorithm>
#include <stack>
using namespace std;

int n,m,cnt=0;
int a[11];

void DFS(int L,int val){

    if(L==n+1){
        if(val==m) cnt++;
    }else{

        //3가지로 나눠짐 1. +a[L] 2. -a[L] 3. a[L]이 들어가지 않음
        DFS(L+1,val+a[L]);
        DFS(L+1,val-a[L]);
        DFS(L+1,val);
    }

}

int main(){

    int i;
    scanf("%d %d",&n, &m);

    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    DFS(1,0); //(레벨, 값)

    if(cnt==0) printf("-1\n");
    else printf("%d\n",cnt);
    return 0;
}