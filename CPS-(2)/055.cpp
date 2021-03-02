#include<stdio.h>
#include<vector>
#include<algorithm>
#include <stack>
using namespace std;

int main(){

    int n,i,pos=1,order=1;
    stack <int> s;
    s.push(-1);

    scanf("%d",&n);
    vector<int> a(n+1);
    vector<char> str;

    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    while(order<=n){

        if(s.top()==order){
            s.pop();
            str.push_back('O');
            order++;
        }

        else {

            if(pos>n) break; //뺄 수는 없는데 더 넣을 것도 없음

            s.push(a[pos]);
            str.push_back('P');
            pos++;
        }
    }

    s.pop(); //처음에 넣어놓은 거
    if(!s.empty()) printf("impossible");
    else{
        for(i=0;i<str.size();i++){
            printf("%c",str[i]);
        }
    }

}

