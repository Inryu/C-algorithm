#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[10][10];
vector<pair<int,int>> blank;
bool sudoku(int level){
    // 스도쿠 완성
    if(level==blank.size()){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<map[i][j]<<" ";
            }
            cout<<"\n";
        }
        return true;
    }

    int r=blank[level].first;
    int c=blank[level].second;

    int candidate[10]={0,};

    //가로, 세로
    for(int i=0;i<9;i++){
        if(map[r][i]) candidate[map[r][i]]=1;
        if(map[i][c]) candidate[map[i][c]]=1;
    }

    //9칸.
    int restR=r%3;
    int restC=c%3;
    for(int i=r-restR;i<r-restR+3;i++){
        for(int j=c-restC;j<c-restC+3;j++){
            if(map[i][j]) {
                candidate[map[i][j]]=1;
            }
        }
    }

    //후보!
    for(int i=1;i<=9;i++){
        if(candidate[i]==0){
            map[r][c]=i;
            bool check=sudoku(level+1);
            if(check) return true;
            map[r][c]=0; //백트래킹. //레벨까지 못 갈 수도 있기 때문에 여러 경로
        }
    }

    return false;
}

int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>map[i][j];
            if(map[i][j]==0){
                blank.push_back({i,j});
            }
        }
    }
    sudoku(0);
}