#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<pair <int,int>> a;
vector <int> ch;
int n,maxval=-2147000;


void DFS(int v,int day,int val){
    int i;

    if(day>=7){
        if(val>maxval) maxval=val;
    }
    else{

        for(i=v+1;i<n;i++){
            if (i>=v+a[v].first&&ch[i] == 0) {
                ch[i]=1;
                DFS(i,day+a[i].first,val+a[i].second);
                ch[i]=0;
            }
        }
    }
}

int main(){

    int t,p,i;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d %d",&t,&p);
        a.push_back(make_pair(t,p));
        ch.push_back(0); //체크 배열
    }

    ch[0]==1;
    DFS(0,a[0].first,a[0].second);
    //DFS(0,4,20)

    printf("%d",maxval);
}


