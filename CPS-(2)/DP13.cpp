#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//회장 뽑기(플로이드-워샬 응용)

int main(){
    int n,a,b;


    cin>>n;
    vector< vector<int>> dis (n+1,vector<int>(n+1,5000));
    vector<int> maxval(n+1); //각 회원마다의 점수 기록
    vector<int> candidate; //후보
    int res=2147000; //회장 후보 점수

    for(int i=1;i<=n;i++) dis[i][i]=0; //🌟‼️꼭..

    while(true){
        cin>>a>>b;

        if(a==-1&&b==-1) break;
        //a와 b는 서로 친구
        dis[a][b]=1;
        dis[b][a]=1;

    }

    //✨플로이드-워샬
    //k : 중간에 거침 1번 사람부터 ~ n번사람까지
    for(int k=1;k<=n;k++){
        //2차원 배열 dis 전부 탐색
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }

    }

    //각 회원마다, (각 행에서) Max값 찾기 =점수
    for(int i=1;i<=n;i++){
        int maxdis=-1;
        for(int j=1;j<=n;j++) {
            if (dis[i][j] > maxdis) {
                maxdis = dis[i][j];
                maxval[i] = maxdis;
            }
        }

        if(maxval[i]<res){
            res=maxval[i]; //가장 작은 점수
        }
    }

    for(int i=1;i<=n;i++){
        if(maxval[i]==res){
            candidate.push_back(i); //후보에 회원 넣기
        }
    }

    cout<<res<<" "<<candidate.size()<<"\n";

    for(int i=0;i<candidate.size();i++){
        cout<<candidate[i]<<" ";
    }

}
