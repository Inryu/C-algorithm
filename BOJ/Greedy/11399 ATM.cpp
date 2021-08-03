#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    vector <int> p;
    int res=0;

    cin>>N;
    for(int i=0;i<N;i++){
        int val; cin>>val;
        p.push_back(val);
    }
    sort(p.begin(),p.end());

    for(int i=0;i<p.size();i++){
        int sum=0;
        for(int j=0;j<i+1;j++){
            sum+=p[j];
        }
        res+=sum;
    }

    cout<<res<<"\n";
}