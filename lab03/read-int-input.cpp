#include <iostream>
using namespace std;
int main()
{
	const int bufSize = 2000;
	int data[bufSize];
	int i = 0, reading, count = 0;
	for (i = 0; cin >> reading; i++) {
		data[i] = reading;
	}
	count = i;
	for (i = 0; i < count; i++) {
		cout << data[i] << " ";
	}
	return 0;
}
