#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1001

int N, M, V;
vector<int> map[MAX];
bool visited[MAX];

void dfs(int v){
    cout<<v<<" ";

    for(int i : map[v]){
        if(!visited[i]){
            visited[i]=true;
            dfs(i);
        }
    }

}

void bfs(int v){
    queue<int> q;

    q.push(v);
    visited[v]=true;

    while(!q.empty()){
        int idx=q.front();
        q.pop();
        cout<<idx<<" ";

        for(int i : map[idx]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }

}

int main(){
    cin>>N>>M>>V;
    for(int i=0;i<M;i++){
        int a, b;
        cin>>a>>b; //양방향
        map[a].push_back(b);
        map[b].push_back(a);
    }

    for(int i=1;i<=N;i++){
        sort(map[i].begin(),map[i].end());
    }

    visited[V]=true;
    dfs(V);
    cout<<"\n";

    //visited 초기화
    memset(visited, false, sizeof(visited));
    bfs(V);
    cout<<"\n";

    return 0;


}
