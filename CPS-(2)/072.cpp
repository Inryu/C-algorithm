#include<stdio.h>
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    int n,k,i;
    queue <int> Q;
    scanf("%d %d",&n,&k);
    //일단 왕자를 다 넣어두기
    for(i=1;i<=n;i++){
        Q.push(i);
    }
    while(!Q.empty()){

        for(i=1;i<k;i++){ //k번을 외치기 전까지는 뒤에 push한 다음에 앞에껀 pop!
            Q.push(Q.front());
            Q.pop();
        }

        //k번을 외치는 왕자
        Q.pop(); //그냥 팝

        if(Q.size()==1){
            printf("%d\n",Q.front());
            Q.pop(); //마지막 왕자 팝 시키고 while 문 종료
        }
    }

}