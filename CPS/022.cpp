#include <stdio.h>
#include <vector>

//🌟온도의 최대값
int main(){

    int n,k,i, sum=0,max;

    scanf("%d %d",&n,&k);
    std::vector<int> a(n); //배열 동적 생성

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    //첫 구간의 값 구하기!! (k날짜 만큼)
    for(i=0;i<k;i++){
        sum+=a[i];
    }

    max=sum; //첫 구간으로 max 초기화

    //이후 한개 씩 밀면서
    for(i=k;i<n;i++){
        sum=sum+a[i]-a[i-k];

        if(sum>max) max=sum; //max값 갱신
    }
    printf("%d\n",max);

    return 0;
} 