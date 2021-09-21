
#include <iostream>
#include<iomanip>
using namespace std;

void printTriangle(int space_before, int space_between, int test_val, bool bTop)
{
	bool bContinue = false;
	do {
		for (int i = 0; i < space_before; i++)
		{
			cout << ' ';
		}
		cout << '*';

		if (space_between > 0)
		{
			for (int i = 0; i < space_between; i++)
			{
				cout << ' ';
			}
			cout << '*';
		}
		cout << endl;
		if (bTop)
		{
			space_between += 2;
			bContinue = (space_before--) > 1;
		}
		else
		{
			space_between -= 2;
			bContinue = (space_before++) < test_val / 2 + 1;
		}
	} while (bContinue);
}

///////////////////////////////////////////////////////////////////////////
int main()
{
	while (true)
	{


		int inVal = 0;
		cout << "Please Enter a number or 0 to quit:";
		cin >> inVal;

		if (inVal == 0 || !(inVal % 2))
			break;


		const int test_val = inVal;
		int space_before = test_val / 2 + 1;
		int space_between = -1;
		printTriangle(space_before, space_between, test_val, true);


		/////////////////////////////////////////////
		for (int i = 0; i < test_val + 2; i++)
			cout << 'X';

		cout << endl;

		///////////////////////////////////////////
		space_before = 1;
		space_between = test_val - 2;
		printTriangle(space_before, space_between, test_val, false);
		
		system("pause");
		system("cls");

	}

	return 0;
}

