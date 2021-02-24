#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n;

int Count(int len,vector<int> a){
    int i,cnt=1, pos=x[1];

    for(i=2;i<=n;i++){
        if(x[i]-pos>=len){
            cnt++; // 말 하나 추가!
            pos=x[i];
        }
    }

    return cnt; //가능한 말 개수

}

int main(){
    int c,i,lt=1,rt,mid,max=-2147000,res;

    scanf("%d %d",&n,&c);
    vector<int> a(n+1); //마구간 좌표 //인덱스 1부터 시작
    
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    }
    
    //오름차순 정렬
    sort(a.begin(),a.end());

    rt=a[n]; //끝 값

    while(lt<=rt){
        mid=(lt+rt)/2; //가장 가까운 말의 거리
        if(Count(mid,a)>=c){ // 그 거리로 말 c마리 배치하는 거 가능?
            //ㅇㅇ가능 //그럼 더 최대값 찾기
            res=mid; //답 갱신
            lt=mid+1;
        }else{
            //ㄴㄴ 불가능 
            rt=mid-1;
        }
    }
    printf("%d\n",res);
}