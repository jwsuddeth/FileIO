#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

int main()
{
	ifstream namesFile("names.txt");

	char buffer[50];

	while(namesFile.getline(buffer, sizeof(buffer)))
	{
		// method 1 using >> operator

		// this method causes errors because >> ignores 
		// white space. ie, it may process the last line twice
		// namesFile >> buffer;
		cout << buffer << endl;
	}

	namesFile.close();

	return 0;
}

