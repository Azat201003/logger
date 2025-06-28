#pragma once

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <fstream>

using namespace std;

class Logger {
public:
    enum ClassMessages {
        CREATED,
    };

    enum SystemMessages {
        START,
        STOP,
    };
private:
    string timeFormat;
    function<void(string)> customPrint = &coutPrint;
    static void coutPrint(string text) {
        cout << text;
    }

    template <typename x>
    string className() { return typeid(x).name(); }

    const map<ClassMessages, string> CLASS_MESSAGES {
        {ClassMessages::CREATED, "created"},
    };

    const map<SystemMessages, string> SYSTEM_MESSAGES {
        {SystemMessages::START, "----------STARTED----------"},
        {SystemMessages::STOP, "----------STOPPED----------"},
    };
public:
    void print(string name, string text);
    void setPrintFunc(function<void(string)>);
    void setTimeFormat(string format);
    void setOutputFile(string filepath);
    void info(string text);
    template <typename T>
    void named(string text) {
        print(className<T>(), text + "\n");
    }
    template <typename T>
    void named(ClassMessages message) {
        named<T>(CLASS_MESSAGES.at(message));
    }
    void system(SystemMessages message);
    void system(string text);
    void debug(string text);
};
