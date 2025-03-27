#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

int main()
{
	char buffer[50];

	ofstream namesFile("names.txt");

	// first method
	namesFile << "Jeff" << endl;

	strcpy(buffer, "John\n");
	namesFile << buffer;

	// method 2 is to use the write method
	strcpy(buffer, "Susan\n");
	namesFile.write(buffer, strlen(buffer));

	namesFile.close();

	return 0;
}
