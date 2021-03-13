#include <iostream>
using namespace std;

int dy[101]; //메모이제이션을 위한 배열


int DFS(int n){

    if(dy[n]!=0){ //이미 구해놓았다면(메모이제이션)
        return dy[n]; //가지 커트!!
    }

    if(n==1 || n==2 ){ //1m 또는 2m 일 때 직관적으로 구한 거 이
        return n;
    }

    else{
        return dy[n]=DFS(n-1)+DFS(n-2); //메모이제이션 하면서 재귀적으로 return
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    cout<<DFS(n);

    return 0;

}