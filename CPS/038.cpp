#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){  
    int n, i, j, pos;

    scanf("%d",&n);
    vector<int> is(n+1), os(n+1);

    for(i=1;i<=n+1;i++){
        scanf("%d",&is[i]);
    }

    for(i=n;i>=1;i--){
        pos=i; //처음 위치
        for(j=1;j<=is[i];j++){ //앞에 있는 자기보다 큰 숫자 개수만큼 //앞 수를 땡겨줘야 함 
            os[pos]=os[pos+1];
            pos++;
        }

        os[pos]=i;
    }

    for(i=1;i<=n;i++){
        printf("%d ",os[i]);
    }

}