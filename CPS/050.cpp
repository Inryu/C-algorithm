#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int w,h,i,j;
    int tw,th; //영지 크기
    int max=-2147000, sum;

    scanf("%d %d",&h,&w);

    vector <vector<int>> a(h+2,vector<int>a(w+2)); //전체 땅


    //전체 땅의 오렌지 개수 받기
    for(int i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            scanf("%d",&a[i][j]); 
        }
    }

    scanf("%d %d",&th,&tw);

    //최대 넓이..

    for(i=1;i<=h-tw+1;i++){
        for(j=1;j<=w-tw+1;j++){

        }
    }









}