#include <iostream>
using namespace std;

int res;

void DFS(int left , int right){

    if(left==0) res++; //left를 다 쓰면 나머지 right를 쓰면 됨

    //left가 더 많이 남으면
    else if(left<right){

        //둘 중 뭐를 쓰든 상관 없다.
        DFS(left-1,right);
        DFS(left,right-1);
    }

    //똑같으면 left써야됨
    else if(left==right){
        DFS(left-1,right);
    }

}

int main() {

    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    DFS(n,n); //왼쪽괄호 n개, 오른쪽 괄호 n개를 다 써버려야 됨 (인자 : 남은 괄호 수)
    cout<<res;

    return 0;
}