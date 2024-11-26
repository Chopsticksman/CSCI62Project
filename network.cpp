#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include "network.h"
#include "post.h"
#include "user.h"



std::vector<User*> users_;
int nextMsgId = 0;

//Default constructor
//pre: none
//post: creates an empty users_ list Network
Network::Network() {

}


//Method that takes in an id int and returns a User pointer
//pre: none
//post: nullptr if not found, user pointer if found
User* Network::getUser(int id) {
    for (User* u : users_) {
        if (u->getId() == id) {

            return u;
        }
    }
    return nullptr;
}

//Adds a user to users_ vector
//pre: Takes in a user pointer
//post: adds the user pointer to users_ vector
void Network::addUser(User* user) {
    if (users_.empty()) {
        users_.push_back(user);
    } else {
        for(int i = 0; i < users_.size(); i++) {
            if(users_[i]->getId() > user->getId()) {
                users_.insert(users_.begin() + i, user);
                break; 
            }
        }
        users_.push_back(user);
    }
}

//With the names of two users, 
//add them to both user's friends_ set if not there.
//pre: two strings in first name last name format
//post: -1 if at least one user is not found, 0 otherwise
int Network::addConnection(std::string s1, std::string s2) {
    User* u1;
    User* u2;
    int id1 = getId(s1);
    int id2 = getId(s2);
    if (id1 == -1 || id2 == -1) {
        std::cout << "User not found." << std::endl;
        return -1;
    }
    u1 = getUser(id1);
    u2 = getUser(id2);
    u1->addFriend(id2);
    u2->addFriend(id1);
    return 0;
}

//With the names of two users, 
//remove them from both user's friends_ set if there.
//pre: two strings in first name last name format
//post: -1 if at least one user is not found, 0 otherwise
int Network::deleteConnection(std::string s1, std::string s2) {
    User* u1;
    User* u2;
    int id1 = getId(s1);
    int id2 = getId(s2);
    if (id1 == -1 || id2 == -1) {
        std::cout << "User not found." << std::endl;
        return -1;
    }
    u1 = getUser(id1);
    u2 = getUser(id2);
    u1->deleteFriend(id2);
    u2->deleteFriend(id1);
    return 0;
}

//Given a name, returns a user's id if found, -1 otherwise
//pre: requires a string
//post: returns an int depending on if an id was found or not
int Network::getId(std::string name) {
    for (User* user : users_) {
        if (user->getName() == name) {
            return user->getId();
        }
    }
    return -1;
}

//Returns the number of users on the network
//pre: none
//post: returns size of users_
int Network::numUsers() {
    return users_.size();
}

//Initializes all of the network's information from a file.
//Parameter is in char*, or a c string for the file name
//pre: file has to exist
//post: adds users to users_ based on file input
void Network::readUsers(char* fname) {
    std::string line;
    std::ifstream ThisFile(fname);
    getline(ThisFile, line); //First line is numUsers
    if (ThisFile) {
        while(std::getline(ThisFile, line)) {
            int id = std::stoi(line);
            getline(ThisFile, line);
            std::string name = line.substr(1);
            getline(ThisFile, line);
            int year = std::stoi(line);
            getline(ThisFile, line);
            int zip = std::stoi(line);
            getline(ThisFile, line);
            std::stringstream ss(line);
            std::string val;
            std::set<int> friendsList;
            while(ss >> val) {
                friendsList.insert(std::stoi(val));
            }
            User* newUser = new User(id, name, year, zip, friendsList);
            addUser(newUser);
        }
    }
}

//Writes all of the network's information to a file.
//Parameter is in char*, or a c string for the file name
//pre: none
//post: writes the information in users_ to the file given.
void Network::writeUsers(char* fname) {
    std::ofstream NewFile(fname); //NewFile
    std::string fileContent = "";
    fileContent += std::to_string(numUsers()) + "\n";
    for (User* user : users_) {
        fileContent += std::to_string(user->getId()) + "\n";
        fileContent.append("\t" + user->getName() + "\n");
        fileContent += "\t" + std::to_string(user->getYear()) + "\n";
        fileContent += "\t" + std::to_string(user->getZip()) + "\n";
        fileContent += "\t";
        for (int id : user->getFriends()) {
            fileContent += std::to_string(id) + " ";
        }
        fileContent += "\n";
    }
    NewFile << fileContent;
}

std::vector<int> Network::shortestPath(int from, int to) {
    std::vector<int> returnVector;
    if (from == to) {
        returnVector.push_back(from);
        return returnVector;
    }
    std::queue<int> q;
    std::vector<bool> visited (numUsers(), 0); //Nodes: users
    std::vector<int> prev (numUsers(), -1); //Edges: friends list
    
    visited[from] = true;
    q.push(from);

    while (q.size() > 0) {
        int cur = q.front();
        q.pop();
        for (int id : getUser(cur)->getFriends()) {
            if (visited[id] == false) {
                q.push(id);
                visited[id] = true;
                prev[id] = cur;
            }

            if (id == to) {
                while (id != -1) {
                    returnVector.push_back(id);
                    id = prev[id];
                }
                std::reverse(returnVector.begin(), returnVector.end());
                return returnVector;
            }
        }
    }
    return returnVector;
}


std::vector<int> Network::distanceUser(int from, int& to, int distance) {
    std::vector<int> returnVector;
    if (from == to) {
        returnVector.push_back(from);
        return returnVector;
    }
    std::stack<int> stack;
    std::vector<bool> visited(numUsers(), 0); //Nodes: users
    std::vector<int> prev(numUsers(), -1); //Edges: friends list
    std::vector<int> dist(numUsers(), -1);
    
    dist[from] = 0;
    visited[from] = true;
    stack.push(from);

    while (stack.size() > 0) {
        int cur = stack.top();
        stack.pop();
        for (int id : getUser(cur)->getFriends()) {
            if (visited[id] == false) {
                stack.push(id);
                visited[id] = true;
                prev[id] = cur;
                dist[id] = dist[cur] + 1;
                if(dist[id] == distance) {
                    to = id;
                    while (id != -1) {
                        returnVector.push_back(id);
                        id = prev[id];
                    }
                    std::reverse(returnVector.begin(), returnVector.end());
                    return returnVector;
                }
            }
        }
    }
    return returnVector;
}

std::vector<int> Network::suggestFriends(int who, int& score) {
    std::vector<int> returnVector;
    User* whoUser = getUser(who);
    std::set<int> whoSet = whoUser->getFriends();

    if (whoUser == nullptr) { //If Who is not valid
        std::cout << "User not found" << std::endl;
        return std::vector<int>();
    }
    std::vector<int> scores(numUsers(), 0);

    for (int id : whoSet) { //Who user's friends ids
        User* whoFriend = getUser(id);
        for (int friendID : whoFriend->getFriends()) { //Friends of Who's friends
            if (whoSet.find(friendID) == whoSet.end() && scores[friendID] == 0 && friendID != who) { //Checks to make sure they aren't already friends and they weren't given a score yet
                int friendScore = findScore(whoSet, friendID);
                if (friendScore > score) {
                    score = friendScore;
                }
                scores[friendID] = friendScore;
            }
        }
    }
    for (int i = 0; i < scores.size(); i++) {
        if (scores[i] == score && whoSet.find(i) == whoSet.end()) { //If whoset is a set of aled montes's friends, then
            returnVector.push_back(i);
        }
    }
    return returnVector;
}

//Finds id friends that match with friendsList
//Helper function
int Network::findScore(std::set<int> friendsList, int id) {
    User* user = getUser(id);
    int score = 1;
    for (int friendID : user->getFriends()) {
        if (friendsList.find(friendID) != friendsList.end()) { //friendsList is aled montes's friends, id is a friend of aled's friend's id
            score++;
        }
    }
    return score;
}


std::vector<std::vector<int> > Network::groups() {
    std::vector<bool> visited(numUsers(), false);
    std::stack<int> stack;
    std::vector<std::vector<int> > returnVector;
    for (User* user : users_) {
        std::vector<int> toBeAdded;
        int userId = user->getId();
        if(visited[userId] == false) {
            stack.push(userId);
            visited[userId] = true;
            toBeAdded.push_back(userId);

            while(!stack.empty()) {
                int cur = stack.top();
                stack.pop();
                for (int id : getUser(cur)->getFriends()) {
                    if(visited[id] == false) {
                        toBeAdded.push_back(id);
                        visited[id] = true;
                        stack.push(id);
                    }
                }
            }

        returnVector.push_back(toBeAdded);
        }
    }
    


    return returnVector;
}
//Adds a new post to ownerId user
//pre: ownerId >= 0
//post: user's messages_ vector has a post added to it
void Network::addPost(int ownerId, std::string message, int likes, bool isIncoming, std::string authorName, bool isPublic) {
    User* u = getUser(ownerId);
    std::vector<Post*> posts = u->getPosts();
    int messageId = nextMsgId;
    nextMsgId++;
    if (isIncoming) {
        IncomingPost* ip = new IncomingPost(messageId, ownerId, message, likes, isPublic, authorName);
        u->addPost(ip);
    } else {
        Post* p = new Post(messageId, ownerId, message, likes);
        u->addPost(p);
    }
}

//Calls User's getPostString method and returns the result
//pre: none
//post: none
std::string Network::getPostsString(int ownerId, int howMany, bool showOnlyPublic) {
    User* u = getUser(ownerId);
    return u->getPostsString(howMany, showOnlyPublic);
}


//Reads posts from a file 
//pre: none
//post: returns -1 if a file is not found
int Network::readPosts(char* fname) {
    std::ifstream ThisFile(fname);

    if (!ThisFile) {
        return -1;
    }
    
    std::string temp;
    getline(ThisFile, temp);
    int numPosts = std::stoi(temp);
    while (getline(ThisFile, temp)) {
        int messageId = std::stoi(temp);
        getline(ThisFile, temp);
        std::string message = temp;
        message = message.substr(1);
        getline(ThisFile, temp);
        int ownerId = std::stoi(temp);
        getline(ThisFile, temp);
        int likes = std::stoi(temp);
        getline(ThisFile, temp); //Public/Private or blank
        temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
        if (!(temp == "")) { //If not blank
            bool isPublic;
            if (temp == "public") {
                isPublic = true;
            } else if (temp == "private") {
                isPublic = false;
            }
            getline(ThisFile, temp); //authorName
            std::string authorName = temp.substr(1);

            Network::addPost(ownerId, message, likes, true, authorName, isPublic);
        } else {
            getline(ThisFile, temp); //blank
            Network::addPost(ownerId, message, likes, false, "", true);
            
        }
    } 
    
    return 0;
}

//Writes posts to a file
//pre: none
//post: returns -1 if a file is not found
int Network::writePosts(char* fname) { 
    std::ofstream ThisFile(fname);

    if (!ThisFile) {
        return -1;
    }
    std::vector<Post*> allPosts;
    for (User* u : users_) {
        for (Post* p : u->getPosts()) {
            allPosts.push_back(p);
        }
    }
    std::sort(allPosts.begin(), allPosts.end(), comparePosts);
    ThisFile << std::to_string(allPosts.size()) + "\n";
    for(Post* p : allPosts) {
        ThisFile << std::to_string(p->getMessageId()) + "\n";
        ThisFile << "\t" + p->getMessage() + "\n";
        ThisFile << "\t" + std::to_string(p->getOwnerId()) + "\n";
        ThisFile << "\t" + std::to_string(p->getLikes()) + "\n";
        if (p->getAuthor() == "") { //Not Incoming
            ThisFile << "\n\n";
        } else {
            if (p->getIsPublic() == true) {
                ThisFile << "\tpublic" << "\n";
            } else {
                ThisFile << "\tprivate" << "\n";
            }
            ThisFile << "\t" << p->getAuthor() << "\n";
        }
    }
    
    return 0;
}

bool Network::comparePosts(Post* p1, Post* p2) {
    return p1->getMessageId() < p2->getMessageId();
}

void getPosts() {
}
