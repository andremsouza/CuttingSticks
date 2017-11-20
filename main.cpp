#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int solve(vi &c, vvi &dp, int left, int right) {
	if (left + 1 == right) return 0;
	if (dp[left][right] != -1) return dp[left][right];
	int aux = INT_MAX;
	for (int i = left + 1; i < right; i++)
		aux = min(aux,
				solve(c, dp, left, i) + solve(c, dp, i, right) + c[right]
																   - c[left]);
	return dp[left][right] = aux;
}

int main(int argc, char **argv) {
	int l;
	while (cin >> l) { //length
		if (!l) break;
		int n; cin >> n; //number of cuts
		vi c(n + 2, 0); //cuts
		vvi dp(n + 2, vi(n + 2, -1)); //dynamic program table
		for (int i = 1; i <= n; i++) cin >> c[i]; //input
		c[n + 1] = l;
		cout << "The minimum cutting is " << solve(c, dp, 0, n + 1) << "."
				<< endl; //output
	}

	return 0;
}
