
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#pragma pack(1)

struct Expense
{
    char name[50];
    char department[50];
    double amount;
    char description[50];
};

#pragma pack()

long getFileSize(const char *fileName)
{
    ifstream infile(fileName, ios::binary | ios::ate);
    long size = infile.tellg();
    infile.close();
    return size;
}

int main(int argc, const char * argv[]) 
{
    long fileSize = getFileSize("expense.bin");

    long recordCount = fileSize / sizeof(Expense);

    cout << "There are " << recordCount 
        << " Expense Records. Which record would you like? " << endl;
    int recno;
    cin >> recno;

    // the record number is 0 based since the file starts at offset 0. So we subtract one from what they said.
    recno--;

    if (recno * sizeof(Expense) > fileSize)
    {
        cout << "There are not that many records!\n";
        return 0;
    }

    // open that file and scan to that record
    ifstream infile("expense.bin", ios::binary);
    infile.seekg(recno * sizeof(Expense));

    // read the record
    Expense expense;
    infile.read(reinterpret_cast<char *>(&expense), sizeof(Expense));

    // close the file
    infile.close();

    // print the record. We add one when we print the record number to match what they asked for
    cout << "Record " << recno+1 << "\t" << expense.name << "\t" << expense.department 
        << "\t" << expense.amount << "\t" << expense.description << endl;

    return 0;
}
