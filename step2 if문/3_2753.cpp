//#2753 ����
#include <iostream>
using namespace std;

int main(void) {
	int year;
	cin >> year;

	//������ ��
	//4�� ����̸鼭 100�� ����� �ƴ� �� �Ǵ� 400�� ����� ��
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		cout << 1;
	//������ �ƴ� ��
	else cout << 0;

}