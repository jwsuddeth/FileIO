#include <iostream>
#include <fstream>

using namespace std;

void fibonacci(int x[], int sz);

int main()
{
	// array of integers
	int arr[10];
	fibonacci(arr, 10);

	// write them to a file
	ofstream fibs("fibonacci_numbers.bin", ios::binary);

	for (int i=0; i<10; i++)
	{
		fibs.write(reinterpret_cast<char*>(&arr[i]), sizeof(int));
	}

	fibs.close();

	cout << "created the file\n";

	ifstream fibs_in("fibonacci_numbers.bin", ios::binary);

	while(!fibs_in.eof())
	{
		int input;
		fibs_in.read( reinterpret_cast<char*>(&input), sizeof(int));

		cout << "The value is " << input << endl;
	}

	fibs_in.close();

	return 0;
}


void fibonacci(int x[], int sz)
{

	if (sz < 2) return;

	x[0] = 0;
	x[1] = 1;

	for (int counter = 2; counter < sz; counter++)
	{
		x[counter] = x[counter-1] + x[counter-2];	
	}	
}
