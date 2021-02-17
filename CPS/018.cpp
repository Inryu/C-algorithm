#include <stdio.h>
#include <iostream>


int main(){
    
    // freopen("input.txt","rt",stdin);


    int n,m,i,est,time=0,max=0;

    scanf("%d %d",&n,&m);

    //n : n초 동안의 측정치
    //m : 측정치 최대 허용 수치

    for(int i=0;i<n;i++){
        scanf("%d",&est);
        if(est>m) { //허용치를 넘으면
            time++;

            if(time>max){
                max=time;
            }
        }else { //허용치를 넘지 않으면
            time=0;//다시 초기화
        }
    }

    if(max==0){
        printf("-1\n");
    }else{
        printf("%d",max);
    }



}