#include <stdio.h>
#include <algorithm>

int a[52],b[52]; //알파벳 카운팅용이므로 int형으로 그리고 전역 변수로

//Anagram
int main(){

    // freopen("input.txt","rt",stdin); //cin이 읽을 때마다 지정 파일에서 읽어줌


    char str1[100];
    char str2[100];
    int i;

    scanf("%s",&str1);
    scanf("%s",&str2);

    //아스키 넘버와, int배열의 인덱스를 1대1대칭시키기
    //대문자 A~Z : 65~90 이므로, 대문자일 경우 -64를 해서 배열에 넣기 즉 (1~26)
    //소문자 a~z : 97~122 이므로, 소문자일 경우 27부터 넣어야하니깐 -70 (27~)

    for(i=0;str1[i]!='\0';i++){
        if(str1[i]>=65 &&str1[i]<=90){//대문자일 경우
            a[str1[i]-64]++;
        }
        else{
            a[str1[i]-70]++;
        }
    }

    for(i=0;str2[i]!='\0';i++){
        if(str2[i]>=65 &&str2[i]<=90){//대문자일 경우
            b[str2[i]-64]++;
        }
        else{
            b[str2[i]-70]++;
        }
    }

    //카운팅 배열 확인
    for(i=1;i<=52;i++){
        if(a[i]!=b[i]){
            printf("No\n");
            exit(0);
        }
    }

    printf("YES\n");








    return 0;
}