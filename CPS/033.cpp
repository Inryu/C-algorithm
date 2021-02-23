
#include <stdio.h>
#include <vector>
#include<algorithm> 
using namespace std;

int main(){

    int n,a[100],i,j,idx,tmp;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++){
        idx=i;
        for(j=i+1;j<n;j++){ // 이 중 최대값 찾기
            if(a[j]>=a[idx]) idx=j;
        }
        tmp=a[i];
        a[i]=a[idx];
        a[idx]=tmp;
    }

    int cnt=1;

    for(i=1;i<n;i++){

        if(a[i]!=a[i-1]) cnt++;
        if(cnt==3) {
            printf("%d",a[i]);
            break;
        }

    }

}