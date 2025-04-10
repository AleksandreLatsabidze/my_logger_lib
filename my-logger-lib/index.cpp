<<<<<<< HEAD
#include <iostream>
#include <string>
using namespace std;
enum LoggingLevel
{
    DEBUG,
    INFO,
    ERROR,
};
class ConsoleLogger
{
public:
    void print(LoggingLevel level, string message) const
    {
        if (message.empty())
        {
            throw invalid_argument("ცარიელი არ შეიძლება იყოს");
        }
        if (message == "null")
        {
            throw invalid_argument("არ შეიძლება იყოს 'null'");
        }

        string levelStr;
        switch (level)
        {
        case DEBUG:
            levelStr = "DEBUG";
            break;
        case INFO:
            levelStr = "INFO";
            break;
        case ERROR:
            levelStr = "ERROR";
            break;
        default:
            throw invalid_argument("Invalid logging level.");
        }

        cout << "[" << levelStr << "]: " << message << endl;
    }
};

int main()
{
    ConsoleLogger logger;
    try
    {
        logger.print(DEBUG, "Application started");
        logger.print(INFO, "Application finished");
        logger.print(ERROR, "Application error");
        logger.print(DEBUG, ""); 
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
=======
#include <iostream>
#include <string>
using namespace std;
enum LoggingLevel
{
    DEBUG,
    INFO,
    ERROR,
};
class ConsoleLogger
{
public:
    void print(LoggingLevel level, string message) const
    {
        if (message.empty())
        {
            throw invalid_argument("It cannot be empty");
        }
        if (message == "null")
        {
            throw invalid_argument("Cannot be 'null'");
        }

        string levelStr;
        switch (level)
        {
        case DEBUG:
            levelStr = "DEBUG";
            break;
        case INFO:
            levelStr = "INFO";
            break;
        case ERROR:
            levelStr = "ERROR";
            break;
        default:
            throw invalid_argument("Invalid logging level.");
        }

        cout << "[" << levelStr << "]: " << message << endl;
    }
};
bool isValidPhoneNumber(const string& phone)
{
    for (char c : phone) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}


int main()
{
    ConsoleLogger logger;
    try
    {
        logger.print(DEBUG, "Application started");
        logger.print(INFO, "Application finished");
        logger.print(ERROR, "Application error");
        logger.print(DEBUG, ""); 
    
        string phoneNumber;
        cout << "Enter phone number (only digits allowed): ";
        getline(cin, phoneNumber);

        // Validate phone number (only digits allowed)
        while (!isValidPhoneNumber(phoneNumber))
        {
            cout << "Invalid phone number. Only digits are allowed. Please enter a valid phone number: ";
            getline(cin, phoneNumber);
        }
 
        cout << "Entered phone number: " << phoneNumber << endl;
        
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
 
  
    string phoneNumber;
    cout << "Enter phone number again (only digits allowed): ";
    getline(cin, phoneNumber);

    while (!isValidPhoneNumber(phoneNumber))
    {
        cout << "Invalid phone number. Only digits are allowed. Please enter a valid phone number: ";
        getline(cin, phoneNumber);
    }

    cout << "Entered phone number: " << phoneNumber << endl;

    return 0;
>>>>>>> feature/add-logging-levels
}