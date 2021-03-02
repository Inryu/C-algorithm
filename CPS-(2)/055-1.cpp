#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;
int main(){

    stack<int> s;
    int i, j=1, n, m;
    scanf("%d", &n);
    vector<char> str;

    for(i=1; i<=n; i++){
        scanf("%d", &m); //하나씩 읽고
        s.push(m); //일단 무조건 스택에 넣음
        str.push_back('P');

        //pop할 것 있는지
        while(1){
            if(s.empty()) break; //더이상 pop 불가능
            if(j==s.top()){
                s.pop();
                j++;
                str.push_back('O');
            }
            else break;
        }
    }
    if(!s.empty()) printf("impossible\n");
    else{
        for(i=0; i<str.size(); i++) printf("%c", str[i]);
    }
    return 0;
}

