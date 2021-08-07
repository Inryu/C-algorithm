#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Time{
    int s; //시작 시간
    int t; // 끝 시간
    Time(int a, int b){
        s=a;
        t=b;
    }
    bool operator<(const Time &b )const{
        if(t!=b.t) return t<b.t; //오름차순
        return s<b.s;
    }
};

int main(){

    int N;
    vector<Time> meetings;
    cin>>N;
    for(int i=0;i<N;i++){
        int s,t; cin>>s>>t;
        meetings.push_back(Time(s,t));
    }
    sort(meetings.begin(), meetings.end());


    int beforeT=meetings[0].t;
    int cnt=1;

    for(int i=1;i<N;i++){
        int curS=meetings[i].s;
        int curT=meetings[i].t;

        if(curS>=beforeT){
            cnt++;
            beforeT=curT;
        }
    }

    cout<<cnt<<"\n";
}