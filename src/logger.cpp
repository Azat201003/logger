#include "logger.h"

void Logger::setPrintFunc(function<void(string)> print) {
    this->print = print;
}

void Logger::setOutputFile(string filepath) {
    ofstream* log = static_cast<ofstream*>(calloc(sizeof(ofstream), 1)); // ! рискованно, занимает файл но не освобождает его .close()
    print = [log] (string text) {
        (*log) << text;
    };
}

void Logger::info(string text) {
    print("> " + text + "\n");
}

void Logger::system(string text) {
    print("[SYSTEM] " + text + "\n");
}

void Logger::debug(string text) {
    print("*DEBUG* " + text + "\n");
}

void Logger::system(SystemMessages message) {
    system(SYSTEM_MESSAGES.at(message));
}
