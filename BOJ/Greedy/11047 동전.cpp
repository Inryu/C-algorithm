#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> coin;
    int N,K;
    cin>>N>>K;

    int val;
    for(int i=0;i<N;i++){
        cin>>val;
        coin.push_back(val);
    }

    reverse(coin.begin(), coin.end());

    int num;
    int cnt=0; //동전 개수
    for(int i=0;i<coin.size();i++){
        if(K>=coin[i]) {
            num=K/coin[i];
            K-=coin[i]*num;
            cnt+=num;
        }
        if(K==0) break;
    }

    cout<<cnt<<"\n";

}