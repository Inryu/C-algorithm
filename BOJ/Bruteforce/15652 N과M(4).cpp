#include <iostream>
using namespace std;

int N,M;
int res[20];

/*
 * 같은 수를 여러 번 골라도 되지만 (visited 사용 x), 오름차순으로!
 */
void dfs(int start,int level){
    if(level==M){
        for(int j=0;j<level;j++){
            cout<<res[j]<<" ";
        }
        cout<<"\n";
        return;
    }

    // ✨ 오름차순으로만 가능!
    for (int i = 1; i <= N; i++) {
            if(i>=start) {
                res[level] = i;
                dfs(i, level + 1);
            }
    }

}

int main(){
    cin>>N>>M;
    dfs(1,0);
}