#include <iostream>
#include <logger/logger.h>

void basicTest(Logger* logger) {
    logger->debug("debug test");
    logger->info("info test");
    logger->system("system test");
    logger->named<Logger>("named test");
}

void timeTest(Logger* logger) {
    logger->setTimeFormat("%d.%m %H:%M:%S ");
    logger->info("time info test");
    for (int i = 0; i < 99999999*3; i++) ;
    logger->debug("time debug test");
    for (int i = 0; i < 99999999*3; i++) ;
    logger->system("time system test");
    for (int i = 0; i < 99999999*3; i++) ;
    logger->error("time error test");
    for (int i = 0; i < 99999999*3; i++) ;
    logger->named<Logger>("time named test");
    logger->setTimeFormat("");
}

int main() {
    Logger* logger = new Logger();
    logger->system(Logger::START);
    basicTest(logger);
    timeTest(logger);
    logger->system(Logger::STOP);
    return 0;
}
