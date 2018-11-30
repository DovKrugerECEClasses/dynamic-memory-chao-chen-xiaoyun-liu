
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
void sort(T a[], int size) {
    // using insertion sort
    if (size <= 1) {
        return;
    }
    for (int i = 1; i < size; ++i) {
        for (int j = i ; j >= 1; --j) {
            if (a[j - 1] > a[j]) {
                swap(a[j], a[j - 1]);
            } else {
                break;
            }
        }
    }
}

template <typename T>
void print(T a[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
    cout << '\n';
}


template <typename T>
T sum(T a[], int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += a[i];
    }
    return sum;
}

int main() {
	int a[] = {5, 4, 3, 1, 7, 8, 9, 2, 1};
	sort(a, sizeof(a)/sizeof(int));
	print(a, sizeof(a)/sizeof(int));
	
	double b[] = {5.5, 4.5, 1.2, 2.9, 9.2, 5.2};
	sort(b, sizeof(b)/sizeof(double));
	print(b, sizeof(b)/sizeof(double));

	cout << sum(a, sizeof(a)/sizeof(int)) << '\n';
	cout << sum(b, sizeof(b)/sizeof(double)) << '\n';

	string c[] = {"yo", "ho", "test", "foo", "bar"};
	sort(c, sizeof(c)/sizeof(string));
	print(c, sizeof(c)/sizeof(string));
	//TODO?	cout << sum(c, sizeof(c)/sizeof(string)) << '\n';
}
