#include <stdio.h>


//올바른 괄호 //스택 사용하지 않고 풀어보기
int main(){
    //여는 괄호를 만다면 cnt를 증가 , 닫는 괄호를 만나면 cnt 감소
    //마지막에 0이 된다면?
    // 근데 )( 이 있으면 안됨..! 닫는 괄호가 먼저 나오면 브레이크

    char a[100];

    int i,cnt=0;
    scanf("%s",a);

    for(i=0;a[i]!='\0';i++){
        if(a[i]=='(') cnt++;
        else cnt--;

        if(cnt<0) break; //닫는 괄호가 더 많이 나오는 경우
    }

    if(cnt==0) printf("YES\n");
    else printf("NO\n");

    return 0;

}