#include "post.h"

int messageId_;
int ownerId_;
std::string message_;
int likes_;
std::string author_; //IncomingPost
bool isPublic_;      //IncomingPost

//Post
Post::Post() {}

Post::Post(int messageId, int ownerId, std::string message, int likes)
{
    messageId_ = messageId;
    ownerId_ = ownerId;
    message_ = message;
    likes_ = likes;
}

std::string Post::toString()
{
    return message_ + " Liked by " + std::to_string(likes_) + " people.";
}

//GETTERS AND SETTERS

//returns messageId field
int Post::getMessageId()
{
    return messageId_;
}

//returns ownerId field
int Post::getOwnerId()
{
    return ownerId_;
}

//returns message field
std::string Post::getMessage()
{
    return message_;
}

//returns likes field
int Post::getLikes()
{
    return likes_;
}

//returns the author of the post (owner by default)
std::string Post::getAuthor()
{
    return "";
}

//returns whether this post is public or not
bool Post::getIsPublic()
{
    return true;
}

void Post::setLikes(int likes) {
    likes_ = likes;
}

//IncomingPost

//Default Constructor
//pre:none
//post:none
IncomingPost::IncomingPost()
    : Post()
{}

//Parameterized constructor with 6 params, uses Post constructor for 4
//pre: none
//post: sets all the fields
IncomingPost::IncomingPost(
    int messageId, int ownerId, std::string message, int likes, bool isPublic, std::string author)
    : Post(messageId, ownerId, message, likes)
{
    author_ = author;
    isPublic_ = isPublic;
}

//returns string [author_] wrote[private]: [Post:toString()]
//pre: none
//post: returns a string
std::string IncomingPost::toString()
{
    std::string returnString = author_ + " wrote";
    if (!isPublic_) {
        returnString += "(private)";
    }
    returnString += ": " + Post::toString();
    return returnString;
}

//gets and returns author_ field
std::string IncomingPost::getAuthor()
{
    return author_;
}

//gets and returns isPublic_ field
bool IncomingPost::getIsPublic()
{
    return isPublic_;
}
