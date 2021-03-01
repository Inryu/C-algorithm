#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int w,h,i,j;
    int tw,th; //영지 크기
    int max=-2147000, sum;

    scanf("%d %d",&h,&w);

    vector <vector<int>> a(h+1,vector<int>a(w+1)); //전체 땅
    vector <vector<int>> dy(h+1,vector<int>dy(w+1)); //다이나믹 배열!!


    //전체 땅의 오렌지 개수 받기
    for(int i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            scanf("%d",&a[i][j]); 

            //다이나믹 배열도 초기화!
            dy[i][j]=dy[i-1][j]+dy[i][j-1]-d[i-1][j-1]+a[i][j];
        }
    }


    //영지 받기
    scanf("%d %d",&th,&tw);

    for(i=1;i<=h-tw+1;i++){
        for(j=th;j<tw;j++){
            tmp=dy[i][j]-dy[i-n][j]-dy[i][j-m]+dy[i-n][j-m];
            if(tmp>max) max=tmp;

            //4중 for문으로 해결 가능하지만 이렇게 하면 timelimit에 걸림 -> 051 참고

        }
    }

    printf("%d\n",max);
    return 0;
}