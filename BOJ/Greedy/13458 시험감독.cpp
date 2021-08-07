#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int N, B, C;
    vector<int> A;

    cin>>N;
    for(int i=0;i<N;i++){
        int val; cin>>val;
        A.push_back(val);
    }
    cin>>B>>C;

    long long cnt=0;

    for(int i=0;i<N;i++){
        if(B>=A[i]) cnt++;
        else{
            int num=(A[i]-B)/C;
            if((A[i]-B)%C>0) num++;
            cnt=cnt+1+num;
        }
    }
    cout<<cnt<<"\n";

}