//
// Created by 신인류 on 2021/03/03.
//
#include<stdio.h>
#include<vector>
#include<algorithm>
#include <stack>
using namespace std;
int n,ch[11];

void DFS(int L){
    int i;
    if(L==n+1){//종료
        for(i=1;i<=n;i++){
            if(ch[i]==1) printf("%d",i);
        }
        puts("");
    }
    else{ //이진 배열 탐색 (0,1로 체크하면서)
        ch[L]=1;//전위순!!! 왼쪽 자식으로
        DFS(L+1);
        ch[L]=0; //오른쪽 자식
        DFS(L+1);
    }

}


int main(){
    scanf("%d",&n);
    DFS(1); //1레벨부터!
}
