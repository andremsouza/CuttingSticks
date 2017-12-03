#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int solve(vi &c, vvi &dp, int left, int right) {
	if(left + 1 == right) return 0; //se não é posível cortar entre left e right
	if(dp[left][right] != -1) return dp[left][right]; //se já computado
	int aux = INT_MAX;
	for(int i = left + 1; i < right; i++) //para todos os cortes possiveis entre left e right
		aux = min(aux, solve(c, dp, left, i) + solve(c, dp, i, right) + c[right] - c[left]); //queremos minimizar o valor
	return dp[left][right] = aux; //retorna a solução otima
}

int main(int argc, char **argv) {
	int l;
	while(cin >> l) { //length
		if(!l) break;
		int n; cin >> n; //number of cuts
		vi cuts(n + 2, 0); //cuts
		vvi dp(n + 2, vi(n + 2, -1)); //dynamic programming table
		for(int i = 1; i <= n; i++) cin >> cuts[i]; //input
		cuts[n + 1] = l;
		cout << "The minimum cutting is " << solve(cuts, dp, 0, n + 1) << "." << endl; //output
	}
	return 0;
}
