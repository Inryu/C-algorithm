#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;


void recur(int x){

    //🌟재귀 함수는 종료 지점을 지정해주지 않으면 무한루프에 빠짐
    if(x==0) { //내가 원하느 종료지점을 지정!
        return;
    }else{
        recur(x-1);
        printf("%d ", x);
    }

}

int main(){
    int n;

    scanf("%d",&n);
    recur(n); //재귀 호출


    return 0;
}