#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 500+1
int map[MAX][MAX];
int N,M,B;
int minTime=2147000000;
int maxHeigt;

int main(){
    cin>>N>>M>>B;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }

    // 모든 맵의 좌표를 해주는 것보다 이렇게 해야 하는 이유
    // 맵의 높이중에서만 고르는 게 아닐 수도 있음.
    for(int h=0;h<=256;h++){
        int plus=0;
        int minus=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
               int sub=map[i][j]-h;
               //제거
               if(sub>0){
                   minus+=sub;
               }else if(sub<0){  //추가
                   plus+=-1*sub;
               }

            }
        }

        if(minus+B>=plus){
            int time=plus+minus*2; //소요시간
            if(time<=minTime){
                minTime=time;
                maxHeigt=h;
            }
        }

    }
    cout<<minTime<<" "<<maxHeigt<<"\n";
}