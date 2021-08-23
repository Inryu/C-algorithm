#include <iostream>
using namespace std;

int N,M;
int res[20];

/* 1부터 N까지 자연수 중에서 M개를 고른 수열*/
/* 같은 수를 여러 번 골라도 됨!.*/
void dfs(int level){
    if(level==M){
        for(int j=0;j<level;j++){
            cout<<res[j]<<" ";
        }
        cout<<"\n";
        return;
    }

    //✨ 같은 수를 여러 번 골라도 됨! -> visited필요 없다.
    // 1부터 쭉.
    for (int i = 1; i <= N; i++) {
        res[level]=i;
        dfs(level+1);
    }

}

int main(){
    cin>>N>>M;
    dfs(0);
}