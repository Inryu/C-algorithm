#include <iostream>
#include <algorithm>
using namespace std;

int numbers[14]; //입력
int res[6]; //만들어지는 조합
int k;

//조합 구현
void dfs(int startIdx, int level){

    //6개를 다 골랐을 경우
    if(level==6){
        for(int i=0;i<6;i++){
            cout<<res[i]<<" "; //조합 출력
        }
        cout<<"\n";
        return;
    }

    //주어진 number배열을 start부터~k-1 인덱스까지 탐색한다.
    for(int i=startIdx;i<k;i++){
        res[level]=numbers[i];
        dfs(i+1, level+1);
    }

}

int main(){

    while(true){
        cin>>k;
        if(k==0) exit(0);

        for(int i=0;i<k;i++){
           cin>>numbers[i];
        }

        dfs(0,0);
        cout<<"\n";
    }

}
