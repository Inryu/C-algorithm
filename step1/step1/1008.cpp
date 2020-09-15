// #1008 A/B

#include <iostream>
using namespace std; // std클래스에 정의되어있는 함수를 사용하겠다.
int main(void) {
	int A, B;
	double n;
	cin >> A >> B;
	n = (double)A /(double)B;
	cout.precision(10); //소수점 출력 범위 설정
	cout << n;
}