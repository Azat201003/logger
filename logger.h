#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

enum ClassMessages {
CREATED,
};

enum SystemMessages {
    START,
    STOP,
};

template <typename x>
string className() { return typeid(x).name(); }

static map<ClassMessages, string> CLASS_MESSAGES {
    {ClassMessages::CREATED, "created"},
};

static map<SystemMessages, string> SYSTEM_MESSAGES {
    {SystemMessages::START, "----------STARTED----------\n\n"},
    {SystemMessages::STOP, "----------STOPPED----------\n\n"},
};

class Logger {
public:
    // static Logger* getInstance();
    void info(string text);
    template <typename T>
    static void named(string text) {
        cout << "[" << className<T>() << "] " << text << endl;
    }
    template <typename T>
    static void named(ClassMessages message) {
        named<T>(CLASS_MESSAGES.at(message));
    }
    static void system(SystemMessages message);
    static void system(string text);
    static void debug(string text);
};
