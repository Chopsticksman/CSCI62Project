#ifndef USER_H
#define USER_H
#include "post.h"
#include <cassert>
#include <iostream>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
class User
{
    int id_;
    std::string name_;
    int year_;
    int zip_;
    std::set<int> friends_;
    std::vector<Post *> messages_;

public:
    //An empty constructor for the User class
    //pre: none
    //post: creates a default user object
    User();

    //A constructor for the User class
    //pre: none
    //post: creates a user object with the values that have been passed in
    User(int id, std::string name, int year, int zip, std::set<int> friends);

    //A method that adds an id to the friends set
    //pre: none
    //post: If id is not in friends, then it is inserted
    void addFriend(int id);

    //A method that removes an id from the friends set
    //pre: none
    //post: if id is in friends, then it is removed
    void deleteFriend(int id);

    //Adds the Post pointer to the messages_ vector field.
    //pre: none
    //post: pushes post pointer argument to messages_ back
    void addPost(Post *post);

    //returns a string that shows the recent howMany Posts, showing all if
    //howMany is greater.
    //pre: howMany >= 0
    //post: none
    std::string getPostsString(int howMany, bool showOnlyPublic);

    //Getters and Setters
    int getId();

    std::string getName();

    int getYear();

    int getZip();

    std::set<int> &getFriends();

    std::vector<Post *> getPosts();
};

#endif
