#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
void D(int x){
    if(x>7) return;
    else{

        //🌟printf의 위치에 따라 전위,중위,후위
        printf("%d ", x);
        D(x*2);
        D(x*2+1);
    }
}
int main(){
    D(1);
    return 0;
}