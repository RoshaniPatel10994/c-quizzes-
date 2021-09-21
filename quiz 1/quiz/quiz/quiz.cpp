#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
// Variable
int main()
{
	string person1;
	string person2;
	string person3;

	cout << "Please enter a famouse trio: ";
	cin >> person1 >> person2 >> person3;
	string s1 = "1) ";
	string s2 = "2) ";
	string s3 = "3) ";
	cout << s1 << person1 << endl;
	cout << s2 << person2 << endl;
	cout << s3 << person3 << endl;
	return 0;

}