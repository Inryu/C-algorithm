#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1000+1
vector<int> map[MAX];
bool visited[MAX];
int N,M;

void bfs(int start){
    queue<int> q;

    visited[start]=true;
    q.push(start);

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(int i=0;i<map[cur].size();i++){
            if(!visited[map[cur][i]]){
                visited[map[cur][i]]=true;
                q.push(map[cur][i]);
            }
        }
    }
}

void dfs(int start){
    visited[start]=true;

    for(int i=0;i<map[start].size();i++){
        if(!visited[map[start][i]]){
            visited[map[start][i]]=true;
            dfs(map[start][i]);
        }
    }

}



int main(){
    cin>>N>>M;

    for(int i=0;i<M;i++){
        int s,e;
        cin>>s>>e;
        map[s].push_back(e);
        map[e].push_back(s);
    }

    int cnt=0;

    for(int i=1;i<=N;i++){
        if(!visited[i]){
            bfs(i);
            //dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<"\n";

}

