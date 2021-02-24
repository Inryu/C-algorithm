#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    //n개 작업 (1~N 인덱스)
    //1초씩, 마지막이후 다시 1번작업
    // 처리가 끝나면 스케쥴에서 사라짐

    //k초 후 정전, 몇 번 작업부터 다시 시작해야 하는지?

    //-> K초 동안 작업이 어디까지 진행됐는지.

    int n,k,i,pos=0,time=0,total=0;
    
    scanf("%d",&n);
    vector<int> work(n+1); //인덱스 1~N으로 

    for(i=1;i<=n;i++){
        scanf("%d",&work[i]); 
        total+=work[i];
    }

    scanf("%d",&k);

    if(total<=k){//모든 작업을 다 해도 정전되지 않는 경우
    //k초 후니깐 total번의 작업이 완료된 후! 같은 것도 포함
        printf("-1\n");
        return 0;
    }

    while(1){ 
        pos++;

        if(pos>n) pos=1; //마지막 번호 인덱스를 넘어갔다면 다시 1로

        if(work[pos]!=0){ //작업이 끝나지 않은 것만
            work[pos]--;
            time++;

            if(time==k) break; //정전
        }

    }

    //정전 된 후 다음작업도 확인을 해줘야함
    while(1){
        pos++; //마지막 작업 바로 다음 작업
        if(pos>n) pos=1; //마지막 번호 인덱스를 넘어갔다면 다시 1로

        if(work[pos]!=0) break; //살아 있는 작업을 찾고
    }

    printf("%d\n",pos); //다음 작업

}