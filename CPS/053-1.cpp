#include<stdio.h>
#include<vector>
#include<algorithm>
#include <stack>
using namespace std;

//스택 헤더파일 사용하기

//k진수 출력
int main(){

    int n,k;
    char str[20]="0123456789ABCDEF";//16진수 출력하기 위해
    stack<int> s;

    scanf("%d %d",&n,&k);
    
    //push
    while(n>0){
        s.push(n%k);
        n/=k;
    }

    //pop
    while(!s.empty()){
        //s.empty : 스택이 비어있으면 참, 비어있지 않으면 거짓
        printf("%c",str[s.top()]);
        s.pop();
    }

    return 0; 

}