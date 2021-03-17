#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int m,n;
    cin>>m>>n;

    int change=m-n;


    vector<int> coin={50000,10000,5000,1000,500,100,50,10};

    int count=0; //화폐 개수
    int kind_count=0; //화폐 종류


    //각 금액부터 시작 (금액이 큰 화폐순으로!)
    for(int i=0;i<coin.size();i++){

        int isUsed=0;

        while(coin[i]<=change){
            change-=coin[i];
            count++;
            isUsed=1;
        }

        if(isUsed) kind_count++;
    }


    cout<<kind_count<<" "<<count;
    return 0;

}
