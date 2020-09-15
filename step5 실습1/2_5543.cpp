//#5543 상근날드
#include <iostream>
using namespace std;

int main(void) {

	//입출력 속도 향상 
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int i;
	int hamburger[3],minham=3000;
	int beverage[2],minbev=3000;

	//햄버거
	for (i = 0; i < 3; i++) {
		cin >> hamburger[i];
		// 가장 싼 햄버거
		if (hamburger[i] < minham)
			minham = hamburger[i];
	}

	//음료
	for (i = 0; i < 2; i++) {
		cin >> beverage[i];
		//가장 싼 음료
		if (beverage[i] < minbev)
			minbev = beverage[i];
	}
	
	cout << minham + minbev - 50;


}