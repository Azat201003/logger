#include "main/logger.h"

void Logger::info(string text)
{
    cout << "> " << text << endl;
}

void Logger::system(string text) {
    cout << "[SYSTEM] " << text << endl;
}

void Logger::debug(string text) {
    cout << "*DEBUG* " << text << endl;
}

void Logger::system(SystemMessages message) {
    system(SYSTEM_MESSAGES.at(message));
}
