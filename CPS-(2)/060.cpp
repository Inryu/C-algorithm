#include<stdio.h>
#include<vector>
#include<algorithm>
#include <stack>
using namespace std;

int n,ch[11];
int flag=0; //합이 서로 존재하는 경우가 존재하면

vector<int> a;

void DFS(int L){

    int i,sum0,sum1;
    if(flag==1) return;
    if(L==n){
        //ch[0]인것과 ch[1]인 것 따로 더해서 비교! flag로 두어야겠다.
        sum0=0;sum1=0;
        for(i=0;i<n;i++){
            if(ch[i]==0) sum0+=a[i];
            else sum1+=a[i];
        }
        if(sum0==sum1) {
            flag = 1;
        }
    }
    else{
        ch[L]=1;
        DFS(L+1);
        ch[L]=0;
        DFS(L+1);
    }

}

int main(){

    int i,x;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&x);
        a.push_back(x);
    }

    DFS(0); //첫번째 레벨부터!

    if(flag==1){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
}

