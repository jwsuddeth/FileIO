#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>


using namespace std;

void getTimeStamp(char *buffer, int sz);

int main()
{
    char buffer[50];

    string userName;
    cout << "Enter your user name: " << endl;
    cin >> userName;


    ofstream logger("log.txt", std::ios::app);

    if (logger.is_open())
    {
        getTimeStamp(buffer, sizeof(buffer));
        logger << buffer
            << ": " << "The log file is openned by "
                << userName << endl;
    }
    else
    {
        cout << "Failed to open log file" << endl;
    }

    logger.close();

    return 0;
}


void getTimeStamp(char *buffer, int sz)
{
    memset(buffer, 0, sz);

    time_t now = time(0);
    tm *timestamp = localtime(&now);
    strncpy(buffer, asctime(timestamp), sz-1);

    // drop the newline character at the end!
    int length = (int)strlen(buffer);
    
    if (buffer[length-1] == '\n')
    {
        buffer[length-1] = '\0';
    }
}
