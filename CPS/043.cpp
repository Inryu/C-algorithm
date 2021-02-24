#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int a[1001],n;

//mid의 용량으로 곡을 녹화하는데 필요한 dvd개수
int Count(int size){

    int i,sum=0;
    int cnt;//dvd개수

    for(i=1;i<=n;i++){
        if(sum+a[i]>size){ //누적 가능? 불가능하면
            cnt++; //dvd추가
            sum=a[i]; //이 dvd는 a[i]로 초기화
        }
        else sum+=a[i]; //누적
    }

    return cnt;
}



int main(){

    int m,i,lt=1,rt=0,mid,res,max=-21470000;

    scanf("%d %d",&n,&m);

    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        rt=rt+a[i]; //곡의 총 합시간이 최대 범위
        if(a[i]>max) max=a[i]; //가장 긴 노래 
    }

    while(lt<=rt){
        mid=(lt+rt)/2; //이게 답이 되는지 확인해야함

        //mid로 가능 한지 m개의 레코드로!
        if(mid>=max&&Count(mid)<=m){
                //최소 용량은, 곡중 가장 긴 노래보다 커야 함

            res=mid; //일단 가능하니깐 답 저장, 추후 갱신
            rt=mid-1; //더 최소값 찾아보기
        }else{ //불가능하고, 용량이 큰쪽으로 가야됨
            lt=mid+1;
        }
    }

}