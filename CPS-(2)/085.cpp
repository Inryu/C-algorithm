#include<stdio.h>
#include<vector>
#include<algorithm>
#include <stack>
using namespace std;

int op[5];
int n,maxval=-2147000000,minval=2147000000;
int sn[20]; //수열

void DFS(int L,int val){
    int i;
    if(L==n){
        if(val>maxval) maxval=val;
        if(val<minval) minval=val;
    }else{
            if(op[1]>0){
                op[1]--;
                DFS(L + 1, val + sn[L+1]);
                op[1]++;
            }
            if(op[2]>0){
                op[2]--;
                DFS(L + 1, val - sn[L+1]);
                op[2]++;
            }
            if(op[3]>0){
                op[3]--;
                DFS(L + 1, val * sn[L+1]);
                op[3]++;
            }
            if (op[4]>0) {
                op[4]--;
                DFS(L + 1, val / sn[L+1]);
                op[4]++;
            }

    }
}
int main(){

    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&sn[i]);
    }

    for(i=1;i<=4;i++){
        scanf("%d",&op[i]);

    }

    DFS(1,sn[1]);

    printf("%d\n",maxval);
    printf("%d\n",minval);

}

