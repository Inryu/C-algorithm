#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxval = -2147000000;
vector<pair <int, int>> a;
int n;

void DFS(int day, int sum) {

	if (day > n) {
		maxval = max(maxval, sum);
	}

	else {
		if (day + a[day].first <= n+1) DFS(day + a[day].first, sum + a[day].second);
		DFS(day + 1, sum);
	}
}

int main() {

	cin >> n;

	int t, p;

	a.push_back(make_pair(0, 0));

	for (int i = 1; i <= n; i++) {
		cin >> t >> p;
		a.push_back(make_pair(t, p));

	}

	DFS(1, 0); //(day,sum)

	cout << maxval;

}