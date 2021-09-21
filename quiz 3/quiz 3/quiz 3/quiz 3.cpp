// DrawDiamond.cpp : Use this shell of a program to get started
//

//#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int MIN_WIDTH = 1;
const int MAX_WIDTH = 75;

int main()
{
	int iInputValue = 0;

	while (true)
	{
		cout << "Please enter an ODD integer in the range of " << MIN_WIDTH << " to " << MAX_WIDTH << " or 0 to quit: ";
		cin >> iInputValue;
		cout << endl;

		// Is the input less than or greater than or even?
		if (iInputValue < MIN_WIDTH || iInputValue > MAX_WIDTH || (iInputValue % 2) == 0)
		{
			cout << "Invalid integer...program exiting" << endl;
			system("pause");
			return 0;
		}

		//////////////////////////////////////

		/// Work here......

		int width = iInputValue + 2;
		int offset = width / 2;
		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < width; ++j) {
				if (i == width / 2) std::cout << "X";
				else if (j == offset || j == width - offset - 1) {
					std::cout << "*";
				}
				else    std::cout << " ";
			}
			if (i > width / 2 - 1) --offset;
			else ++offset;
			std::cout << std::endl;
		}
		//////////////////////////////////////



		cout << endl;
		system("pause");
		system("cls");
	}

	return 0;
}