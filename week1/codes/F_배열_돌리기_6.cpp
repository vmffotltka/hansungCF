#include <bits/stdc++.h>
using namespace std;

int N, R, arr[128][128];

void f(int k, int l) {
	int len = (1 << l), mxLen = (1 << N);
	if (k == 1) {
		for (int i = 0; i < mxLen; i += len) {
			for (int j = 0; j < mxLen; j += len) {
				for (int a = 0; a < len / 2; a++) {
					for (int b = 0; b < len; b++) {
						swap(arr[i + a][j + b], arr[i + len - a - 1][j + b]);
					}
				}
			}
		}
	}
	else if (k == 2) {
		for (int i = 0; i < mxLen; i += len) {
			for (int j = 0; j < mxLen; j += len) {
				for (int a = 0; a < len; a++) {
					for (int b = 0; b < len / 2; b++) {
						swap(arr[i + a][j + b], arr[i + a][j + len - b - 1]);
					}
				}
			}
		}
	}
	else if (k == 3) {
		for (int i = 0; i < mxLen; i += len) {
			for (int j = 0; j < mxLen; j += len) {
				vector<vector<int>> tmp(len, vector<int>(len));
				for (int a = 0; a < len; a++) {
					for (int b = 0; b < len; b++) {
						tmp[a][b] = arr[i + a][j + b];
					}
				}
				for (int a = 0; a < len; a++) {
					for (int b = 0; b < len; b++) {
						arr[i + a][j + b] = tmp[len - b - 1][a];
					}
				}
			}
		}
	}
	else if (k == 4) {
		for (int i = 0; i < mxLen; i += len) {
			for (int j = 0; j < mxLen; j += len) {
				vector<vector<int>> tmp(len, vector<int>(len));
				for (int a = 0; a < len; a++) {
					for (int b = 0; b < len; b++) {
						tmp[a][b] = arr[i + a][j + b];
					}
				}
				for (int a = 0; a < len; a++) {
					for (int b = 0; b < len; b++) {
						arr[i + a][j + b] = tmp[b][len - a - 1];
					}
				}
			}
		}
	}
	else if (k == 5) {
		for (int i = 0; i < mxLen / 2; i += len) {
			for (int j = 0; j < mxLen; j += len) {
				for (int a = 0; a < len; a++) {
					for (int b = 0; b < len; b++) {
						swap(arr[i + a][j + b], arr[mxLen - i - len + a][j + b]);
					}
				}
			}
		}
	}
	else if (k == 6) {
		for (int i = 0; i < mxLen; i += len) {
			for (int j = 0; j < mxLen / 2; j += len) {
				for (int a = 0; a < len; a++) {
					for (int b = 0; b < len; b++) {
						swap(arr[i + a][j + b], arr[i + a][mxLen - j - len + b]);
					}
				}
			}
		}
	}
	else if (k == 7) {
		vector<vector<int>> tmp(mxLen, vector<int>(mxLen));
		for (int i = 0; i < mxLen; i += len) {
			for (int j = 0; j < mxLen; j += len) {
				for (int a = 0; a < len; a++) {
					for (int b = 0; b < len; b++) {
						tmp[j + a][mxLen - i - len + b] = arr[i + a][j + b];
					}
				}
			}
		}
		for (int i = 0; i < mxLen; i++) {
			for (int j = 0; j < mxLen; j++) {
				arr[i][j] = tmp[i][j];
			}
		}
	}
	else if (k == 8) {
		vector<vector<int>> tmp(mxLen, vector<int>(mxLen));
		for (int i = 0; i < mxLen; i += len) {
			for (int j = 0; j < mxLen; j += len) {
				for (int a = 0; a < len; a++) {
					for (int b = 0; b < len; b++) {
						tmp[mxLen - j - len + a][i + b] = arr[i + a][j + b];
					}
				}
			}
		}
		for (int i = 0; i < mxLen; i++) {
			for (int j = 0; j < mxLen; j++) {
				arr[i][j] = tmp[i][j];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> R;
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < (1 << N); j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < R; i++) {
		int k, l; cin >> k >> l;
		f(k, l);
	}
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < (1 << N); j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}
