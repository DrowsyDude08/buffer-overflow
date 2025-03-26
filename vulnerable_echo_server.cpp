// vulnerable_echo_server.cpp
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <cstdlib>

void vulnerable_echo() {
    char buffer[128];
    std::cout << "Enter your message: ";
    std::cin >> buffer;
    std::cout << "You entered: " << buffer << std::endl;
}

void secret_function() {
    const char *flag = getenv("FLAG");
    if (!flag) {
        flag = "practice{default_flag}";
    }
    std::cout << "Congratulations! Here's your flag: " << flag << std::endl;
    exit(0);
}

int main() {

    setbuf(stdout, NULL);
    
    std::cout << "Welcome to the Echo Service!" << std::endl;
    std::cout << "Secret function address: " << (void*)secret_function << std::endl;
    
    while(true) {
        vulnerable_echo();
    }
    
    return 0;
}