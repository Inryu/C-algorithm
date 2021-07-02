#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 55
using namespace std;

int n,m;
int map[MAX][MAX];
int check[MAX][MAX]; //구름이 사라진 칸=비가 온 칸 인지


//0, ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dr[]={0,0,-1,-1,-1,0,1,1,1};
int dc[]={0,-1,-1,0,1,1,1,0,-1};

struct Loc{
    int r;
    int c;

    Loc(int x, int y){
        r=x;
        c=y;
    }
};

struct Magic{
    int d; //방향
    int s; //거리

    Magic(int x, int y){
        d=x;
        s=y;
    }
};

queue<Loc> cloud; //구름 좌표
queue<Loc> removed_cloud; //사라지는 구름 좌표
vector <Magic> magic; //m회의 마법

//1. input, 비바라기 시전
void input(){
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }

    int d,s;

    for(int i=0;i<m;i++){
        cin>>d>>s;
        magic.push_back(Magic(d,s));
    }

    //비바라기 시전
    cloud.push(Loc(n,1));
    cloud.push(Loc(n,2));
    cloud.push(Loc(n-1,1));
    cloud.push(Loc(n-1,2));
}


// 2. 구름 이동
void move_cloud(Magic magic){

    int size=cloud.size();
    // 큐 크기만큼.
    for(int i=0;i<size;i++){
        Loc cur=cloud.front();
        cloud.pop();

        int r=cur.r;
        int c=cur.c;

        for(int j=0;j<magic.s;j++){
            r+=dr[magic.d];
            c+=dc[magic.d];

            // 범위를 넘어간 경우
            if(r<=0) r=n;
            if(c<=0) c=n;
            if(r>n) r=1;
            if(c>n) c=1;
        }

        // 새로 이동한 구름 좌표 넣어주기.
        cloud.push(Loc(r,c));
    }

}

//3. 비 오고 구름 사라짐
void rain(){
    // 비 내리고 사라지기 전에, 구름 좌표 저장해놓기.
    removed_cloud=cloud;

    // 비 오기, 구름 사라짐
    while(!cloud.empty()){
        Loc cur=cloud.front();
        cloud.pop();

        //비가 왔음(=구름이 사라짐)을 체크
        check[cur.r][cur.c]=1;

        //비 옴
        map[cur.r][cur.c]+=1;
    }
}

//4. 물 복사 마법
void duplicate_magic(){

    // 비가 내린 곳에
    while(!removed_cloud.empty()){
        Loc cur=removed_cloud.front(); removed_cloud.pop();

        int r=cur.r; int c=cur.c;

        //대각선 체크
        for(int i=2;i<=8;i+=2){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr<=0||nr>n||nc<=0||nc>n) continue;

            //물이 있는 바구니 일 때만
            if(map[nr][nc]>0){
                map[r][c]+=1;
            }

        }
    }

}

//5. 구름 생성
void create_cloud(){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //구름이 사라진 칸이 아니고 물이 2 이상이면
            if(!check[i][j]&&map[i][j]>=2){
                cloud.push(Loc(i,j));
                map[i][j]-=2;
            }

        }
    }

    //check 배열 0으로 초기화
    memset(check, 0, sizeof(check));

}

int main(){
    input(); //1. input, 비바라기 시전

    for(auto & i : magic){
        move_cloud(i); //2. 구름 이동
        rain(); //3. 비 오고, 구름 사라짐
        duplicate_magic(); //4.  물복사 마법
        create_cloud(); //5. 구름 생성
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans+=map[i][j];
        }
    }

    cout<<ans;
}