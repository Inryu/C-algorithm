#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int numarr[100]; //있으면 1, 없으면 0 //일단 0으로 초기화


int main(){

    int s,n,i,j,idx;
    
    int num; //작업 번호를 읽을 것임.

    scanf("%d %d",&s,&n);
    vector<int> a(s);

    for(i=0;i<n;i++){
        scanf("%d",&num);

        //Cache Miss 
        if(numarr[num]==0){
            //모든 작업이 뒤로 밀리고
            //a[0]에  num이 위치

            numarr[a[s-1]]=0; //빠졌으니깐

            for(i=s-1;i>0;i--){
                a[i]=a[i-1];
            }
            a[0]=num;

            numarr[num]=1; //들어갔으니깐

        }


        //Cache Hit
        else{

            for(j=0;j<s;j++){
                if(a[j]==num){
                    idx=j; //hit 작업의 인덱스를 찾음
                    break;
                }
            }

            for(j=idx;j>0;j--){
                a[j]=a[j-1];
            }
            a[0]=num;     
	    }

    }

    for(i=0;i<s;i++){
        printf("%d ",a[i]);
    }

}

