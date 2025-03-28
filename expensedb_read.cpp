//
//  main.cpp
//  dbrecords
//
//  Created by Jeffery Suddeth on 3/27/25.
//

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


int main(int argc, const char * argv[]) {
   
    // open for reading
    ifstream infile("expense.bin", ios::binary);

    Expense input;

    while(infile.read(reinterpret_cast<char *>(&input), sizeof(Expense)))
    {
        cout << input.name << "\t" << input.department << "\t" << input.amount << "\t" << input.description << endl;
    }

    infile.close();
    return 0;
}
