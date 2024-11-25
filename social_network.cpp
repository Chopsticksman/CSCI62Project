#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include "network.h"
#include "user.h"
#include "post.h"



int main(int argc, char* argv[]) {
    if (argc != 2 && argc != 3) {
        std::cout << "Please input only user txt file and post txt file" << std::endl;
    } else {
        Network* network = new Network;
        network->readUsers(argv[1]);
        if (argc == 3) {
            network->readPosts(argv[2]);
        }
        int option;
        std::cout << "1: Add a user\n2: Add friend connection\n3: Delete friend connection\n4: Write to file\n5: View most recent posts\n6: Quit" << std::endl;
        while (true) {
            std::cin >> option;
            std::cin.ignore();
            if (option == 1) {
                std::cout << "Format: [id] [firstname] [lastname] [year] [zip code]" << std::endl;
                std::string input;
                getline(std::cin, input);
                std::stringstream ss(input);
                std::string part;
                int id;
                std::string firstName;
                std::string lastName;
                std::string name;
                int year;
                int zip;

                ss >> part;
                id = std::stoi(part);
                ss >> firstName;
                ss >> lastName;
                name = firstName + " " + lastName;
                ss >> part;
                year = std::stoi(part);
                ss >> part;
                zip = std::stoi(part);
                User* u = new User(id, name, year, zip, std::set<int>());
                network->addUser(u);

            } else if (option == 2) {
                std::cout << "Format: [YourFirstName] [YourLastName] [TheirFirstName] [TheirLastName]" << std::endl;
                std::string input;
                getline(std::cin, input);
                std::stringstream ss(input);
                std::string yourFirstName;
                std::string yourLastName;
                std::string theirFirstName;
                std::string theirLastName;
                std::string yourName;
                std::string theirName;
                ss >> yourFirstName;
                ss >> yourLastName;
                ss >> theirFirstName;
                ss >> theirLastName;
                yourName = yourFirstName + " " + yourLastName;
                theirName = theirFirstName + " " + theirLastName;
                network->addConnection(yourName, theirName);
                

            } else if (option == 3) {
                std::cout << "Format: [YourFirstName] [YourLastName] [TheirFirstName] [TheirLastName]" << std::endl;
                std::string input;
                getline(std::cin, input);
                std::stringstream ss(input);
                std::string yourFirstName;
                std::string yourLastName;
                std::string theirFirstName;
                std::string theirLastName;
                std::string yourName;
                std::string theirName;
                ss >> yourFirstName;
                ss >> yourLastName;
                ss >> theirFirstName;
                ss >> theirLastName;
                yourName = yourFirstName + " " + yourLastName;
                theirName = theirFirstName + " " + theirLastName;
                network->deleteConnection(yourName, theirName);
                

            } else if (option == 4) {
                std::cout << "Format: [Text file to be written to]" << std::endl;
                std::string input;
                getline(std::cin, input);
                char* fileName = new char[input.length() + 1];
                std::strcpy (fileName, input.c_str());
                network->writeUsers(fileName);

            } else if (option == 5) {
                std::cout << "Format: [FirstName] [LastName] [# of posts]" << std::endl;
                std::string input;
                getline(std::cin, input);
                std::stringstream ss(input);
                std::string firstName;
                std::string lastName;
                std::string num;
                ss >> firstName;
                ss >> lastName;
                ss >> num;
                std::string name = firstName + " " + lastName;
                int howMany = std::stoi(num);
                std::cout << network->getPostsString(network->getId(name), howMany, false) << std::endl;
            } else {
                std::cout << "Exiting..." << std::endl;
                exit(0);
            }
            std::cout << "1: Add a user\n2: Add friend connection\n3: Delete friend connection\n4: Write to file\n5: View most recent posts\n6: Quit" << std::endl;

        }
    }
    return 0;
}
