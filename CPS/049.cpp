#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n,i,j,tmp,sum=0;

    scanf("%d",&n);
    vector <int> frt(n+1); //정면
    vector <int> rgt(n+1); //우측
    vector <vector<int>> a(n+1,vector<int>(n+1)); //최종

    for(i=1;i<=n;i++){
        scanf("%d",&frt[i]);
    }

    for(i=1;i<=n;i++){
        scanf("%d",&rgt[i]);
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            a[i][j]=frt[j]; //정면 배열로 초기화

            //오른쪽 배열과 비교 
            //정면-오른쪽이 >0이면 그 차만큼 줄이기. (블록의 최대 개수니깐)
            tmp=a[i][j]-rgt[i];
            if(tmp>0){
                a[i][j]-=tmp;
            } 

            sum+=a[i][j];    
        
        }
    }

    printf("%d\n",sum);


}