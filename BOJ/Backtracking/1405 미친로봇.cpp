#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int N;
double Percent[4]; //동서남북으로 각각 이동할 확률!

//동,서,남,북
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};

bool Visit[30][30]={false,};
double ans;



void dfs(int len,double percent, int r, int c){

    if(len==N){
        ans+=percent;
        return;
    }

    // 각 위치에서 동,서,남,북으로 뻗는다
    for(int i=0;i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];

        // valid하면 방문.
        if(!Visit[nr][nc]){
            Visit[nr][nc]=true; //방문.
            dfs(len+1, percent*Percent[i],nr,nc);
            Visit[nr][nc]=false; // return 됐으면 false로 가는 건가!?

        }
    }

}

int main(){
    cin>>N;

    for(int i=0;i<4;i++){
        int a; cin>>a;
        Percent[i]=a/100.0;
    }

    Visit[15][15]=true; //방문.
    dfs(0,1,15,15);

    cout.precision(10);
    cout<<fixed<<ans<<"\n";
}
