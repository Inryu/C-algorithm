#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int m,n;
    cin>>m>>n;

    int change=m-n;

    //dy[j] : j원을 거슬러주는 데 사용한 화폐의 최소 개수
    vector<int> dy(change+1,24170000);//최대값으로 초기화

    vector<int> coin={50000,10000,5000,1000,500,100,50,10};
    vector<int> coin_check(8);


    dy[0]=0;

    //각 금액부터 시작 (금액이 큰 화폐순으로!)
    for(int i=0;i<coin.size();i++){
        if(coin[i]>change) continue;

        for(int j=coin[i];j<=change;j++){
            //해당 화폐를 쓰는 것이 더 최소이면
            if(dy[j-coin[i]]+1<dy[j]){
                dy[j]=dy[j-coin[i]]+1;
                coin_check[i]=1;
            }

        }
    }

    int count=0;

    for(int i=0;i<coin_check.size();i++){
        if(coin_check[i]!=0){
            count++;
        }
    }

    cout<<count<<" "<<dy[change];
    return 0;

}
