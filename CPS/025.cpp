#include <stdio.h>
#include <vector>
#include<algorithm> 
using namespace std;

//석차 구하기 (브루트포스)
int main(){

    int n,i,j;
    scanf("%d",&n);

    vector<int> a(n); // n크기의 배열 생성 점수 읽기 용
    vector<int> b(n,1); // n크기의 1초 로기화된 배열 생성 : 등수 저장 용

    //먼저 점수를 다 읽음
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    //2중 포문을 돌면서,원소 하나 고정해두고(i) j랑 비교.. 결국 자기보다 더 큰 점수를 찾는 만큼 등수를 ++;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i]<a[j]){
                b[i]++; 
            }
        }
    }

    //등수 출력
    for(i=0;i<n;i++){
        printf("%d ",b[i]);
    }
}
