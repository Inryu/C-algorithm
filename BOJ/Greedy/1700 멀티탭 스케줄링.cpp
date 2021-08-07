#include <iostream>
using namespace std;

int cnt=0;
int N, K;
int order[101], plugs[101];

int main(){

    cin>>N>>K;

    for(int i=0;i<K;i++){
       cin>>order[i];
    }

    //사용횟수 <= 멀티탭 구멍 개수
    if(K<=N){
        cout<<0<<"\n";
        return 0;
    }

    //<실수1🥲> 0~N-1까지 그냥 넣으면 안 됨 . 거기서도 중복 있을 수 있음..

    for(int i=0;i<K;i++){
        bool isPlugged=false;
        //현재 플러그에 꼽혀있나
        for(int j=0;j<N;j++){
            if(order[i]==plugs[j]) {
                isPlugged=true;
                break;
            }
        }

        if(isPlugged) continue;


        // 비어있는지 확인
        for(int j=0;j<N;j++){
            if(!plugs[j]){
                plugs[j]=order[i];
                isPlugged=true;
                break;
            }
        }

        if(isPlugged) continue;


        // 현재 플러그에 없으면 뭘 뽑아야할지 골라야 함
        // 플러그에 있는 것중 가장 나중에 사용하는 것 제거 (또는 아예 사용되지 않는 것)
        int plugsIdx; //뽑을 플러그 인덱스
        int max=-1;

        for(int j=0;j<N;j++){
            int lastIdx=-1;
            for(int k=i+1;k<K;k++){
                if(plugs[j]==order[k]){
                    lastIdx=k;
                    break; // <실수1🥲> 중복되면 가장 최근에 쓰이는 걸로 찾아야됨....
                }
            }

            if(lastIdx==-1){ //사용된 적 없으면
                plugsIdx=j;
                break;
            }

            if(lastIdx>max){
                plugsIdx=j;
                max=lastIdx;
            }
        }
        //뽑기
        plugs[plugsIdx]=order[i];
        cnt++;
    }

    cout<<cnt<<"\n";
    return 0;
}