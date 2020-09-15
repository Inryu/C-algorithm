//#2753 윤년
#include <iostream>
using namespace std;

int main(void) {
	int year;
	cin >> year;

	//윤년일 때
	//4의 배수이면서 100의 배수가 아닐 때 또는 400의 배수일 때
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		cout << 1;
	//윤년이 아닐 때
	else cout << 0;

}