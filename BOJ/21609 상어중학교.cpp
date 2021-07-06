#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//블럭그룹 구조체
struct Blocks{
    int size;//블록 그룹 크기
    int rainbowCnt; //무지개 블록 개수
    int r,c; //기존블록 행렬
    queue <pair <int, int>> block; // 블럭 좌표들

    Blocks(int size_, int rainbowCnt_, int r_, int c_, queue <pair <int, int>> block_){
        size=size_;
        rainbowCnt=rainbowCnt_;
        r=r_;
        c=c_;
        block=block_;
    }

    // 정렬 기준 (우선순위큐)
    //1. 크기가 가장 큰 블록, 2. 무지개 개수가 많은 블록, 3. 행이 큰 블록, 4. 열이 큰 블록.
    bool operator<(const Blocks &b) const{
        if(size==b.size){
            if(rainbowCnt==b.rainbowCnt) {
                if (r == b.r) return c < b.c;
                else return r < b.r;
            }
            else return rainbowCnt<b.rainbowCnt;
        }else{
            return size<b.size;
        }
    }
};

int score=0;
int N,M;
int map[20][20];

// 상, 우 , 하, 좌
int dr[4]={0,1,0,-1};
int dc[4]={-1,0,1,0};

void input();
bool find_bigblock();
void gravity();
void rotate();

int main(){
    input();
    while(true){
        int res=find_bigblock();
        if(!res) break; //블럭이 없는 경우 종료
        gravity();
        rotate();
        gravity();
    }
    cout<<score;

    return 0;
}

void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }
}

bool find_bigblock() {
    bool visit[20][20] = {false,}; //BFS시 방문했는지 체크
    priority_queue<Blocks> pQ; // 블록 그룹 => 우선순위 큐로 정렬될 것

    //블록 탐색 후 우선순위 큐에 삽입.
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){

            //기준 블록 찾기
            if(map[i][j]>0&&!visit[i][j]){
                bool rainbowVisit[20][20]={false,}; //무지개는 하나의 블록그룹 안에서만 체크하면 됨.
                queue<pair<int,int>> Q; //기준 블록 좌표
                queue<pair<int,int>> QQ; // pQ에 넣어줄 좌표
                Q.push({i,j});
                QQ.push({i,j});
                visit[i][j]=true;

                int size=1, rainbowCnt=0;
                while(!Q.empty()){
                    int r=Q.front().first;
                    int c=Q.front().second;
                    Q.pop();

                    for(int d=0;d<4;d++){
                        int nr=r+dr[d];
                        int nc=c+dc[d];

                        if(nr<0||nr>N-1||nc<0||nc>N-1||visit[nr][nc]||rainbowVisit[nr][nc]) continue;

                        //1.무지개 블록이거나 2.일반 블록일 때만 탐색
                        //무지개 블록
                        if(map[nr][nc]==0){
                            rainbowVisit[nr][nc]=true;
                            Q.push({nr,nc});
                            QQ.push({nr,nc});
                            size++;
                            rainbowCnt++;
                        }
                        //일반블록일 때, 기준블록과 색깔이 같아야
                        else if(map[i][j]==map[nr][nc]){
                            visit[nr][nc]=true;
                            Q.push({nr,nc});
                            QQ.push({nr,nc});
                            size++;
                        }

                    }
                }
                //Q에 블록그룹 블록 넣기 끝.
                pQ.push(Blocks(size,rainbowCnt,i,j,QQ)); //블록그룹 완성
            }
        }
    }

    //블록그룹이 없으면 false반환
    if(pQ.empty())
        return false;


    if(pQ.top().size<2)
        return false;


    //가장 큰 블록그룹의 모든 블럭 제거
    int size=pQ.top().size;
    score+=size*size;

    queue <pair <int, int>> block=pQ.top().block; //블럭의 좌표들

    while(!block.empty()){
        int r=block.front().first;
        int c=block.front().second;
        block.pop();

        map[r][c]=-2; //삭제
    }

    return true;
}

void gravity(){
    for(int i=N-1;i>=0;i--){ //맨 밑 행부터 내리기
        for(int j=0;j<N;j++){
            if(map[i][j]==-2||map[i][j]==-1) continue;

            //원래 행 좌표
            int r=i; r++;
            //원래 값
            int color=map[i][j];
            while(true){
                if(map[r][j]!=-2) break;
                if(r==N) break;
                r++;
            }
            r--;
            map[i][j]=-2;
            map[r][j]=color;
        }
    }
}

void rotate(){
    int temp[20][20]; //90도 회전하여 저장

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            temp[i][j]=map[j][N-1-i];
        }
    }

    // 다시 맵에 복사
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            map[i][j]=temp[i][j];
        }
    }

}
