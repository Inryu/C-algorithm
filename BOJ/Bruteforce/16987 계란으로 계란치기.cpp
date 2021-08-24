#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <pair<int,int>> eggs; //내구도, 무게
int maxCnt=-1; //최대 몇 개의 계란을 깨냐

void hitEgg(int start){
    if(start==N){  //가장 오른쪽에 위치한 계란일 경우 종료
        int cnt=0;
        for(auto & egg : eggs){
            if(egg.first<=0) cnt++;
        }
        maxCnt=max(maxCnt,cnt);
        return ;
    }

    // 손에 든 계란이 깨져있는 경우
    if(eggs[start].first<=0) {
        //다음으로 넘어감
        hitEgg(start+1);
        return;
    }

    bool isExist=false; //안깨진 계란이 있는지
    // 깨지지 않은 다른 계란 중에서 하나를 친다.
    for(int i=0;i<N;i++){
        if(start==i) continue; //자기 자신
        if(eggs[i].first<=0) continue; //깨진 계란일 경우 그냥 넘어감.

        isExist=true;

        //계란 치기
        eggs[start].first-=eggs[i].second;
        eggs[i].first-=eggs[start].second;
        hitEgg(start+1);
        eggs[start].first+=eggs[i].second;
        eggs[i].first+=eggs[start].second;
    }

    //남은 것중 안깨진 게 없을 경우 더 볼 것 없이 바로.
    if(!isExist) hitEgg(N);
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        int s, w;
        cin>>s>>w;
        eggs.push_back({s,w});
    }

    hitEgg(0); //0번 계란부터 친다.
    cout<<maxCnt<<"\n";

}