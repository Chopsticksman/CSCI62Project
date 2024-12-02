#ifndef NETWORK_H
#define NETWORK_H
#include "post.h"
#include "user.h"
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

class Network
{
    std::vector<User *> users_;
    int nextMsgId = 0;

public:
    //Default constructor
    //pre: none
    //post: creates an empty users_ list Network
    Network();

    std::vector<User *> getUsers() { return users_; }
    //Method that takes in an id int and returns a User pointer
    //pre: none
    //post: nullptr if not found, user pointer if found
    User *getUser(int id);

    //Adds a user to users_ vector
    //pre: Takes in a user pointer
    //post: adds the user pointer to users_ vector
    void addUser(User *user);

    //With the names of two users,
    //add them to both user's friends_ set if not there.
    //pre: two strings in first name last name format
    //post: -1 if at least one user is not found, 0 otherwise
    int addConnection(std::string s1, std::string s2);

    //With the names of two users,
    //remove them from both user's friends_ set if there.
    //pre: two strings in first name last name format
    //post: -1 if at least one user is not found, 0 otherwise
    int deleteConnection(std::string s1, std::string s2);

    //Given a name, returns a user's id if found, -1 otherwise
    //pre: requires a string
    //post: returns an int depending on if an id was found or not
    int getId(std::string name);

    //Returns the number of users on the network
    //pre: none
    //post: returns size of users_
    int numUsers();

    //Initializes all of the network's information from a file.
    //Parameter is in char*, or a c string for the file name
    //pre: file has to exist
    //post: adds users to users_ based on file input
    void readUsers(char *fname);

    //Writes all of the network's information to a file.
    //Parameter is in char*, or a c string for the file name
    //pre: none
    //post: writes the information in users_ to the file given.
    void writeUsers(char *fname);

    //Returns a vector starting with from and ending with to,
    //giving their shortest distance from each other.
    //pre: none
    //post: returns a vector. Empty if not connected.
    std::vector<int> shortestPath(int from, int to);

    //Finds a user whose relational distance is equal to the distance parameter.
    //Returns the shortest path between them. Uses DFS for optimization.
    //pre: distance >= 0
    //post: changes the to param to the found users id. Returns the shortest path vector.
    std::vector<int> distanceUser(int from, int &to, int distance);

    //Returns a list of friend suggestions depending on mutual friends
    //pre: none
    //post: changes score param to the highest # of mutual friends found
    //and returns an empty vector if no suggestions exist, score = 0
    std::vector<int> suggestFriends(int who, int &score);

    //Returns the number of friends ID has in friendsList
    //Helper function
    //pre: none
    //post: returns the # of friends
    int findScore(std::set<int> friendsList, int id);

    //Returns a list of the connected nodes(users) in the network.
    //Uses DFS to connect components of the graph.
    //pre: none
    //post: returns a vector of vectors of ids
    std::vector<std::vector<int> > groups();

    //Adds a new post to ownerId user
    //pre: ownerId >= 0
    //post: user's messages_ vector has a post added to it
    void addPost(int ownerId,
                 std::string message,
                 int likes,
                 bool isIncoming,
                 std::string authorName,
                 bool isPublic);

    //Calls User's getPostString method and returns the result
    //pre: none
    //post: none
    std::string getPostsString(int ownerId, int howMany, bool showOnlyPublic);

    //Reads a post from a file
    //pre: none
    //post: returns -1 if a file is not found
    int readPosts(char *fname);

    //Writes a post to a file
    //pre: none
    //post: returns -1 if a file is not found
    int writePosts(char *fname);

    static bool comparePosts(Post *p1, Post *p2);

    std::vector<Post *> getPosts();
};

#endif
