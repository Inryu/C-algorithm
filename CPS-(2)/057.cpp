//
// Created by 신인류 on 2021/03/03.
//

#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;

void binary(int x){
    if(x==0) return;
    else{
        binary(x/2);
        printf("%d",x%2);
    }

}

int main(){

    int n;
    scanf("%d",&n);

    binary(n);
}


