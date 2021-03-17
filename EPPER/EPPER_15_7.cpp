#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Time{
    int s;
    int e;

   Time(int a, int b){
        s=a;
        e=b;
    }

    bool operator <(const Time &b) const{
       if(e!=b.e){
           return e<b.e; //종료기준 오름차순 정렬
       }else{ //종료시간이 똑같으면
           //시작이 더 빠른 것(작은 것)이 앞으로 옴
           return s<b.s;

       }
   }
};

int solution(vector<int> s, vector<int> e){
    int ans=0;
    int e1=-1, e2=-1; //각각 자리의 종료시간 초기화

    vector<Time> time;

    //Time 자료구조로 s와 e벡터 묶기
    for(int i=0;i<s.size();i++){
        time.push_back(Time(s[i],e[i]));
    }

    //정렬 -> ✨종료시간이 빠른 순으로 정렬!!!! (종료시간이 같으면 시작시간이 더 빠른 것으로)
    sort(time.begin(), time.end());

    //정렬한 time벡터를 돈다.
    for(int i=0;i<time.size();i++){
        //1번 자리에 앉을 수 있나 = 1번자리의 종료시간이 지금 넣을 학생의 시작시간보다 빠른가!?
        if(e1<=time[i].s){
            e1=time[i].e; //앉을 수 있다면, 지금 앉은 학생의 종료시간으로 초기화
            ans++;
        }else if(e2<=time[i].s){ //1에 앉을 수 없다면 2번 자리에 앉을 수 있나
            e2=e1; //e1을 먼저 체크하니깐 e1껄로 바꿔놓고
            e1=time[i].e; //e1은 이번애로 바꿔놓음.
            ans++;
        }
    }

    return ans;
}

int main(){
    int n,i;
    cin>>n;
    vector<int>s(n);
    vector<int>e(n);

    for(i=0;i<n;i++){
        cin>>s[i];
    }

    for(i=0;i<n;i++){
        cin>>e[i];
    }

    int res=solution(s,e);


    cout<<res;
}
