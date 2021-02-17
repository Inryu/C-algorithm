#include <stdio.h>

//011과 같은 문제 - 숫자가 클 때는?
int main(){
    // freopen("input.txt","rt",stdin); //cin이 읽을 때마다 지정 파일에서 읽어줌


    int n, sum=0, c=1, d=9, res=0;

    //d : 자리수가 어디까지 왔는지..!  개수
    //한자리수 : 9개
    // 그 다음 두자리수(1~99까지 두자리수 숫자는 몇개?) : 90개 -> 총 숫자의 수 : 2*90
    // 그 다음 세자리 수 : 900개 -> 총 숫자의 수 : 3*900

    scanf("%d",&n);

    while(sum+d<n){ //sum_d: 이 개수만큼 지금 숫자가 되나?
        res+= c*d; //c자리 숫자 * d개 

        sum=sum+d; //이 개수만큼 구했다.
        c++;
        d=d*10;
    }

    res+=(n-sum)*c; //res에 포함되지 않은 숫자 개수!
    printf("%d",res);

    return 0;

}