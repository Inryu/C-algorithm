#include<stdio.h>
int n, T[20], P[20], res=0;
void DFS(int L, int sum){
    if(L==n+1){
        if(sum>res) res=sum;
    }
    else{

        //L날짜의 상담을 한다, 안 한다.
        if(L+T[L]<=n+1) DFS(L+T[L], sum+P[L]); //한다
        DFS(L+1, sum); // 안 한다
    }
}

int main(){
    freopen("input.txt", "rt", stdin);
    int i;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d %d", &T[i], &P[i]);
    }


    DFS(1, 0); //1일부터 시작
    printf("%d\n", res);

    return 0;
}