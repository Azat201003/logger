#include <iostream>
#include <logger/logger.h>

void basicTest(Logger* logger) {
    logger->system(Logger::START);
    logger->debug("debug test");
    logger->info("info test");
    logger->system("system test");
    logger->named<Logger>("named tag");
    logger->system(Logger::STOP);
}

int main() {
    Logger* logger = new Logger();
    basicTest(logger);
    return 0;
}
