#include <stdio.h>
#include <vector>
#include<algorithm> 
using namespace std;


int main(){

	int n, left=77, right, cur, k=1, res=0;
	scanf("%d", &n);
	while(left != 0){
		left=n/(k*10);
		right=n%k;
		cur=(n/k)%10;
		if(3<cur){
			res=res+((left+1)*k);
		}
		else if(3==cur){
			res=res+((left*k)+(right+1));
		}
		else res=res+(left*k);	
		k=k*10;
	}
	printf("%d\n", res);
	return 0;
    
}