#include <stdio.h>

int digit_sum(int x){

    int sum=0;

    while(x>0){
        sum+=x%10; //마지막 자리
        x/=10; //마지막 자리 떼어내기
    }

    return sum;
}
int main(){


    int n,i,x,max=-2147000,sum,res;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&x);
        sum=digit_sum(x);  
        
        if(sum>max) {
            max=sum;
            res=x;
        }else if(sum==max){
            if(x>res) res=x;
        }
    }

    printf("%d",res);


    return 0;
}