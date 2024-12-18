#include "socialnetworkwindow.h"
#include "network.h"
#include "post.h"
#include "ui_socialnetworkwindow.h"
#include "user.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

Network n;
User *curUser;
User *shownUser;
std::string reaction;
int currentMsgId;

SocialNetworkWindow::SocialNetworkWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SocialNetworkWindow)
{
    ui->setupUi(this);
    ui->profileLabel->hide();
    ui->friendsListTable->hide();
    ui->postButton1->hide();
    ui->postButton2->hide();
    ui->postButton3->hide();
    ui->postButton4->hide();
    ui->postButton5->hide();
    ui->postButton1->setStyleSheet("text-align: left;");
    ui->postButton2->setStyleSheet("text-align: left;");
    ui->postButton3->setStyleSheet("text-align: left;");
    ui->postButton4->setStyleSheet("text-align: left;");
    ui->postButton5->setStyleSheet("text-align: left;");
    ui->clickedPostLabel->hide();
    ui->clickedPostLabel->setAlignment(Qt::AlignCenter);
    ui->likeButton->setStyleSheet("font-size: 50px;");
    ui->likeButton->hide();
    ui->likesLabel->setAlignment(Qt::AlignCenter);
    ui->likesLabel->hide();
    ui->reactionButton->hide();
    ui->reactionTable->hide();
    ui->reactionTable->setColumnCount(1);
    ui->reactionTable->setColumnWidth(0, 80);
    ui->reactionTable->setRowCount(10);
    ui->reactionTable->setItem(0, 0, new QTableWidgetItem(QString::fromStdString("😂")));
    ui->reactionTable->setItem(1, 0, new QTableWidgetItem(QString::fromStdString("😢")));
    ui->reactionTable->setItem(2, 0, new QTableWidgetItem(QString::fromStdString("😭")));
    ui->reactionTable->setItem(3, 0, new QTableWidgetItem(QString::fromStdString("😠")));
    ui->reactionTable->setItem(4, 0, new QTableWidgetItem(QString::fromStdString("😐")));
    ui->reactionTable->setItem(5, 0, new QTableWidgetItem(QString::fromStdString("👍")));
    ui->reactionTable->setItem(6, 0, new QTableWidgetItem(QString::fromStdString("👎")));
    ui->reactionTable->setItem(7, 0, new QTableWidgetItem(QString::fromStdString("🤩")));
    ui->reactionTable->setItem(8, 0, new QTableWidgetItem(QString::fromStdString("🔥")));
    ui->reactionTable->setItem(9, 0, new QTableWidgetItem(QString::fromStdString("💯")));
    ui->confirmReactionButton->hide();
    ui->commentButton->hide();
    ui->commentBox->hide();
    ui->confirmCommentButton->hide();
    ui->friendsLabel->hide();
    ui->backButton->hide();
    ui->suggestionsLabel->hide();
    ui->suggestionsTable->hide();
    ui->addFriendButton->hide();
    ui->friendsListTable->setColumnCount(1);
    ui->friendsListTable->setColumnWidth(0, 215);
    ui->suggestionsTable->setColumnCount(2);
    ui->suggestionsTable->setColumnWidth(0, 180);
    ui->suggestionsTable->setColumnWidth(1, 50);
    ui->searchBar->hide();
    ui->searchButton->hide();
    ui->searchWarningLabel->hide();
    ui->myPostsButton->hide();
    ui->friendsPostsButton->hide();
    ui->trendingPostsButton->hide();
    ui->enterNameLabel2->hide();
    ui->enterNameText->hide();
    ui->enterYearLabel->hide();
    ui->enterYearText->hide();
    ui->enterZipLabel->hide();
    ui->enterZipText->hide();
    ui->createButton->hide();
    ui->postNameLabel1->hide();
    ui->postNameLabel2->hide();
    ui->postNameLabel3->hide();
    ui->postNameLabel4->hide();
    ui->postNameLabel5->hide();

    connect(ui->postButton1, &QPushButton::clicked, this, &SocialNetworkWindow::postClick1);
    connect(ui->postButton2, &QPushButton::clicked, this, &SocialNetworkWindow::postClick2);
    connect(ui->postButton3, &QPushButton::clicked, this, &SocialNetworkWindow::postClick3);
    connect(ui->postButton4, &QPushButton::clicked, this, &SocialNetworkWindow::postClick4);
    connect(ui->postButton5, &QPushButton::clicked, this, &SocialNetworkWindow::postClick5);
    connect(ui->likeButton, &QPushButton::clicked, this, &SocialNetworkWindow::likeClick);
    connect(ui->reactionButton, &QPushButton::clicked, this, &SocialNetworkWindow::openReactions);
    connect(ui->confirmReactionButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::confirmReactionClick);
    connect(ui->commentButton, &QPushButton::clicked, this, &SocialNetworkWindow::commentClick);
    connect(ui->confirmCommentButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::confirmCommentClick);
    connect(ui->loginButton, &QPushButton::clicked, this, &SocialNetworkWindow::loginButtonClick);
    connect(ui->backButton, &QPushButton::clicked, this, &SocialNetworkWindow::backButtonClick);
    connect(ui->addFriendButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::addFriendButtonClick);
    connect(ui->friendsListTable, SIGNAL(cellClicked(int, int)), this, SLOT(tableClick(int, int)));
    connect(ui->reactionTable, SIGNAL(cellClicked(int, int)), this, SLOT(reactionClick(int, int)));

    connect(ui->suggestionsTable,
            SIGNAL(cellClicked(int, int)),
            this,
            SLOT(suggestionsClick(int, int)));
    connect(ui->searchButton, &QPushButton::clicked, this, &SocialNetworkWindow::searchButtonClick);
    connect(ui->myPostsButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::myPostsButtonClick);
    connect(ui->friendsPostsButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::friendsPostsButtonClick);
    connect(ui->trendingPostsButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::trendingPostsButtonClick);
    connect(ui->createAccButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::createAccButtonClick);
    connect(ui->createButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::createAccount);
    n.readUsers("users.txt");
    n.readPosts("posts.txt");
}

SocialNetworkWindow::~SocialNetworkWindow()
{
    delete ui;
}

void SocialNetworkWindow::loginButtonClick()
{
    std::string name = ui->nameTextEdit->toPlainText().toStdString();
    if (n.getId(name) == -1) {
        ui->enterNameLabel->setText("User Not Found");
    } else {
        curUser = n.getUser(n.getId(name));
        shownUser = n.getUser(n.getId(name));
        ui->friendsLabel->show();
        ui->loginButton->hide();    //loginButton: the log in qpushbutton
        ui->createAccButton->hide();
        ui->enterNameLabel->hide(); //enterNameLabel: the label right above the text box
        ui->nameTextEdit->hide();   //nameTextEdit: the textedit box where the name is typed
        ui->profileLabel
            ->show(); //profileLabel: Label at the top of the window that says My Profile or shownuser's profile
        ui->friendsListTable->show(); //friendsListTable: Table that shows all your friends
        ui->suggestionsLabel->show(); //suggestionsLabel: lable for suggestions Table
        ui->suggestionsTable
            ->show(); //SuggestionsTable: Able to go to people's profiles, with adding in another column
        ui->searchBar->show();
        ui->searchButton->show();
        ui->myPostsButton->show();
        ui->friendsPostsButton->show();
        ui->trendingPostsButton->show();
        display();
    }
}

void SocialNetworkWindow::tableClick(int row, int column)
{
    int id = n.getId(ui->friendsListTable->item(row, column)->text().toStdString());
    shownUser = n.getUser(id);
    display();
    ui->myPostsButton->hide();
    ui->friendsPostsButton->hide();
    ui->trendingPostsButton->hide();
}

void SocialNetworkWindow::backButtonClick()
{
    shownUser = curUser;
    hideAll();
    ui->myPostsButton->show();
    ui->friendsPostsButton->show();
    ui->trendingPostsButton->show();
    display();
}

void SocialNetworkWindow::suggestionsClick(int row, int column)
{
    int id = n.getId(ui->suggestionsTable->item(row, 0)->text().toStdString());
    if (column == 0) {
        shownUser = n.getUser(id);
    } else if (column == 1) {
        curUser->addFriend(id);
        n.getUser(id)->addFriend(curUser->getId());
        n.writeUsers("users.txt");
    }
    display();
}

void SocialNetworkWindow::addFriendButtonClick()
{
    curUser->addFriend(shownUser->getId());
    shownUser->addFriend(curUser->getId());
    ui->addFriendButton->hide();
    n.writeUsers("users.txt");
    display();
}

void SocialNetworkWindow::searchButtonClick()
{
    std::string name = ui->searchBar->toPlainText().toStdString();
    shownUser = n.getUser(n.getId(name));
    if (n.getId(name) != -1) {
        display();
        ui->searchWarningLabel->hide();
        ui->searchBar->setText("");
    } else {
        ui->searchWarningLabel->show();
    }
    ui->myPostsButton->hide();
    ui->friendsPostsButton->hide();
    ui->trendingPostsButton->hide();
}

void SocialNetworkWindow::myPostsButtonClick()
{
    display();
}

void SocialNetworkWindow::friendsPostsButtonClick()
{

    ui->postButton1->hide();
    ui->postButton2->hide();
    ui->postButton3->hide();
    ui->postButton4->hide();
    ui->postButton5->hide();

    ui->postNameLabel1->hide();
    ui->postNameLabel2->hide();
    ui->postNameLabel3->hide();
    ui->postNameLabel4->hide();
    ui->postNameLabel5->hide();

    std::set<int> friends = curUser->getFriends();
    std::vector<User *> users = n.getUsers();
    std::vector<Post *> allFriendPosts;

    for (auto user : users) {
        if (friends.find(user->getId()) != friends.end()) {
            std::vector<Post *> friendPosts = user->getPosts();
            for (auto post : friendPosts) {
                if (post->getIsPublic()) {
                    allFriendPosts.push_back(post);
                }
            }
        }
    }

    std::sort(allFriendPosts.begin(), allFriendPosts.end(), [](Post* a, Post* b) {
        return a->getMessageId() > b->getMessageId();
    });

    std::vector<std::string> top5message;
    std::vector<std::string> top5owners;
    for (int i = 0; i < allFriendPosts.size(); i++) {
        top5message.push_back(allFriendPosts[i]->getMessage());
    }

    for (int i = 0; i < allFriendPosts.size(); i++) {
        int id = allFriendPosts[i]->getOwnerId();
        User *u = n.getUser(id);
        top5owners.push_back(u->getName());
    }

    for (int i = 0; i < top5message.size(); i++) {
        if (i == 0) {
            ui->postButton1->setText(QString::fromStdString(top5message[i]));
            ui->postButton1->show();
            ui->postNameLabel1->show();
            ui->postNameLabel1->setText(QString::fromStdString(" - " + top5owners[i]));
        } else if (i == 1) {
            ui->postButton2->setText(QString::fromStdString(top5message[i]));
            ui->postButton2->show();
            ui->postNameLabel2->show();
            ui->postNameLabel2->setText(QString::fromStdString(" - " + top5owners[i]));
        } else if (i == 2) {
            ui->postButton3->setText(QString::fromStdString(top5message[i]));
            ui->postButton3->show();
            ui->postNameLabel3->show();
            ui->postNameLabel3->setText(QString::fromStdString(" - " + top5owners[i]));
        } else if (i == 3) {
            ui->postButton4->setText(QString::fromStdString(top5message[i]));
            ui->postButton4->show();
            ui->postNameLabel4->show();
            ui->postNameLabel4->setText(QString::fromStdString(" - " + top5owners[i]));
        } else if (i == 4) {
            ui->postButton5->setText(QString::fromStdString(top5message[i]));
            ui->postButton5->show();
            ui->postNameLabel5->show();
            ui->postNameLabel5->setText(QString::fromStdString(" - " + top5owners[i]));
        }
    }

}

void SocialNetworkWindow::trendingPostsButtonClick()
{
    ui->postButton1->show();
    ui->postButton2->show();
    ui->postButton3->show();
    ui->postButton4->show();
    ui->postButton5->show();

    std::vector<User *> users = n.getUsers();
    std::vector<Post *> allPosts;

    for (auto user : users) {
        std::vector<Post *> userPosts = user->getPosts();
        for (auto post : userPosts) {
            if (post->getIsPublic()) {
                allPosts.push_back(post);
            }
        }
    }

    std::sort(allPosts.begin(), allPosts.end(), [](Post *a, Post *b) {
        return a->getLikes() > b->getLikes();
    });

    std::vector<std::string> top5message;
    std::vector<std::string> top5owners;
    for (int i = 0; i < 5; i++) {
        top5message.push_back(allPosts[i]->getMessage());
    }

    for (int i = 0; i < 5; i++) {
        int id = allPosts[i]->getOwnerId();
        User *u = n.getUser(id);
        top5owners.push_back(u->getName());
        std::cout << u->getName() << std::endl;
    }


    for (int i = 0; i < top5message.size(); i++) {
        if (i == 0) {
            ui->postButton1->setText(QString::fromStdString(top5message[i]));
            ui->postNameLabel1->show();
            ui->postNameLabel1->setText(QString::fromStdString(" - " + top5owners[i]));
        } else if (i == 1) {
            ui->postButton2->setText(QString::fromStdString(top5message[i]));
            ui->postNameLabel2->show();
            ui->postNameLabel2->setText(QString::fromStdString(" - " + top5owners[i]));
        } else if (i == 2) {
            ui->postButton3->setText(QString::fromStdString(top5message[i]));
            ui->postNameLabel3->show();
            ui->postNameLabel3->setText(QString::fromStdString(" - " + top5owners[i]));
        } else if (i == 3) {
            ui->postButton4->setText(QString::fromStdString(top5message[i]));
            ui->postNameLabel4->show();
            ui->postNameLabel4->setText(QString::fromStdString(" - " + top5owners[i]));
        } else if (i == 4) {
            ui->postButton5->setText(QString::fromStdString(top5message[i]));
            ui->postNameLabel5->show();
            ui->postNameLabel5->setText(QString::fromStdString(" - " + top5owners[i]));
        }
    }
}

void SocialNetworkWindow::createAccButtonClick() {
    ui->enterNameLabel2->show();
    ui->enterNameText->show();
    ui->enterYearLabel->show();
    ui->enterYearText->show();
    ui->enterZipLabel->show();
    ui->enterZipText->show();
    ui->createButton->show();

    ui->loginButton->hide();
    ui->createAccButton->hide();
    ui->enterNameLabel->hide();
    ui->nameTextEdit->hide();
}

int getLength(int num) {
    if (num == 0)
        return 1;
    int length = 0;
    while (num != 0) {
        num /= 10;
        length++;
    }
    return length;
}

void SocialNetworkWindow::createAccount() {
    std::string name = ui->enterNameText->toPlainText().toStdString();
    int zip = ui->enterZipText->toPlainText().toInt();
    int year = ui->enterYearText->toPlainText().toInt();
    std::set<int> friends;

    std::vector<User*> users = n.getUsers();

    int i = 0;
    for ( ; i < users.size(); i++) {
        if (users[i]->getName() == name) {
            ui->nameExistsLabel->show();
            ui->nameExistsLabel->setText(QString::fromStdString("Name already exists!"));
            return;
        }
    }

    if (i >= users.size()) {
        if (getLength(zip) != 5 || getLength(year) != 4) {
            ui->nameExistsLabel->show();
            ui->nameExistsLabel->setText(QString::fromStdString("Invalid year or zipcode!"));
            return;
        }
        User * newUser = new User(n.numUsers(), name, year, zip, friends);
        n.addUser(newUser);

        n.writeUsers("users.txt");
        ui->enterNameLabel2->hide();
        ui->enterNameText->hide();
        ui->enterYearLabel->hide();
        ui->enterYearText->hide();
        ui->enterZipLabel->hide();
        ui->enterZipText->hide();
        ui->createButton->hide();
        ui->nameExistsLabel->hide();

        ui->loginButton->show();
        ui->createAccButton->show();
        ui->enterNameLabel->show();
        ui->enterNameLabel->setText(QString::fromStdString("Enter your name"));
        ui->nameTextEdit->show();
    }
}

void SocialNetworkWindow::postClick1()
{
    ui->clickedPostLabel->setText(ui->postButton1->text());
    displayPost();
    for (Post *p : n.getPosts()) {
        if (p->getMessage() == ui->clickedPostLabel->text().toStdString()) {
            currentMsgId = p->getMessageId();
            ui->likesLabel->setText(QString::number(p->getLikes()));
        }
    }
}

void SocialNetworkWindow::postClick2()
{
    ui->clickedPostLabel->setText(ui->postButton2->text());
    displayPost();
    for (Post *p : n.getPosts()) {
        if (p->getMessage() == ui->clickedPostLabel->text().toStdString()) {
            currentMsgId = p->getMessageId();
            ui->likesLabel->setText(QString::number(p->getLikes()));
        }
    }
}

void SocialNetworkWindow::postClick3()
{
    ui->clickedPostLabel->setText(ui->postButton3->text());
    displayPost();
    for (Post *p : n.getPosts()) {
        if (p->getMessage() == ui->clickedPostLabel->text().toStdString()) {
            currentMsgId = p->getMessageId();
            ui->likesLabel->setText(QString::number(p->getLikes()));
        }
    }
}

void SocialNetworkWindow::postClick4()
{
    ui->clickedPostLabel->setText(ui->postButton4->text());
    displayPost();
    for (Post *p : n.getPosts()) {
        if (p->getMessage() == ui->clickedPostLabel->text().toStdString()) {
            currentMsgId = p->getMessageId();
            ui->likesLabel->setText(QString::number(p->getLikes()));
        }
    }
}

void SocialNetworkWindow::postClick5()
{
    ui->clickedPostLabel->setText(ui->postButton5->text());
    displayPost();
    for (Post *p : n.getPosts()) {
        if (p->getMessage() == ui->clickedPostLabel->text().toStdString()) {
            currentMsgId = p->getMessageId();
            ui->likesLabel->setText(QString::number(p->getLikes()));
        }
    }
}

void SocialNetworkWindow::likeClick()
{
    std::cout << currentMsgId << std::endl;
    ui->likeButton->setText("❤️");
    for (Post *p : n.getPosts()) {
        if (p->getMessageId() == currentMsgId) {
            p->setLikes(p->getLikes() + 1);
            ui->likesLabel->setText(QString::number(p->getLikes()));
            n.writePosts("posts.txt");
            break;
        }
    }
}

void SocialNetworkWindow::openReactions()
{
    if (!ui->reactionTable->isVisible()) {
        ui->reactionTable->show();
        ui->reactionButton->setText("Cancel");
    } else {
        ui->reactionTable->hide();
        ui->reactionButton->setText("Add Reaction");
        ui->confirmReactionButton->hide();
    }
}

void SocialNetworkWindow::reactionClick(int row, int column)
{
    reaction = ui->reactionTable->item(row, column)->text().toStdString();
    ui->confirmReactionButton->show();
}

void SocialNetworkWindow::confirmReactionClick()
{
    int messageId = n.getPosts().size();
    int ownerId;
    for (Post *p : n.getPosts()) {
        if (p->getMessageId() == currentMsgId) {
            ownerId = p->getOwnerId();
            reaction = p->getMessage() + ": " + curUser->getName() + " - " + reaction;
            break;
        }
    }
    Post *p = new IncomingPost(messageId, ownerId, reaction, 0, false, curUser->getName());
    curUser->addPost(p);
    n.writePosts("posts.txt");
    openReactions();
}

void SocialNetworkWindow::commentClick()
{
    if (!ui->commentBox->isVisible()) {
        ui->commentBox->show();
        ui->commentButton->setText("Cancel");
        ui->confirmCommentButton->show();
    } else {
        ui->commentBox->hide();
        ui->commentButton->setText("Add Comment");
        ui->confirmCommentButton->hide();
    }
}

void SocialNetworkWindow::confirmCommentClick()
{
    std::string message = ui->commentBox->toPlainText().toStdString();
    if (message != "") {
        int messageId = n.getPosts().size();
        int ownerId;
        for (Post *p : n.getPosts()) {
            if (p->getMessageId() == currentMsgId) {
                ownerId = p->getOwnerId();
                break;
            }
        }

        Post *p = new IncomingPost(messageId, ownerId, message, 0, false, curUser->getName());
        curUser->addPost(p);
        n.writePosts("posts.txt");
        commentClick();
    }
}

void SocialNetworkWindow::displayPost()
{
    hideAll();
    ui->backButton->show();
    ui->likeButton->setText("🤍");
    ui->likeButton->show();
    ui->likesLabel->show();
    ui->clickedPostLabel->show();
    ui->reactionButton->show();
    ui->reactionButton->setText("Add Reaction");
    ui->commentButton->show();
    ui->commentButton->setText("Add Comment");

}

void SocialNetworkWindow::display()
{
    int friendsCount = shownUser->getFriends().size();
    ui->friendsListTable->setRowCount(friendsCount);
    int i = 0;
    for (int id : shownUser->getFriends()) {
        ui->friendsListTable
            ->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(n.getUser(id)->getName())));
        i++;
    }
    ui->clickedPostLabel->hide();
    ui->postButton1->hide();
    ui->postButton2->hide();
    ui->postButton3->hide();
    ui->postButton4->hide();
    ui->postButton5->hide();
    int msgIndex = shownUser->getPosts().size() - 1;
    for (int i = 0; i < 5; i++) {
        if (msgIndex == -1) {
            break;
        }

        if (shownUser->getPosts()[msgIndex]->getIsPublic() == true
            || (shownUser->getId() == curUser->getId() && shownUser->getPosts()[msgIndex]->getOwnerId() == curUser->getId())) {
            if (i == 0) {
                ui->postButton1->setText(
                    QString::fromStdString(shownUser->getPosts()[msgIndex]->getMessage()));
                ui->postButton1->show();
            } else if (i == 1) {
                ui->postButton2->setText(
                    QString::fromStdString(shownUser->getPosts()[msgIndex]->getMessage()));
                ui->postButton2->show();
            } else if (i == 2) {
                ui->postButton3->setText(
                    QString::fromStdString(shownUser->getPosts()[msgIndex]->getMessage()));
                ui->postButton3->show();
            } else if (i == 3) {
                ui->postButton4->setText(
                    QString::fromStdString(shownUser->getPosts()[msgIndex]->getMessage()));
                ui->postButton4->show();
            } else if (i == 4) {
                ui->postButton5->setText(
                    QString::fromStdString(shownUser->getPosts()[msgIndex]->getMessage()));
                ui->postButton5->show();
            }
        } else {
            i--;
        }

        msgIndex--;
    }
    if (shownUser->getId() == curUser->getId()) {
        ui->friendsLabel->show();
        ui->friendsListTable->show();
        ui->profileLabel->show();
        ui->searchBar->show();
        ui->searchButton->show();
        std::string profileLabelText = "            My Profile";
        ui->profileLabel->setText(QString::fromStdString(profileLabelText));
        ui->suggestionsLabel->show();
        ui->suggestionsTable->show();
        ui->addFriendButton->hide();
        ui->backButton->hide();
        int mutuals = -1;
        std::vector<int> suggestedFriends = n.suggestFriends(curUser->getId(), mutuals);
        int suggestionsCount = suggestedFriends.size();
        ui->suggestionsTable->setRowCount(suggestionsCount);
        i = 0;
        for (int id : suggestedFriends) {
            ui->suggestionsTable->setItem(i,
                                          0,
                                          new QTableWidgetItem(
                                              QString::fromStdString(n.getUser(id)->getName())));
            ui->suggestionsTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString("+")));
            i++;
        }

    } else {
        std::string profileLabelText = shownUser->getName() + "'s Profile";
        ui->profileLabel->setText(QString::fromStdString(profileLabelText));
        ui->suggestionsLabel->hide();
        ui->suggestionsTable->hide();
        if (curUser->getFriends().find(shownUser->getId()) == curUser->getFriends().end()) {
            ui->addFriendButton->show();
        }
        ui->backButton->show();
    }
    ui->postNameLabel1->hide();
    ui->postNameLabel2->hide();
    ui->postNameLabel3->hide();
    ui->postNameLabel4->hide();
    ui->postNameLabel5->hide();
}

void SocialNetworkWindow::hideAll()
{
    ui->addFriendButton->hide();
    ui->backButton->hide();
    ui->clickedPostLabel->hide();
    ui->enterNameLabel->hide();
    ui->friendsLabel->hide();
    ui->friendsListTable->hide();
    ui->friendsPostsButton->hide();
    ui->loginButton->hide();
    ui->myPostsButton->hide();
    ui->nameTextEdit->hide();
    ui->postButton1->hide();
    ui->postButton2->hide();
    ui->postButton3->hide();
    ui->postButton4->hide();
    ui->postButton5->hide();
    ui->profileLabel->hide();
    ui->searchBar->hide();
    ui->searchButton->hide();
    ui->searchWarningLabel->hide();
    ui->suggestionsLabel->hide();
    ui->suggestionsTable->hide();
    ui->trendingPostsButton->hide();
    ui->clickedPostLabel->hide();
    ui->likeButton->hide();
    ui->likesLabel->hide();
    ui->reactionButton->hide();
    ui->reactionTable->hide();
    ui->confirmReactionButton->hide();
    ui->commentButton->hide();
    ui->commentBox->hide();
    ui->confirmCommentButton->hide();
    ui->postNameLabel1->hide();
    ui->postNameLabel2->hide();
    ui->postNameLabel3->hide();
    ui->postNameLabel4->hide();
    ui->postNameLabel5->hide();
}
