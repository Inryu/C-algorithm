#include <stdio.h>
int C[20];
int main() {
	int s, n, a, i, j, pos;

	scanf("%d %d", &s, &n);

    //작업 개수
	for(i=1; i<=n; i++){
		scanf("%d", &a);
		pos=-1; 


        //hit냐 miss냐
		for(j=0; j<s; j++) {
            if(C[j]==a)  pos=j;
        }

        //miss
		if(pos==-1){
			for(j=s-1; j>=1; j--) {
                C[j]=C[j-1];
            }
		}
        //hit
		else{
			for(j=pos; j>=1; j--){
                C[j]=C[j-1];
            } 
		}


		C[j]=a;
	}


	for(i=0; i<s; i++) {
        printf("%d ", C[i]);
    }

	return 0;
}