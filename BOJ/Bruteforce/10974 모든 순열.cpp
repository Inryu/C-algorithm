#include <iostream>
#include <cstring>
using namespace std;
int N;
int res[10];
bool visited[10];


void dfs(int level){
    if(level==N){
        for(int i=0;i<N;i++){
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }

    for(int i=1;i<=N;i++){
        if(!visited[i]){
            visited[i]=true;
            res[level]=i;
            dfs(level+1);
            visited[i]=false;
        }
    }
}
int main(){
    cin>>N;
    dfs(0);
}
