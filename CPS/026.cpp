#include <stdio.h>
#include <vector>
#include<algorithm> 
using namespace std;

int main(){

    //앞으로 얻을 수 있는 최선의 등수

    //큰 값이 더 좋은 실력

    int n,i,j;

    scanf("%d",&n);
    vector<int> a(n);
    vector<int> b(n);   //앞설 가능성이 있는 사람 수 


    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }



    for(i=0;i<n;i++){
        for(j=i;j>=0;j--){
            if(a[i]>a[j]){
                b[i]++;
            }
        }
    }

    for(i=0;i<n;i++){
        printf("%d ",((i+1)-b[i])); // 원래 등수 - 앞설 가능성이 있는 사람 수
    }




}