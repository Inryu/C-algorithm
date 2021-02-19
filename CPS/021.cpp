#include <stdio.h>
#include <string.h>

int main(){

    int a[10],b[10],i,awin=0,bwin=0;
    char lastwin[10];

    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
    }

    for(i=0;i<10;i++){
        scanf("%d",&b[i]);
    }


        //이제 배열 비교
    for(i=0;i<10;i++){
        if(a[i]>b[i]) {
            awin+=3;
            strcpy(lastwin,"A");
        }
        else if(a[i]<b[i]) {
            bwin+=3;
            strcpy(lastwin,"B");
        }
        else {
            awin++;
            bwin++;
        }
    }

    //결과 값
    printf("%d %d\n",awin,bwin);
    
    if(awin>bwin) printf("A\n");
    else if(awin<bwin) printf("B\n");
    else if(awin==bwin){
        printf("%s",lastwin);
    }
    else{
        printf("D\n");
    }


}