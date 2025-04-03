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
}