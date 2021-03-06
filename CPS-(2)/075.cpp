#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

struct Data{
    int money;
    int when;
    Data(int a, int b){
        money=a;
        when=b;
    }
    bool operator<(const Data &b)const{
        return when>b.when;
    }
};


int main(){
    int n, i, j, a, b, res=0, max=-2147000000;

    vector<Data> T;
    priority_queue<int> pQ;
    scanf("%d", &n);

    for(i=1; i<=n; i++){
        scanf("%d %d", &a, &b);
        T.push_back(Data(a, b));
        if(b>max) //최대 일수 찾기
            max=b;
    }
    sort(T.begin(), T.end()); //정렬
    j=0;

    for(i=max; i>=1; i--){ //최대 일수부터
        for( ; j<n; j++){
            if(T[j].when<i) break;
            pQ.push(T[j].money);
        }
        if(!pQ.empty()){
            res+=pQ.top();
            pQ.pop();
        }
    }
    printf("%d\n",res);
    return 0;
}
