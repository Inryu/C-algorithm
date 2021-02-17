#include <stdio.h>

int main(){

    int n,num,ans,i,j,sum=0;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d %d",&num,&ans);
        sum=0;

        for(j=1;j<=num;j++){
            sum+=j;
        }

        if(ans==sum){
            printf("YES\n");
        }else printf("NO\n");
    }
    
}