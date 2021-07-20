#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

bool isValid(string val){

    int len=val.size();

    for(int i=1;i<=len/2;i++){ //비교할 길이!
        string s1=val.substr(len-i,i);
        string s2=val.substr(len-i*2,i);

        if(s1==s2) return false;
    }
    return true;
}

void dfs(int len,string val){

    if(!isValid(val)) return;

    if(len==N){
        cout<<val<<"\n";
        exit(0); //첫번째 나오는 거 출력하고 종료!
    }

    dfs(len+1,val+'1');
    dfs(len+1,val+'2');
    dfs(len+1,val+'3');
}

int main(){
    cin>>N;
    dfs(0,"");
}
