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

    // create output file
    ofstream expenseFile("expense.bin", ios::binary);
    
    // loop until they are done entering expenses
    bool done = false;
    
    while (!done)
    {
        // read expense data
        Expense expense;
        memset(&expense, 0, sizeof(expense));
        
        cout << "Employee Name: " << endl;
        cin.getline(expense.name, 50);
        
        cout << "Department: " << endl;
        cin.getline(expense.department, 50);
        
        cout << "Expense Amount: " << endl;
        char buffer[50];
        cin.getline(buffer, 49);
        expense.amount = atof(buffer);
        
        cout << "Description: " << endl;
        cin.getline(expense.description, 50);
        
        // write to the file
        expenseFile.write(reinterpret_cast<char *>(&expense), sizeof(expense));
        
        // ask if they want to enter another. If they say anything other than y we are done.
        cout << "Enter another (y/n)? " << endl;
        char another[10];
        cin.getline(another, 10);
        
        cout << "==============" << endl;
        
        done = strcmp(another, "y") != 0;
    }
    
    // close the file
   expenseFile.close();
    
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
