#include <iostream>
#include <vector>
using namespace std;

int check(int n){

    vector<int> arr;

    while(n){
        arr.push_back(n%10);
        n/=10;
    }

    bool flag=false;
    if(arr.size()<3) return 1;
    else {
        int sub=(arr[0]-arr[1]);
        for (int i = 1; i < arr.size()-1; i++) {
            if((arr[i]-arr[i+1])!=sub){
                flag=true;
            }
        }
    }

    if(flag) return 0;
    else return 1;
}

int main(){
    int N;
    int cnt=0;
    cin>>N;

    for(int i=1;i<=N;i++){
        cnt+=check(i);
    }

    cout<<cnt<<"\n";

}