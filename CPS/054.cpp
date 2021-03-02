#include<stdio.h>
#include<vector>
#include<algorithm>
#include <stack>
using namespace std;

int main(){

    stack<char> s;
    int i,flag=1;

    char a[50];
    scanf("%s",&a);

    for(i=0;a[i]!='\0';i++){
        if(a[i]=='('){
            s.push(a[i]);
        }
        else{
            if(s.empty()) {
                printf("NO\n"); 
                flag=0;
                break;
            }
            else s.pop();
        }
    }

    if(s.empty()&&flag==1) printf("YES\n"); //정상 종료
    if(flag==1&&!s.empty()) printf("NO\n");
}