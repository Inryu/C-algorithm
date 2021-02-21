#include <stdio.h>
#include <vector>
#include<algorithm> 
using namespace std;

int main(){
    
    int n,i,j,tmp,num,cnt2=0,cnt5=0;

    scanf("%d",&n);

    //시간 초과  
    // for(i=n;i>1;i--){
    //     n=n*(i-1);
    // }

    // while(n>0){
    //     num=n%10;
    //     printf("num=%d\n",num);
    //     if(num==0) cnt++;
    //     else break;
    //     n=n/10;
    // }
    // printf("%d",cnt);

    

    //솔루션?
    
    //소인수 분해
    for(i=2;i<=n;i++){
        tmp=i;
        j=2;
        while(1){
            if(tmp%j==0){
                if(j==2) cnt2++;
                else if(j==5) cnt5++;
                tmp=tmp/j;
            }
            else j++;

            if(tmp==1) break;
        }
    }

    if(cnt2<cnt5) printf("%d\n",cnt2);
    else printf("%d\n",cnt5);

}