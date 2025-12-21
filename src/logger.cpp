#include "logger.h"

#include <iostream>
#include <ctime>
#include <iomanip>

void Logger::print(string name, string text) {
	std::time_t currentTime = std::time(nullptr);
	std::tm* localTime = std::localtime(&currentTime);
	
	char buffer[80];
	strftime(
		buffer, sizeof(buffer),
		timeFormat.data(),
		localTime
	);

	customPrint(permissions.updateText(name, string(buffer) + "[" + name + "] " + text + "\n"));
}

void Logger::setPrintFunc(function<void(string)> print) {
    this->customPrint = print;
}

void Logger::setTimeFormat(string format) {
    this->timeFormat = format;
}

void Logger::setOutputFileAsPrint(string filepath) {
	this->customPrint = [this, filepath] (string text) {
		ofstream log;
		log.open(filepath);
		log << text;
		log.close();
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

void Logger::error(string text) {
	print("ERROR", text);
}

void Logger::system(SystemMessages message) {
	system(SYSTEM_MESSAGES.at(message));
}

UniqueLogger& UniqueLogger::getInstance() {
	static UniqueLogger instance;
	return instance;
}

