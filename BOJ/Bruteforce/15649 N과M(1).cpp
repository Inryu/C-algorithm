#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
int res[20];
bool visited[20];

/* ✨ 순열
 * 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열 , 1234!=4321
 */
void dfs(int level){
    if(level==M){
        for(int j=0;j<level;j++){
            cout<<res[j]<<" ";
        }
        cout<<"\n";
        return;
    }

    // ✨ 중복이 없어야 하므로 visited 사용
    for (int i = 1; i <= N; i++) {
        if(!visited[i]){
            visited[i]=true;
            res[level]=i;
            dfs(level+1);
            visited[i]=false;
        }
    }

}

int main(){
    cin>>N>>M;
    dfs(0);
}