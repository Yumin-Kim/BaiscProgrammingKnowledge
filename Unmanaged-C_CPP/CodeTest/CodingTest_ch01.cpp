#include <stdc++.h>

using namespace std;

int n, m, k;
vector<int> v;

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	int first = v[n - 1];
	int second = v[n - 2];

	int cnt = (m / (k + 1)) * k;
	cnt += m % (k + 1);

	int result = 0;
	result += cnt * first;
	result += (m - cnt) * second;
	
	cout << result << endl;

}
