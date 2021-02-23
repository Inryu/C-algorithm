#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int a, b=1, cnt=0, tmp, i;
    scanf("%d",&a);
    tmp=a; //원래 숫자는 수식으로 표현해야 하므로 저장!

    a--; //1과 2를 빼줘야 하므로. 일단 1을 빼줌

    while(a>0){
        b++; //b=2 //몇개짜리 연속으로 할 건지도 여기에 속함!
        a-=b; //2까지 빼줌 

        if(a%b==0){
            for(i=1;i<b;i++){// 뒤에 +가 붙는 것만 출력
                printf("%d +",(a/b)+i); //i에 몫을 분배!

            }
            printf("%d = %d\n",(a/b)+i,tmp);
            cnt++;
        }
    }

    printf("%d\n",cnt);
    return 0;




}