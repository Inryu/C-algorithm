#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define MAX 25
char map[MAX+1][MAX+1];
bool visited[MAX+1][MAX+1];
int N;
vector<int> res;

int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

void bfs(int r,int c){
    int cnt=0;

    queue<pair<int,int>> q;
    visited[r][c]=true;
    q.push(make_pair(r,c));
    cnt++;

    while(!q.empty()){
        int cr=q.front().first;
        int cc=q.front().second;
        q.pop();

        for(int d=0;d<4;d++){
            int nr=cr+dr[d];
            int nc=cc+dc[d];

            if(nr<0||nr>N-1||nc<0||nc>N-1||map[nr][nc]!='1'||visited[nr][nc]) continue;

            visited[nr][nc]=true;
            q.push(make_pair(nr,nc));
            cnt++;
        }
    }
    res.push_back(cnt);
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
                bfs(i,j);
            }
        }
    }

    sort(res.begin(),res.end());

    cout<<res.size()<<"\n";
    for(int i:res){
        cout<<i<<"\n";
    }
}