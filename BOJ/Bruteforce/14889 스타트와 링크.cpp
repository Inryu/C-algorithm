#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 2147000000

int minVal=MAX;
int N;
int map[21][21];
int res[20]; //스타트,링크 조합 1일 때 스타트

/* 능력치 차이 구하기*/
void computePower(){
    vector<int> start;
    vector<int> link;

    // 1인 것이 스타트팀!
    for(int i=1;i<=N;i++){
        if(res[i]==1) start.push_back(i);
        else link.push_back(i);
    }

    int startScore=0;
    int linkScore=0;

    for(int i=0;i<N/2;i++){
        for(int j=0;j<N/2;j++){
            if(i==j) continue;
            startScore+=map[start[i]][start[j]];
            linkScore+=map[link[i]][link[j]];
        }
    }

    int diff=abs(startScore-linkScore);
    minVal=min(diff,minVal);
}

/* N/2명의 조합 구하기.*/
void selectStart(int start,int level){
    if(level==N/2){
        // N/2명 골랐을 때 능력치 차이를 구한다.
        computePower();
        return;
    }

    for(int i=start;i<=N;i++){
        if(!res[i]){
            res[i]=1; //1로 설정한 것이 스타트팀.
            selectStart(i+1, level+1);
            res[i]=0;
        }

    }
}

int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>map[i][j];
        }
    }

    //1. N/2 명의 스타트팀을 고른다. (조합)
    selectStart(1,0);
        //2. N/2명 골랐을 때 능력치 차이를 구한다.

    //능력치 차이의 최소값
    cout<<minVal<<"\n";
    return 0;
}