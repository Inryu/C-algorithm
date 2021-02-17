#include <stdio.h>

int stu[100];

int main(){

    int n,i,max=-2147000,cnt=0;

    //자신의 뒷 사람 모두를 시청방해하는 학생 수 :
    // 뒤에서 부터 보면서 새로운 max값이 등장하면 무조건 분노유발자.

    //학생 들의 숫자를 배열에 저장
    // 뒤쪽부터 max를 두고, for문으로 앞쪽 배열로 오면서 확인
    //max보다 큰 애가 나오면 ! 무조건 분노유발자 

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&stu[i]);
    }

    max=stu[n-1]; //맨 마지막 사람으로 초기화

    for(i=n-2;i>=0;i--){
        if(stu[i]>max) {
             max=stu[i];
             cnt++;
        } 
    }

    printf("%d",cnt); 

}