#pragma once

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <fstream>
#include <vector>

using namespace std;

class Permission {
public:
    virtual string updateText(string) = 0;
};

class BasePermission : public Permission {
    string updateText(string text) override {
        return text;
    }
};

class NoTextPermission : public Permission {
    string updateText(string) override {
        return "";
    }
};

class Permissions {
private:
    map<string, Permission*> permissions;
public:
    Permissions() {
        permissions[""] = new BasePermission();
    }
    void updatePermission(string subject, Permission* permission) {
        permissions[subject] = permission;
    }

    string updateText(string name, string text) {
        Permission* permission = permissions[name];
        if (permission != nullptr)
            return permissions[""]->updateText(permission->updateText(text));
        return text;
    }
};

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
    ofstream log;
    string timeFormat = "";
    function<void(string)> customPrint = &coutPrint;

    static void coutPrint(string text) {
        cout << text;
    }
    template <typename T>
    string className() { return typeid(T).name(); }

    const map<ClassMessages, string> CLASS_MESSAGES {
        {ClassMessages::CREATED, "created"},
    };
    const map<SystemMessages, string> SYSTEM_MESSAGES {
        {SystemMessages::START, "----------STARTED----------"},
        {SystemMessages::STOP, "----------STOPPED----------"},
    };
public:
    Permissions permissions;

    void print(string name, string text);
    void setPrintFunc(function<void(string)>);
    void setTimeFormat(string format);
    void setOutputFileAsPrint(string filepath);
    void info(string text);
    template <typename T>
    void named(string text) {
        print(className<T>(), text);
    }
    template <typename T>
    void named(ClassMessages message) {
        named<T>(CLASS_MESSAGES.at(message));
    }
    void system(SystemMessages message);
    void system(string text);
    void debug(string text);
    void error(string text);
};
