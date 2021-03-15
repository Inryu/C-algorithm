#include <iostream>
#include <algorithm>
using namespace std;
int arr[21][21];
int dy[21][21]; //메모이제이션
int n;

int DFS(int i, int j){

    //메모이제이션
    if(dy[i][j]!=0){
        return dy[i][j];
    }

    //직관적으로 구한 것
    if(i==0&&j==0){
        return arr[0][0];
    }else{

        //가장자리 고려
        if(i==0){ //0행일 때, 왼쪽에서만 올 수 있음
            return dy[i][j]=DFS(i,j-1)+arr[i][j];
        }
        else if(j==0){ //0열일 때, 위쪽에서만 올 수 있음
            return dy[i][j]=DFS(i-1,j)+arr[i][j];

        }

        //가장자리가 아닐 때
        else{
            return dy[i][j]=min(DFS(i-1,j),DFS(i,j-1))+arr[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    //🌟목적지에서 시작
    cout<<DFS(n-1,n-1);
    return 0;
}