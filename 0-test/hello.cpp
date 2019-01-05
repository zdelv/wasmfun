#include <stdio.h>
#include <iostream>
#include <emscripten.h>
using namespace std;

int main() {
	printf("Hello World\n");
	int x(0);
	cout << "x: ";
	cin >> x;

	cout << "x is: " << x;

	return 0;
}
