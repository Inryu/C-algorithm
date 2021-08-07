#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct minHeap{
    int time;
    minHeap(int t){
        time=t;
    }
    bool operator<(const minHeap &b)const{
        return time>b.time; // 내림차순 (최소힙)
    }
};

int main(){
    int N;
    int cnt=1; //처음엔 배정.

    vector<pair<int,int>> Class;

    cin>>N;
    for(int i=0;i<N;i++){
        int s,t;
        cin>>s>>t;
        Class.push_back(make_pair(s,t));
    }

    sort(Class.begin(), Class.end());

    priority_queue<minHeap> T; //최소 힙
    T.push(minHeap(0));

    for(int i=0;i<N;i++){
        int s=Class[i].first; //시작 시간
        int t=Class[i].second; //끝나는 시간

        if(T.top().time<=s){
            T.pop();
        }else{
            cnt++;
        }

        T.push(t);

    }
    cout<<cnt<<"\n";
}