#include <iostream>
#include <cstring>
using namespace std;

int N;
int board[15]; //각 행에 어떤 열에 퀸이 놓인지.
int res;

bool promising(int r, int c){
    for(int i=0;i<r;i++){
        if(board[i]==c||abs(c-board[i])==r-i)return false; //위쪽 행 또는 대각선에 있을 경우}

    }
    return true;
}

void dfs(int row){
    if(row==N){
        res++;
        return;
    }
    //모든 열을 본ㄷㅏ
    for(int i=0;i<N;i++){
        if(promising(row,i)){ //row행 i열에 놓을 수 있는지
            board[row]=i;
            dfs(row+1); //놓았으면 다음행 봄
            board[row]=-1;
        }
    }
}

int main(){
    memset(board,-1,sizeof(board)); //어떤 열에 놓을지 들어가므로, 0 이상의 수는 안 됨!
    cin>>N;
    dfs(0); //0행부터 시작.
    cout<<res<<"\n";
}
