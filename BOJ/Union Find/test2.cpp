#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int MAX=2000+1;
int N,k;
int res[21];
int minVal=2147000000;

struct Loc {
    int r;
    int c;
    int color;
    Loc(int a, int b, int c){
        r=a;
        c=b;
        color=c;
    }
};

vector<Loc> point;

bool checkRes(){
    map<int,int> m; //컬러,개수

    //조합, k개 고른 거
    for(int i=0;i<k;i++){
        m[point[res[i]].color]++;
    }

    for(int i=1;i<=k;i++){
        if(m.count(i)) continue;
        else return false; //하나라도 없으면
    }

    return true;
}
//조합 구현
void dfs(int startIdx, int level){

    //k개를 다 골랐을 경우
    if(level==k){
        //모든 점이 골고루 있으면
        if(checkRes()){

        }
        return;
    }

    //주어진 number배열을 start부터~k-1 인덱스까지 탐색한다.
    for(int i=startIdx;i<=N;i++){
        res[level]=i;
        dfs(i+1, level+1);
    }

}

int main(int argc, char** argv){
    cin>>N>>k;


    for(int i=0;i<N;i++){
        int r,c,color;
        cin>>r>>c>>color;
        point.push_back(Loc(r,c,color));
    }

    //N개의 점 중 k개의 조합은 뽑아야 함.
    dfs(0,0);
    cout<<minVal<<"\n";

    return 0;
}