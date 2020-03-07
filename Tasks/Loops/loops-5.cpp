#include <iostream>

using namespace std;

int main() {
	int n = 0, k = 0;
	cout << "Enter two numbers N and K:" << endl;
	cin >> n >> k;
	cout << endl;

	if (n < 0 || k < 0) return 0;

	unsigned long long nFact = 1, kFact = 1, nMinusKFact = 1;
	for (int i = 1; i <= n; i++) {
		nFact *= i;
	}
	for (int j = 1; j <= k; j++) {
		kFact *= j;
	}
	for (int s = 1; s <= (n - k); s++) {
		nMinusKFact *= s;
	}

	int combinationsOfNandK = nFact / (kFact * nMinusKFact);

	cout << "The possible combinations of K elements from a group of N is "
		 << combinationsOfNandK << endl << endl;

	return 0;
}