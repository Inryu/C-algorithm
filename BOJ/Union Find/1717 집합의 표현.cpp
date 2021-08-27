#include <iostream>
using namespace std;
#define MAX 1000000+1
int n,m;
int unf[MAX]; //unf[i] : i의 root

//부모 노드 찾기!
int Find(int v){
    if(unf[v]==v) return v; //자기 자신이 최상위
    else return unf[v]=Find(unf[v]); //최상위 노드를 찾음
}

void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    //부모노드가 다르면 한쪽에 연결
    if(a!=b) unf[a]=b;
}
int op,a,b;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++) unf[i]=i;
    for(int i=0;i<m;i++){
        cin>>op>>a>>b;
        if(op==0){
            Union(a,b);
        }
        else if(op==1){
            if(Find(a)==Find(b)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}