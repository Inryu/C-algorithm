#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int caseNum=1;

    while(1){
        int L,P,V;
        int maxDays=0;
        cin>>L>>P>>V;
        if(L==0&&P==0&&V==0) break;

        maxDays+=(V/P)*L;

        if(V%P>L){
            maxDays+=L;
        }else
        {
            maxDays+=V%P;
        }

        cout<<"Case "<<caseNum++<<": "<<maxDays<<"\n";
    }

    return 0;

}