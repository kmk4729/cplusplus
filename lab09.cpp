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



#include <iostream>
using namespace std;
int* make_arr(int n) { 
	int* arr = new int[n];
	for (int count = 0; count < n; count++) {
		arr[count] = 2 * count + 1;
	}
	return arr;
}
void print_arr(int* a, int n) {
	cout << "\nOdd Number Array:" << endl;
	while (n) {
		cout << *a << " ";
		a++;
		n--;
	}
	cout << endl;
}
int sum_arr(int* a, int n) {
	int s = 0;
	for (int i = 0; i < n; i++)
		s += a[i];
	return s;
}
int main() {
	int n;
	cout << "Enter a number: ";
	cin >> n;
	int* arr = make_arr(n);
	print_arr(arr, n);
	int sum = sum_arr(arr, n);
	cout << "\nSum of the array: " << sum << endl;
	delete[] arr;
	return 0;
}



#include <iostream>
using namespace std;

int main() {
	int num;
	while (true) {
		cout << "Please enter a number: ";
		cin >> num;
		if (num < 2) {
			cout << "Wrong number!!!" << endl;
			break;
		}
		int half = num / 2;
		cout << "Size of random array : " << half << endl;
		int* arr = new int[half];
		for (int k = 0; k < half; k++) {
			arr[k] = rand() % num+1;
		}

		int sum = 0;
		cout << "[array]" << endl;
		for (int k = 0; k < half; k++) {
			cout << arr[k] << " ";
			for (int g = k + 1; g < half; g++) {
				if (arr[k] == arr[g]) {
					sum++;
				}
			}
		}
		cout << endl;

		if (sum == 0) {
			cout << "Duplicates not found"<<endl<<endl;
		}
		else {
			cout << "Duplicates found" << endl<<endl;
		}
		
	}
}
