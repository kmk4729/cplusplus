#include <iostream>
#include <vector>

using namespace std;

int main() {
	int arow, acol, brow, bcol;
	cout << "A의 행 렬 :";
	cin >> arow >> acol;
	cout << "B의 행 렬: ";
	cin >> brow >> bcol;
	vector<vector<int>> a(arow,vector<int>(acol));
	vector<vector<int>> b(brow, vector<int>(bcol));

	for (auto &elem : a) {
		for (auto &elem2 : elem) {
			elem2 = rand() % 19-9 ;
		}
	}

	for (auto elem : a) {
		for (auto elem2 : elem) {
			cout << elem2 << " ";
		}
		cout << endl;
	}

	cout << endl << endl;
	for (auto& elem : b) {
		for (auto& elem2 : elem) {
			elem2 = rand() % 19-9;
		}
	}

	for (auto elem : b) {
		for (auto elem2 : elem) {
			cout << elem2 << " ";
		}
		cout << endl;
	}

	if (acol != brow) {
		cout << "두 행렬을 곱할 수 없습니다" << endl;
	}

	else {
		vector<vector<int>> c(arow, vector<int>(bcol));
		cout << endl << endl << endl;
		for (int col = 0; col < bcol; col++) {
			for (int row = 0; row < arow; row++) {
				for (int count = 0; count < acol; count++) {
					c[row][col] += a[row][count] * b[count][col];
				}
			}
		}
		for (auto elem : c) {
			for (auto elem2 : elem) {
				cout << elem2 << " ";
			}
			cout << endl;
		}

	}
}