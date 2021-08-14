#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 101

int N,M;
int computers[MAX][MAX];
bool visited[MAX];


int bfs(int start){
    int cnt=0;
    queue<int> q;

    visited[start]=true;
    q.push(start);

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(int i=1;i<=N;i++){
            if(computers[cur][i]&&!visited[i]){
                q.push(i);
                visited[i]=true;
                cnt++;
            }
        }
    }

    return cnt;
}

int main(){
    cin>>N;
    cin>>M;

    for(int i=0;i<M;i++){
        int s,e;
        cin>>s>>e;
        computers[s][e]=1;
        computers[e][s]=1;
    }

    //1번 컴퓨터가 걸림.
    cout<<bfs(1)<<"\n";
}