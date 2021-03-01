#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int stack[100], top=-1;

void push(int x){
    stack[++top]=x;
}

int pop(){
    return stack[top--];
}

//k진수 출력
int main(){

    int n,k;
    char str[20]="0123456789ABCDEF";//16진수 출력하기 위해

    scanf("%d %d",&n,&k);
    
    //push
    while(n>0){
        push(n%k);
        n/=k;
    }

    //pop
    while(top!=-1){
        printf("%c",str[pop()]);
    }

    return 0; 

}