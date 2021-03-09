#include<stdio.h>
#include<vector>
#include<algorithm>
#include <stack>
using namespace std;

vector <pair<int,int>> home;
vector <pair<int,int>> pizza;

int n,m;

int main(){

    int i,j,num;
    scanf("%d %d",&n,&m);


    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&num);
            if(num==1){ //집
                home.push_back(make_pair(i,j)); //(x좌표,y좌표)
            }else if(num==2) { //피자집
                pizza.push_back(make_pair(i, j)); //(x좌표,y좌표)
            }
        }
    }



}

