#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 25
char map[MAX+1][MAX+1];
bool visited[MAX+1][MAX+1];
int N;
vector<int> res;
int cnt;

int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

void print(int i, int j){
    cout<<"ii\n";
}

void dfs(int r, int c){
    visited[r][c]=true;
    cnt++;

    for(int d=0;d<4;d++){
        int nr=r+dr[d];
        int nc=c+dc[d];

        if(nr<0||nr>N-1||nc<0||nc>N-1||map[nr][nc]!='1'||visited[nr][nc]) continue;
        dfs(nr,nc);
    }
}


int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(map[i][j]=='1'&&!visited[i][j]){
                cnt=0;
                dfs(i,j);
                res.push_back(cnt);
            }
        }
    }

    sort(res.begin(),res.end());

    cout<<res.size()<<"\n";
    for(int i:res){
        cout<<i<<"\n";
    }
}