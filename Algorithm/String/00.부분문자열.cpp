#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {

	/*string a = "string";
	string b;
	cin >> b;

	
	if (a.find(b)) {
		cout << "없음";
	}
	else
		cout << "있음";*/
	string name;
	int n;
	cin >> name >> n;
	char* check = new char[n];
	for (int i = 0; i < n; i++) {
		string place;
		cin >> place;
		if (place.find(name) == -1) {
			check[i] = 'X';
		}
		else
			check[i] = 'O';
	}
	for (int i = 0; i < n; i++) {
		cout << check[i] << endl;
	}

	
}