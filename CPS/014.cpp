#include <stdio.h>//014 : 뒤집은 소수

int reverse(int x){
    int res=0;
    while(x>0){
        //맨 뒤에 자리를 빼고, 기존 숫자에 *10을 해서 더해 주기
        res=res*10+(x%10);
        x/=10; // 맨 뒤에 자리 삭제
    }
    return res;
}

bool isPrime(int x){
    int i;

    //1은 소수가 아님
    if(x==1) return false;

    bool flag=true;

    for(i=2;i<x;i++){ //2부터 자기자신 전 까지!
        if(x%i==0){
            flag=false;
        }
    }

    return flag;
}


int main(){

    int n,i,x,rev;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&x);
        rev=reverse(x);
        if(isPrime(rev)){
            printf("%d ",rev);
        }
    }

}