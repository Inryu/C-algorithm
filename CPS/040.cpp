#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n,m,i,p1=0,p2=0,p3=0;
    
    scanf("%d",&n);
    vector<int> a(n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    sort(a.begin(),a.end()); //자동 정렬
 

    scanf("%d",&m);
    vector<int> b(m),c(n+m);
    for(i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    
    sort(b.begin(),b.end()); //자동 정렬


    while(p1<n&&p2<m){
        if(a[p1]==b[p2]){
            c[p3++]=a[p1++];
            p2++; //얘도 증가 시켜줘야 함
        }
        else if(a[p1]<b[p2]) p1++; //작은 쪽 증가
        else p2++;
    }

    for(i=0;i<p3;i++){
        printf("%d ",c[i]);
    }






}