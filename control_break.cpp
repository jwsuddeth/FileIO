
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

    // add a grand total variable... 
    double grandTotal = 0.0;


    cout << "\n\nExpense Report By Department\n\n";

    cout << left
	    << setw(20)
	    << "Name"
	    << setw(20)
	    << "Dept"
	    << setw(6)
	    << "Amt"
	    << setw(50)
	    << "Description"
	    << "\n"
	    << string(85, '=') 
	    << "\n\n";
    

    while(infile.read(reinterpret_cast<char *>(&input), sizeof(Expense)))
    {
        // if the department does not match the current then we hit a control break
        if (strcmp(currentDept, input.department) != 0)
        {
            // if we don't have a current department then it is the first record
            // if we do then we print our department total line then clear it
            if (strlen(currentDept) > 0)
            {
                cout << string(85, '-') << "\n";
                cout << "Department Total: " << deptTotal << "\n\n\n"; 

		// add the deptTotal into the grand total
		grandTotal += deptTotal;
            }
            deptTotal = 0.0;
            strcpy(currentDept, input.department);
        }

        // accumulate amount
        deptTotal += input.amount;

        // print the line item
        cout << left
	       << setw(20) << input.name << setw(20) << input.department << setw(6) << input.amount << setw(50) 
	       	<< input.description << endl;
    }

    // write the last summary line
    cout << string(85, '-') << "\n";
    cout << "Department Total: " << deptTotal << endl;


    // add the deptTotal into the grand total
    grandTotal += deptTotal;

   // display the grand total
   cout << string(85, '=') << "\n\n";
   cout << "Grand Total:\t" << grandTotal << endl;

    infile.close();
    return 0;
}
