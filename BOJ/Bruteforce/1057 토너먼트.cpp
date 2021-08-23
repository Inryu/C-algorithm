#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,a,b;

    cin>>N>>a>>b;

    int round=0;
    while(N){
        round++;

        if(abs(a-b)==1){
            if(a<b){
                if(a%2!=0) break;
            }else{
                if(b%2!=0) break;
            }
        }
        a=(a+1)/2;
        b=(b+1)/2;
        N/=2;
    }

    if(!N) cout<<-1<<"\n";

    cout<<round<<"\n";
}