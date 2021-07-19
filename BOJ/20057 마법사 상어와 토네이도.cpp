#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//좌 하 우 상
int dr[]={0,1,0,-1};
int dc[]={-1,0,1,-0};

//방향에 따른 비율 좌표
int dwr[4][9]={
        {-1,1, -1, 1, -2, 2, -1, 1, 0},//바람 방향 : 좌
        {-1,-1,0,0,0,0,1,1,2},// 바람 방향 : 하
        {1,-1,1,-1,2,-2,1,-1,0}, // 우
        {1,1,0,0,0,0,-1,-1,-2} //상
};
int dwc[4][9]={
        {1,1,0,0,0,0,-1,-1,-2},//바람 방향 : 좌
        {-1,1,-1,1,-2,2,-1,1,0},// 바람 방향 : 하
        {-1,-1,0,0,0,0,1,1,2}, // 우
        {1,-1,1,-1,2,-2,1,-1,0} //상
};

//비율 순서
int ratios[]={1,1,7,7,2,2,10,10,5};

int N;
int map[500][500];
int wr,wc; int wd=0;//바람의 위치, 방향
int ans=0;

void moveWindy(int len);
void spreadSend();

int main(){

    cin>>N;

    //바람의 출발 지점.
    wr=N/2;
    wc=N/2;

    //input
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }

    int len=1; //이동하는 길이
    for(int i=1;i<=N-1;i++){
        for(int j=1;j<=2;j++){
            //현재 방향으로 len만큼 이동
            moveWindy(len);
            wd=(wd+1)%4; //방향 전환
        }
        len++;
    }

    //마지막 이동
    moveWindy(len-1);
    cout<<ans<<"\n";

}

//현재 방향으로 len만큼 이동
void moveWindy(int len){
    for(int i=0;i<len;i++){
        wr+=dr[wd];
        wc+=dc[wd];
        //한 칸 이동할 때마다 모래 흩날리기
        spreadSend();
    }
}

void spreadSend(){
    int centerVal=map[wr][wc]; //y의 모래 양

    //비율 순서대로
    for(int i=0;i<9;i++){
        //비율 순 좌표
        int nr=wr+dwr[wd][i];
        int nc=wc+dwc[wd][i];

        //해당 좌표의 비율
        int sendVal=(centerVal*ratios[i])/100;

        map[wr][wc]-=sendVal; //이동하여 없어짐

        //범위를 벗어나면
        if(nr<0||nc<0||nr>=N||nc>=N){
            ans+=sendVal;
            continue;
        }
        map[nr][nc]+=sendVal;
    }

    //남은 모래

    //a좌표 : y좌표에서 현재 방향으로 한 칸 더 이동
    int nr=wr+dr[wd];
    int nc=wc+dc[wd];

    //범위를 벗어나면
    if(nr<0||nc<0||nr>=N||nc>=N){
        ans+=map[wr][wc]; //남은 모래
        map[wr][wc]=0;
        return;
    }

    //범위 안 벗어나면
    map[nr][nc]+=map[wr][wc];
    map[wr][wc]=0;
}