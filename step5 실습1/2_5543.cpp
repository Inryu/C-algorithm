//#5543 ��ٳ���
#include <iostream>
using namespace std;

int main(void) {

	//����� �ӵ� ��� 
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int i;
	int hamburger[3],minham=3000;
	int beverage[2],minbev=3000;

	//�ܹ���
	for (i = 0; i < 3; i++) {
		cin >> hamburger[i];
		// ���� �� �ܹ���
		if (hamburger[i] < minham)
			minham = hamburger[i];
	}

	//����
	for (i = 0; i < 2; i++) {
		cin >> beverage[i];
		//���� �� ����
		if (beverage[i] < minbev)
			minbev = beverage[i];
	}
	
	cout << minham + minbev - 50;


}