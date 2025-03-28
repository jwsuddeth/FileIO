
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


int main(int argc, const char * argv[]) 
{
    // open for reading
    ifstream infile("expense.bin", ios::binary);

    Expense input;

    char currentDept[50];
    memset(currentDept, 0, sizeof(currentDept));

    double deptTotal = 0.0;

    cout << "\n\nExpense Report By Department\n\n";

    while(infile.read(reinterpret_cast<char *>(&input), sizeof(Expense)))
    {
        // if the department does not match the current then we hit a control break
        if (strcmp(currentDept, input.department) != 0)
        {
            // if we don't have a current department then it is the first record
            // if we do then we print our department total line then clear it
            if (strlen(currentDept) > 0)
            {
                cout << "=========================================\n";
                cout << "Department Total: " << deptTotal << endl << endl << endl;

            }
            deptTotal = 0.0;
            strcpy(currentDept, input.department);
        }

        // accumulate amount
        deptTotal += input.amount;

        // print the line item
        cout << input.name << "\t" << input.department << "\t" << input.amount << "\t" << input.description << endl;
    }

    // write the last summary line
    cout << "=========================================\n";
    cout << "Department Total: " << deptTotal << endl << endl << endl;

    infile.close();
    return 0;
}
