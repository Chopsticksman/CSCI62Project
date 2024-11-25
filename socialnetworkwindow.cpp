#include "socialnetworkwindow.h"
#include "ui_socialnetworkwindow.h"
#include "user.h"
#include "post.h"
#include "network.h"
#include <string>
#include <iostream>
#include <vector>

Network n;
User* curUser;
User* shownUser;

SocialNetworkWindow::SocialNetworkWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SocialNetworkWindow)
{
    ui->setupUi(this);
    ui->profileLabel->hide();
    ui->friendsListTable->hide();
    ui->recentPost1->hide();
    ui->recentPost2->hide();
    ui->recentPost3->hide();
    ui->recentPost4->hide();
    ui->recentPost5->hide();
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
    connect(ui->loginButton, &QPushButton::clicked, this, &SocialNetworkWindow::loginButtonClick);
    connect(ui->backButton, &QPushButton::clicked, this, &SocialNetworkWindow::backButtonClick);
    connect(ui->addFriendButton, &QPushButton::clicked, this, &SocialNetworkWindow::addFriendButtonClick);
    connect(ui->friendsListTable, SIGNAL(cellClicked(int,int)), this, SLOT(tableClick(int,int)));
    connect(ui->suggestionsTable, SIGNAL(cellClicked(int,int)), this, SLOT(suggestionsClick(int,int)));
    n.readUsers("users.txt");
    n.readPosts("posts.txt");
}

SocialNetworkWindow::~SocialNetworkWindow()
{
    delete ui;
}

void SocialNetworkWindow::loginButtonClick() {
    std::string name = ui->nameTextEdit->toPlainText().toStdString();
    if (n.getId(name) == -1) {
        ui->enterNameLabel->setText("User Not Found");
    } else {
        curUser = n.getUser(n.getId(name));
        shownUser = n.getUser(n.getId(name));
        ui->friendsLabel->show();
        ui->loginButton->hide();  //loginButton: the log in qpushbutton
        ui->enterNameLabel->hide(); //enterNameLabel: the label right above the text box
        ui->nameTextEdit->hide(); //nameTextEdit: the textedit box where the name is typed
        ui->profileLabel->show(); //profileLabel: Label at the top of the window that says My Profile or shownuser's profile
        ui->friendsListTable->show(); //friendsListTable: Table that shows all your friends
        ui->suggestionsLabel->show(); //suggestionsLabel: lable for suggestions Table
        ui->suggestionsTable->show(); //SuggestionsTable: Able to go to people's profiles, with adding in another column
        display();
    }
}

void SocialNetworkWindow::tableClick(int row, int column) {
    int id = n.getId(ui->friendsListTable->item(row, column)->text().toStdString());
    shownUser = n.getUser(id);
    display();
}

void SocialNetworkWindow::backButtonClick() {
    shownUser = curUser;
    display();
}

void SocialNetworkWindow::suggestionsClick(int row, int column) {
    int id = n.getId(ui->suggestionsTable->item(row, 0)->text().toStdString());
    if (column == 0) {
        shownUser = n.getUser(id);
    } else if (column == 1) {
        curUser->addFriend(id);
        n.getUser(id)->addFriend(curUser->getId()
                                 );
        n.writeUsers("users.txt");
    }
    display();
}

void SocialNetworkWindow::addFriendButtonClick() {
    curUser->addFriend(shownUser->getId());
    shownUser->addFriend(curUser->getId());
    ui->addFriendButton->hide();
    n.writeUsers("users.txt");
    display();
}

void SocialNetworkWindow::display() {
    int friendsCount = shownUser->getFriends().size();
    ui->friendsListTable->setRowCount(friendsCount);
    int i = 0;
    for (int id : shownUser->getFriends()) {
        ui->friendsListTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(n.getUser(id)->getName())));
        i++;
    }
    ui->recentPost1->hide();
    ui->recentPost2->hide();
    ui->recentPost3->hide();
    ui->recentPost4->hide();
    ui->recentPost5->hide();
    int msgIndex = shownUser->getPosts().size()-1;
    for (int i = 0; i < 5; i++) {
        if (msgIndex == -1) {
            break;
        }
        if(shownUser->getPosts()[msgIndex]->getIsPublic() == true || shownUser->getId() == curUser->getId()) {
            if (i == 0) {
                ui->recentPost1->setText(QString::fromStdString(shownUser->getPosts()[msgIndex]->getMessage()));
                ui->recentPost1->show();
            } else if (i == 1) {
                ui->recentPost2->setText(QString::fromStdString(shownUser->getPosts()[msgIndex]->getMessage()));
                ui->recentPost2->show();
            } else if (i == 2) {
                ui->recentPost3->setText(QString::fromStdString(shownUser->getPosts()[msgIndex]->getMessage()));
                ui->recentPost3->show();
            } else if (i == 3) {
                ui->recentPost4->setText(QString::fromStdString(shownUser->getPosts()[msgIndex]->getMessage()));
                ui->recentPost4->show();
            } else if (i == 4) {
                ui->recentPost5->setText(QString::fromStdString(shownUser->getPosts()[msgIndex]->getMessage()));
                ui->recentPost5->show();
            }
        } else {
            i--;
        }

        msgIndex--;
    }
    if (shownUser->getId() == curUser->getId()) {
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
            ui->suggestionsTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(n.getUser(id)->getName())));
            ui->suggestionsTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString("+")));
            i++;
        }

    } else {
        std::string profileLabelText = shownUser->getName() + "'s Profile";
        ui->profileLabel->setText(QString::fromStdString(profileLabelText));
        ui->suggestionsLabel->hide();
        ui->suggestionsTable->hide();
        if(curUser->getFriends().find(shownUser->getId()) == curUser->getFriends().end()) {
            ui->addFriendButton->show();
        }
        ui->backButton->show();
    }
}

