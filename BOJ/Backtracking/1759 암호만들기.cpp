#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int L,C;
vector<char> candidate;

//최소 한 개의 모음, 최소 두 개의 자음
bool check(string pw){
    int conCnt=0; //자음
    int vowelCnt=0; //모음

    for(int i=0;i<pw.size();i++){
        if(pw[i]=='a'||pw[i]=='e'||pw[i]=='i'||pw[i]=='o'||pw[i]=='u'){
            vowelCnt++;
        }else conCnt++;
    }

    if(vowelCnt>=1&&conCnt>=2) return true;
    else return false;
}

void dfs(int idx, string pw){

    if(pw.size()==L){
        if(check(pw)) {
            cout << pw<<"\n";
        }
        return;
    }
    if(idx==C) return;

    dfs(idx+1,pw+candidate[idx]);
    dfs(idx+1,pw);

}

int main(){
    cin>>L>>C;

    for(int i=0;i<C;i++){
        char a;
        cin>>a;

        candidate.push_back(a);
    }

  // 👀 정렬
    sort(candidate.begin(), candidate.end());
    dfs(0,"");
}
