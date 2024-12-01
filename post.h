#ifndef POST_H
#define POST_H
#include <set>
#include <string>
#include <vector>

class Post
{
    int messageId_;
    int ownerId_;
    std::string message_;
    int likes_;
    std::string author_; //IncomingPost
    bool isPublic_;      //IncomingPost
public:
    //Default Constructor
    //pre: none
    //post: none
    Post();

    //Parameterized Constructor that takes in 4 arguments
    //pre: none
    //post: sets fields to arguments
    Post(int messageId, int ownerId, std::string message, int likes);

    //returns a string "message" liked by "likes" people
    //pre: none
    //post: returns a string
    virtual std::string toString();

    //GETTERS AND SETTERS

    //returns messageId field
    int getMessageId();

    //returns ownerId field
    int getOwnerId();

    //returns message field
    std::string getMessage();

    //returns likes field
    int getLikes();

    //returns the author of the post (owner by default)
    virtual std::string getAuthor();

    //returns whether this post is public or not
    virtual bool getIsPublic();

    void setLikes(int likes);
};

class IncomingPost : public Post
{
    std::string author_;
    bool isPublic_;

public:
    //Default Constructor
    //pre:none
    //post:none
    IncomingPost();

    //Parameterized constructor with 6 params
    //pre: none
    //post: sets all the fields
    IncomingPost(int messageId,
                 int ownerId,
                 std::string message,
                 int likes,
                 bool isPublic,
                 std::string author);

    //returns string [author_] wrote[private]: [Post:toString()]
    //pre: none
    //post: returns a string
    virtual std::string toString();

    //gets and returns author_ field
    std::string getAuthor();

    //gets and returns isPublic_ field
    bool getIsPublic();
};
#endif
