#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int k,l,i,pos1=0,pos2=0,pos3=0;

    scanf("%d",&k);
    vector<int> a1(k);

    for(i=0;i<k;i++){
        scanf("%d",&a1[i]);
    }

    scanf("%d",&l);
    vector<int> a2(l);
    vector<int> a3(k+l);

    for(i=0;i<l;i++){
        scanf("%d",&a2[i]);
    }

    while(pos1<k&&pos2<l){

        if(a1[pos1]>a2[pos2]){
            a3[pos3++]=a2[pos2++];

        }else{
            a3[pos3++]=a1[pos1++];
        }
    }

    //1. a1이 남은 경우
    while(pos1<k){
        a3[pos3++]=a1[pos1++];
    }

    //2. a2가 남은 경우
    while(pos2<l){
        a3[pos3++]=a2[pos2++];
    }


    for(i=0;i<pos3;i++){
        printf("%d ",a3[i]);
    }


}