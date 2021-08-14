#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 100000
bool visited[MAX+1];
int N,K;

int bfs(int time, int pos){

    deque<pair<int,int>> dq;
    visited[pos]=true;
    dq.push_back({time,pos});

    while(!dq.empty()){
        int curTime=dq.front().first;
        int curPos=dq.front().second;

        dq.pop_front();

        if(curPos==K) return curTime;

        //2*x
        if(2*curPos<=MAX&&!visited[2*curPos]){
            visited[2*curPos]= true;
            dq.push_front({curTime,2*curPos}); // 이동거리 (time)이 0이므로 front에 넣어줘야함@@
        }

        //x-1
        if(curPos>=1&&!visited[curPos-1]){
            visited[curPos-1]=true;
            dq.push_back({curTime+1,curPos-1});
        }

        //x+1
        if(curPos<=MAX-1&&!visited[curPos+1]){
            visited[curPos+1]= true;
            dq.push_back({curTime+1,curPos+1});
        }

    }

}

int main(){
    cin>>N>>K;
    cout<<bfs(0, N)<<"\n";
    return 0;
}
