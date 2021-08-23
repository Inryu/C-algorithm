#include <iostream>
using namespace std;

int N,M;
int res[10];

/*
 * 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
 *  고른 수열은 오름차순이어야 한다. -> 정렬한 후, ✨조합 구하기
 */
void dfs(int start, int level){
    if(level==M){
        for(int i=0;i<level;i++){
            cout<<res[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    //✨조합
    for(int i=start;i<=N;i++){
        res[level]=i;
        dfs(i+1,level+1);
    }
}

int main(){
    cin>>N>>M;
    dfs(1,0);
}