#include<iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX=16;
int N;
int map[MAX][MAX];
int tmpMap[MAX][MAX];
bool visited[MAX][MAX];
//상우하좌
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
//조합용
vector<int> num;
int res[3];
int maxVal;

void copyMap(){
    for(int i=0;i<3*N;i++){
        for(int j=0;j<N;j++){
            tmpMap[i][j]=map[i][j];
        }
    }
}

void printMap(){
    for(int i=0;i<3*N;i++){
        for(int j=0;j<N;j++){
            cout<<tmpMap[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void down(){
    //각 열
    for(int i=0;i<N;i++){
        //행!
        for(int j=3*N-1;j>=1;j--){
            if(tmpMap[j][i]==0){
                int r=j;
                while(true){
                    r--;
                    if(r<0) break;
                    if(tmpMap[r][i]) {
                        tmpMap[j][i]=tmpMap[r][i];
                        tmpMap[r][i]=0;
                        break;
                    }
                }
            }
        }
    }
}

int bfs(int r, int c, int color){
    int cnt=0; //사라지는 자동차 개수
    queue<pair<int,int>> q;
    memset(visited,0,sizeof(visited));

    q.push({r,c});
    tmpMap[r][c]=0; //사라짐
    visited[r][c]=true;
    cnt++;
    int minR=r;
    int minC=c;
    int maxR=r;
    int maxC=c;


    while(!q.empty()){
        int cr=q.front().first;
        int cc=q.front().second;
        q.pop();

        for(int d=0;d<4;d++){
            int nr=cr+dr[d];
            int nc=cc+dc[d];

            if(nr<0||nr>3*N-1||nc<0||nc>3*N-1) continue;
            if(visited[nr][nc]) continue;
            if(tmpMap[nr][nc]!=color) continue;


            q.push({nr,nc});
            tmpMap[nr][nc]=0; //사라짐
            visited[nr][nc]=true;
            cnt++;

            minR=min(minR,nr);
            minC=min(minC,nc);
            maxR=max(maxR,nr);
            maxC=max(maxC,nc);
        }
    }
    //점수
    int score=cnt+(maxC-minC+1)*(maxR-minR+1);
    return score;
}

//조합 구현
void dfs(int startIdx, int level){
    //3개를 다 골랐을 경우
    if(level==3){
        //각 조합마다 새로운 map에

        copyMap();
        int score=0;

        //3라운드
        for(int l=0;l<3;l++){
            int i=res[l]/N+2*N;
            int j=res[l]%N;
            //1. 사라지고
            score+=bfs(i,j,tmpMap[i][j]);
            //cout<<"score"<<score<<"\n";
            //2. 내려오고
            down();
            //printMap();
        }
        maxVal=max(maxVal,score);
        return;
    }

    //주어진 number배열을 start부터~k-1 인덱스까지 탐색한다.
    for(int i=startIdx;i<num.size();i++){
        res[level]=num[i];
        dfs(i+1, level+1);
    }

}

int main(int argc, char** argv)
{
    cin>>N;
    for(int i=0;i<3*N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<N*N;i++){
        num.push_back(i);
    }

    //조합.
    dfs(0,0);

    cout<<maxVal;
    return maxVal;
}