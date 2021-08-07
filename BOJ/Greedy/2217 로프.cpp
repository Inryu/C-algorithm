#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
    int N;
    vector <int> weight;

    cin>>N;

    for(int i=0;i<N;i++){
        int val;
        cin>>val;
        weight.push_back(val);
    }

    sort(weight.begin(),weight.end());
    reverse(weight.begin(),weight.end()); //내림차순

    int w=0; int k=0; int max=-2147000000;
    for(int i=0;i<N;i++){
        k++;
        w=weight[i]*k;

        if(w>max) max=w;
    }
    cout<<max<<"\n";
}
