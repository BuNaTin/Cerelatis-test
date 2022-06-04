#include "Net/Client.h"
#include "Net/Server.h"
#include "Net/ServerType.h"

#include <iostream>

#include <unistd.h>

void printHelp();

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printHelp();
        return 0;
    }
    using namespace Cerelatis;

    if (argv[1][0] == 's') {
        std::unique_ptr<Net::Server> server;
        try {
            server = Net::Server::create(Net::ServerType::UDP);
        } catch (...) {
            return 1;
        }

        server->setHandler([](const std::string &data) {
            sleep(3);
            std::cout << '|' << data << "|\n";
            return "OK!";
        });

        if (!server->start()) {
            return 1;
        }
    } else if (argv[1][0] == 'c') {
        std::unique_ptr<Net::Client> client;
        try {
            client = Net::Client::create(Net::ServerType::UDP);
        } catch (...) {
            return 1;
        }

        std::string data;
        while (data != "quit") {
            std::cout << "> ";
            std::cin >> data;
            client->send(data);
        }

    } else {
        printHelp();
    }

    return 0;
}

void printHelp() {
    std::cout << "Usage: ./cerelatis-test [c|s]" << '\n';
}