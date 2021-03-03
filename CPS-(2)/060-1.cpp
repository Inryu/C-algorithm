
#include<stdio.h>
int n, a[11], total=0;
bool flag=false;

void DFS(int L, int sum){
    if(sum>(total/2)) return;
    if(flag==true) return;

    if(L==n+1){ //마지막 레벨까지 왔을 때
        if(sum==(total-sum)){ //정확히 반반 나눠졌는지
            flag=true;
        }
    }
    else{
        DFS(L+1, sum+a[L]); //왼쪽 노드 : 포함
        DFS(L+1, sum); //오른쪽 노드 : 포함 X
    }
}
int main(){
    int i;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d", &a[i]);
        total+=a[i];
    }
    DFS(1, 0);
    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}
