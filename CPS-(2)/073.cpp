
//😇 우선순위 큐
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    int a;
    priority_queue<int> pQ;

    while(true){
        scanf("%d",&a);

        //-1 입력
        if(a==-1) break;

        //0 입력
        if(a==0) {
            if (pQ.empty()) printf("-1\n");
            else {
                printf("%d\n", pQ.top()); //최대값 출력
                pQ.pop();
            }
        }

        //자연수 입력
        else{
            pQ.push(a);
        }
    }
}


