#include <stdio.h>
#include <vector>

int main(){
    //내 코드
    int n,i,cnt=1,max=0;

    scanf("%d",&n);

    std:: vector<int> a(n);

    //배열 첫 값은 읽어놓기
    scanf("%d",&a[0]);

    for(i=1;i<n;i++){
        scanf("%d",&a[i]);

        if(a[i]>=a[i-1]){
            cnt++;
            if(cnt>max) max=cnt;
        }else{
            cnt=1;
        }
    }

    printf("%d",max);

    return 0;
}