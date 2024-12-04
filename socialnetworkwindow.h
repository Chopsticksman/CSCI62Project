#ifndef SOCIALNETWORKWINDOW_H
#define SOCIALNETWORKWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class SocialNetworkWindow;
}
QT_END_NAMESPACE

class SocialNetworkWindow : public QMainWindow
{
    Q_OBJECT

public:
    //pre: none
    //post: new social network window
    SocialNetworkWindow(QWidget *parent = nullptr);

    //pre: none
    //post: social network window deconstructs
    ~SocialNetworkWindow();

    //pre: none
    //post: logs in a valid user
    void loginButtonClick();

    //pre: none
    //post: navigates back to the logged in user's profile
    void backButtonClick();

    //pre: none
    //post: adds the currently displayed user as a friend
    void addFriendButtonClick();

    //pre: none
    //post: navigates the the profile of the name in the search bar
    void searchButtonClick();

    //pre: none
    //post: displays posts of the current user
    void myPostsButtonClick();

    //pre: none
    //post: displays the 5 most recent posts from friend list
    void friendsPostsButtonClick();

    //pre: none
    //post: displays the 5 most liked posts from the entire network
    void trendingPostsButtonClick();

    //pre: none
    //post: dispalys form to create a new account
    void createAccButtonClick();

    //pre: length of zipcode has to be 5, birth year must be 4
    //post: adds new user to social network and writes to users.txt
    void createAccount();

    //pre: post 1 is displayed
    //post: navigates the reaction/comment page of first post
    void postClick1();

    //pre: post 2 is displayed
    //post: navigates the reaction/comment page of second post
    void postClick2();

    //pre: post 3 is displayed
    //post: navigates the reaction/comment page of third post
    void postClick3();

    //pre: post 4 is displayed
    //post: navigates the reaction/comment page of fourth post
    void postClick4();

    //pre: post 5 is displayed
    //post: navigates the reaction/comment page of fifth post
    void postClick5();

    //pre: none
    //post: increments likes of post by 1 and rewrites posts.txt
    void likeClick();

    //pre: none
    //post: opens up menu of reaction options
    void openReactions();

    //pre: none
    //post: adds reaction as an incoming post to the owner of post
    void confirmReactionClick();

    //pre: none
    //post: opens up input box to type in comment
    void commentClick();

    //pre: none
    //post: adds comment as an incoming post to the owner of the post
    void confirmCommentClick();

    //pre: none
    //post: displays current user's profile
    void display();

    //pre: none
    //post: displays reaction/comment/like options
    void displayPost();

    //pre: none
    //post: hides all the ui elements
    void hideAll();

public slots:
    void tableClick(int row, int column);
    void suggestionsClick(int row, int column);
    void reactionClick(int row, int column);

private:
    Ui::SocialNetworkWindow *ui;
};
#endif // SOCIALNETWORKWINDOW_H
