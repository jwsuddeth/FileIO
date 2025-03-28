
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void createFile();
void readFile();


int main()
{
    //createFile();

    readFile();

    return 0;
}

void createFile()
{
    // open the file for writing in append mode
    ofstream nameFile("names.dat", ios::app);

    char nameBuffer[50];
    memset(nameBuffer, 0, sizeof(nameBuffer));

    // process the file by reading names from the 
    // user and appending them to the file
    cout << "Instructions: Enter a name. To exit, press enter to enter a blank name." << endl;
    cout << "Enter name: " << endl;
    cin.getline(nameBuffer, 50);
    while(strlen(nameBuffer) > 0)
    {
        nameFile << nameBuffer << endl;
        memset(nameBuffer, 0, sizeof(nameBuffer));

        cout << "Enter name: " << endl;
        cin.getline(nameBuffer, 50);
    }

    // close the file
    nameFile.close();
    
}

void readFile()
{
    char nameBuffer[50];
    memset(nameBuffer, 0, sizeof(nameBuffer));

    ifstream namesFile("names.dat");
    while (namesFile.getline(nameBuffer, sizeof(nameBuffer)-1))
    {
        cout << nameBuffer << endl;
        memset(nameBuffer, 0, sizeof(nameBuffer));
    }

    namesFile.close();
}