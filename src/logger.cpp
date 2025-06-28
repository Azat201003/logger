#include "logger.h"

void Logger::print(string name, string text) {
    customPrint("[" + name + "] " + text + "\n");
}

void Logger::setPrintFunc(function<void(string)> print) {
    this->customPrint = print;
}

void Logger::setOutputFile(string filepath) {
    ofstream* log = static_cast<ofstream*>(calloc(sizeof(ofstream), 1)); // ! рискованно, занимает файл но не освобождает его .close()
    this->customPrint = [log] (string text) {
        (*log) << text;
    };
}

void Logger::info(string text) {
    print("INFO", text);
}

void Logger::system(string text) {
    print("SYSTEM", text);
}

void Logger::debug(string text) {
    print("DEBUG", text);
}

void Logger::system(SystemMessages message) {
    system(SYSTEM_MESSAGES.at(message));
}
