// #1008 A/B

#include <iostream>
using namespace std; // stdŬ������ ���ǵǾ��ִ� �Լ��� ����ϰڴ�.
int main(void) {
	int A, B;
	double n;
	cin >> A >> B;
	n = (double)A /(double)B;
	cout.precision(10); //�Ҽ��� ��� ���� ����
	cout << n;
}