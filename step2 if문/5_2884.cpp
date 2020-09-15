//#2884 알람 시계
#include <iostream>
using namespace std;

int main(void) {
	int H, M;
	cin >> H>>M;

	if (M < 45) {
		M += 60;
		if (H == 0)
			H = 23;
		else  H -= 1;
	}

	cout << H << " " <<M-45;

}