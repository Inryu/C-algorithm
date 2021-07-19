//
// Created by 신인류 on 2021/07/19.
//

#include <iostream>

using namespace std;

int N,S,cnt=0;
int arr[20];

void dfs(int idx, int sum){

    if(idx==N) return;
    if(sum+arr[idx]==S) cnt++;

    dfs(idx+1, sum);
    dfs(idx+1, sum+arr[idx]);
}

int main(){
    //input
    cin>>N>>S;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    dfs(0,0);

    cout<<cnt<<"\n";
}
