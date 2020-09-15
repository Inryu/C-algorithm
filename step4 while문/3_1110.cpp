//#1110 더하기 사이클
#include <iostream>
using namespace std;

int main(void) {
	int num, temp;
	int front, back;
	int count = 0;

	cin >> num;
	temp = num;

	while (1) {
		count++;

		front = num / 10; //앞자리 수 , 10보다 작으면 자동으로 0
		back = num % 10; // 뒷자리 수
		num = (back * 10) + ((back + front) % 10);

		if (num == temp) {
			cout << count << endl;
			break;
		}
	}
}