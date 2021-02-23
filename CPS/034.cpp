#include <stdio.h>
int main() {
	int a[101], n, i, j, tmp;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}

	for(i=0; i<n; i++){
		for(j=0; j<n-i-1; j++){  //제일 큰 값을 맨 뒤로 밀기
			if(a[j]>a[j+1]){ //앞에가 크면 뒤로 밀어야함
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}	
	return 0;
}