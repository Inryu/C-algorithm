#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,i,key,lt=0,rt,mid;
    scnaf("%d %d",&n,&key);
    vector<int> a(n);

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    //벡터 자동 정렬
    sort(a.begin(),a.end()); //default : 오름차순

    rt=n-1; //배열의 끝 인덱스

    while(lt<=rt){
        mid=(lt+rt)/2;

        if(a[mid]==key){
            printf("%d",mid+1);
        }else if(a[mid]>key){
            rt=mid-1;
        }else{
            lt=mid+1;
        }
    }



}