#include <stdio.h>
#include <vector>
#include<algorithm> 
using namespace std;

int main(){

    int n,a[100],i,j,tmp;

    int idx;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }


    for(i=0;i<n;i++){

        int flag=0;
        for(j=0+i;j<n;j++){
            if(a[j]<0) {idx=j; flag=1; break;} //제일 앞에 있는 음수값 찾기
        }
        if(flag==0) break; //음수 찾지 못했다면 break;

        //계속 앞으로 밀기
        for(j=idx;j>0+i;j--){
            tmp=a[j];
            a[j]=a[j-1];
            a[j-1]=tmp;
        }

    }

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }


}