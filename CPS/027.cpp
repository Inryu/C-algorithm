#include <stdio.h>
#include <vector>
#include<algorithm> 
using namespace std;

int main(){
    int i,j,n,tmp;

    scanf("%d",&n);
    vector<int> ch(n+1); //체크 배열
    //소인수 분해 했을 때 n보다 큰 숫자는 나오지 않음

    //1~n까지의 수 소인수 분해
    for(i=2;i<=n;i++){
        tmp=i; //i를 분해해야 하니깐 저장해두기

        j=2; //소인수 분해 //2부터 나눔
        
        while(1){

            if(tmp%j==0){ //j로 나눠 떨어진다면
                tmp=tmp/j;
                ch[j]++; //j는 소인수다!
            }
            else{
                j++;
            }
            if(tmp==1) break;
        }


    }

    printf("%d! = ",n);

    for(i=2;i<=n;i++){
        if(ch[i]!=0) printf("%d",ch[i]); //인수로 체크된 것만 출력하기
    }


}