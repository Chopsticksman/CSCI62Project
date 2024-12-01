#include "user.h"
#include "post.h"
#include <vector>

int id_;
std::string name_;
int year_;
int zip_;
std::set<int> friends_;
std::vector<Post *> messages_;

//An empty constructor for the User class
//pre: none
//post: creates a default user object
User::User()
{
    id_ = 0;
    name_ = "";
    year_ = 0;
    zip_ = 0;
}

//A constructor for the User class
//pre: none
//post: creates a user object with the values that have been passed in
User::User(int id, std::string name, int year, int zip, std::set<int> friends)
{
    id_ = id;
    name_ = name;
    year_ = year;
    zip_ = zip;
    friends_ = friends;
}

//A method that adds an id to the friends set
//pre: none
//post: If id is not in friends, then it is inserted
void User::addFriend(int id)
{
    if (friends_.find(id) == friends_.end()) {
        friends_.insert(id);
    } else if (id == id_) {
        std::cout << "You cannot add yourself as a friend." << std::endl;
    } else {
        std::cout << "User is already in friends list." << std::endl;
    }
}

//A method that removes an id from the friends set
//pre: none
//post: if id is in friends, then it is removed
void User::deleteFriend(int id)
{
    if (friends_.find(id) != friends_.end()) {
        friends_.erase(id);
    } else {
        std::cout << "User not found in friends list." << std::endl;
    }
}

//Adds the Post pointer to the messages_ vector field.
//pre: none
//post: pushes post pointer argument to messages_ back
void User::addPost(Post *post)
{
    messages_.push_back(post);
}

//returns a string that shows the recent howMany Posts, showing all if
//howMany is greater.
//pre: howMany >= 0
//post: none
std::string User::getPostsString(int howMany, bool showOnlyPublic)
{
    std::string postsString;
    for (int i = messages_.size() - 1; i >= 0; i--) {
        if (howMany <= 0) {
            break;
        }
        //Post* p = (*messages_)[i];
        //postsString += p->toString() + "\n\n";
        postsString += messages_[i]->toString() + "\n\n";
        howMany--;
    }
    return postsString;
}

//Getters and Setters
int User::getId()
{
    return id_;
}

std::string User::getName()
{
    return name_;
}

int User::getYear()
{
    return year_;
}

int User::getZip()
{
    return zip_;
}

std::set<int> &User::getFriends()
{
    return friends_;
}

std::vector<Post *> User::getPosts()
{
    return messages_;
}
