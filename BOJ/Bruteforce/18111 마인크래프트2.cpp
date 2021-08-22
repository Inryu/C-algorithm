#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 500+1
int map[MAX][MAX];
int N,M,B;
int minTime=2147000000;
int maxHeigt;
int visitHeight[256];

void work(int targetHeight){
    int plus=0;
    int minus=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int sub=map[i][j]-targetHeight;
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
            maxHeigt=targetHeight;
        }
    }
}

int main(){
    cin>>N>>M>>B;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }


    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!visitHeight[map[i][j]])  work(map[i][j]);
            visitHeight[map[i][j]]=true;
        }
    }
    cout<<minTime<<" "<<maxHeigt<<"\n";
}