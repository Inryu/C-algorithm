//#1110 ���ϱ� ����Ŭ
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

		front = num / 10; //���ڸ� �� , 10���� ������ �ڵ����� 0
		back = num % 10; // ���ڸ� ��
		num = (back * 10) + ((back + front) % 10);

		if (num == temp) {
			cout << count << endl;
			break;
		}
	}
}