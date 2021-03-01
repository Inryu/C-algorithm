#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int a[9]

int main(){

    int i,j,sum,avg,min=2147000,pos;

    for(i=0;i<9;i++){

        sum=0;
        //각 행을 따로
        for(j=0;j<9;j++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        
        //평균 출력
        //소수점 첫 째자리에서 반올림

        avg=(sum/9.0)+0.5; //반올림

        printf("%d ",sum/avg);

        //가장 가까운 값 찾기
        min=2147000;
        for(j=0;j<9;j++){
            if(abs(avg-a[i])<min){
                min=avg-a[i];
                pos=i;
            }else if(abs(avg-a[i]==min)){ //같은 경우 둘 중 큰 값
                if(a[i]>a[pos]) pos=i;
            }
        }

        prinf("%d\n",a[pos]);

    }




}