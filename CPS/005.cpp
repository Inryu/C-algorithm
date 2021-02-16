#include <stdio.h>

int main(){

    char a[20];
    int year,age;

    scanf("%s",&a);

    printf("엥..?");

    //1. 나이 계산
    if(a[7]=='1'||a[7]=='2'){
        year=1900+((a[0]-48)*10+(a[1]-48));  //a[0]은 문자열이므로 아스키 문자로 인식할 것임
   // 아스키번호에서 진짜 숫자를 알려면 -48
    }else {
        year=2000+((a[0]-48)*10+(a[1]-48)); 
    }

    age=2020-year+1;
    printf("%d",age);

    //2. 성별 계산
     if(a[7]=='1'||a[7]=='3'){
        printf(" M\n");
        
     }else {
        printf(" W\n");

     }

     return 0;



}