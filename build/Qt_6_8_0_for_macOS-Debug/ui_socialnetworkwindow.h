/********************************************************************************
** Form generated from reading UI file 'socialnetworkwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCIALNETWORKWINDOW_H
#define UI_SOCIALNETWORKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SocialNetworkWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *nameTextEdit;
    QLabel *enterNameLabel;
    QPushButton *loginButton;
    QLabel *profileLabel;
    QTableWidget *friendsListTable;
    QLabel *friendsLabel;
    QPushButton *backButton;
    QTableWidget *suggestionsTable;
    QLabel *suggestionsLabel;
    QPushButton *addFriendButton;
    QTextEdit *searchBar;
    QPushButton *searchButton;
    QLabel *searchWarningLabel;
    QPushButton *myPostsButton;
    QPushButton *friendsPostsButton;
    QPushButton *trendingPostsButton;
    QPushButton *postButton1;
    QPushButton *postButton5;
    QPushButton *postButton4;
    QPushButton *postButton3;
    QPushButton *postButton2;
    QLabel *clickedPostLabel;
    QPushButton *likeButton;
    QLabel *likesLabel;
    QTableWidget *reactionTable;
    QPushButton *reactionButton;
    QPushButton *confirmReactionButton;
    QPushButton *commentButton;
    QPushButton *confirmCommentButton;
    QTextEdit *commentBox;
    QPushButton *createAccButton;
    QTextEdit *enterNameText;
    QTextEdit *enterZipText;
    QTextEdit *enterYearText;
    QLabel *enterNameLabel2;
    QLabel *enterZipLabel;
    QLabel *enterYearLabel;
    QPushButton *createButton;
    QLabel *nameExistsLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SocialNetworkWindow)
    {
        if (SocialNetworkWindow->objectName().isEmpty())
            SocialNetworkWindow->setObjectName("SocialNetworkWindow");
        SocialNetworkWindow->resize(992, 784);
        centralwidget = new QWidget(SocialNetworkWindow);
        centralwidget->setObjectName("centralwidget");
        nameTextEdit = new QTextEdit(centralwidget);
        nameTextEdit->setObjectName("nameTextEdit");
        nameTextEdit->setGeometry(QRect(350, 240, 104, 71));
        enterNameLabel = new QLabel(centralwidget);
        enterNameLabel->setObjectName("enterNameLabel");
        enterNameLabel->setGeometry(QRect(340, 200, 121, 20));
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(350, 320, 100, 32));
        loginButton->setAutoFillBackground(false);
        loginButton->setFlat(false);
        profileLabel = new QLabel(centralwidget);
        profileLabel->setObjectName("profileLabel");
        profileLabel->setGeometry(QRect(330, 110, 171, 16));
        friendsListTable = new QTableWidget(centralwidget);
        friendsListTable->setObjectName("friendsListTable");
        friendsListTable->setGeometry(QRect(10, 160, 256, 192));
        friendsLabel = new QLabel(centralwidget);
        friendsLabel->setObjectName("friendsLabel");
        friendsLabel->setGeometry(QRect(90, 110, 81, 16));
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(730, 632, 61, 31));
        suggestionsTable = new QTableWidget(centralwidget);
        suggestionsTable->setObjectName("suggestionsTable");
        suggestionsTable->setGeometry(QRect(530, 160, 256, 192));
        suggestionsLabel = new QLabel(centralwidget);
        suggestionsLabel->setObjectName("suggestionsLabel");
        suggestionsLabel->setGeometry(QRect(610, 110, 121, 16));
        addFriendButton = new QPushButton(centralwidget);
        addFriendButton->setObjectName("addFriendButton");
        addFriendButton->setGeometry(QRect(710, 600, 81, 32));
        searchBar = new QTextEdit(centralwidget);
        searchBar->setObjectName("searchBar");
        searchBar->setGeometry(QRect(290, 30, 221, 31));
        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(520, 30, 51, 32));
        searchWarningLabel = new QLabel(centralwidget);
        searchWarningLabel->setObjectName("searchWarningLabel");
        searchWarningLabel->setGeometry(QRect(360, 70, 91, 16));
        myPostsButton = new QPushButton(centralwidget);
        myPostsButton->setObjectName("myPostsButton");
        myPostsButton->setGeometry(QRect(30, 370, 100, 32));
        friendsPostsButton = new QPushButton(centralwidget);
        friendsPostsButton->setObjectName("friendsPostsButton");
        friendsPostsButton->setGeometry(QRect(150, 370, 100, 32));
        trendingPostsButton = new QPushButton(centralwidget);
        trendingPostsButton->setObjectName("trendingPostsButton");
        trendingPostsButton->setGeometry(QRect(270, 370, 100, 32));
        postButton1 = new QPushButton(centralwidget);
        postButton1->setObjectName("postButton1");
        postButton1->setGeometry(QRect(15, 420, 771, 32));
        postButton1->setLayoutDirection(Qt::LeftToRight);
        postButton1->setAutoFillBackground(false);
        postButton1->setFlat(true);
        postButton5 = new QPushButton(centralwidget);
        postButton5->setObjectName("postButton5");
        postButton5->setGeometry(QRect(15, 620, 771, 32));
        postButton5->setLayoutDirection(Qt::LeftToRight);
        postButton5->setAutoFillBackground(false);
        postButton5->setFlat(true);
        postButton4 = new QPushButton(centralwidget);
        postButton4->setObjectName("postButton4");
        postButton4->setGeometry(QRect(15, 570, 771, 32));
        postButton4->setLayoutDirection(Qt::LeftToRight);
        postButton4->setAutoFillBackground(false);
        postButton4->setFlat(true);
        postButton3 = new QPushButton(centralwidget);
        postButton3->setObjectName("postButton3");
        postButton3->setGeometry(QRect(15, 520, 771, 32));
        postButton3->setLayoutDirection(Qt::LeftToRight);
        postButton3->setAutoFillBackground(false);
        postButton3->setFlat(true);
        postButton2 = new QPushButton(centralwidget);
        postButton2->setObjectName("postButton2");
        postButton2->setGeometry(QRect(15, 470, 771, 32));
        postButton2->setLayoutDirection(Qt::LeftToRight);
        postButton2->setAutoFillBackground(false);
        postButton2->setFlat(true);
        clickedPostLabel = new QLabel(centralwidget);
        clickedPostLabel->setObjectName("clickedPostLabel");
        clickedPostLabel->setGeometry(QRect(0, 90, 801, 20));
        clickedPostLabel->setStyleSheet(QString::fromUtf8(""));
        likeButton = new QPushButton(centralwidget);
        likeButton->setObjectName("likeButton");
        likeButton->setGeometry(QRect(640, 140, 64, 64));
        likeButton->setFlat(true);
        likesLabel = new QLabel(centralwidget);
        likesLabel->setObjectName("likesLabel");
        likesLabel->setGeometry(QRect(630, 210, 81, 20));
        reactionTable = new QTableWidget(centralwidget);
        reactionTable->setObjectName("reactionTable");
        reactionTable->setGeometry(QRect(610, 370, 121, 192));
        reactionButton = new QPushButton(centralwidget);
        reactionButton->setObjectName("reactionButton");
        reactionButton->setGeometry(QRect(620, 330, 100, 32));
        reactionButton->setAutoExclusive(false);
        reactionButton->setFlat(false);
        confirmReactionButton = new QPushButton(centralwidget);
        confirmReactionButton->setObjectName("confirmReactionButton");
        confirmReactionButton->setGeometry(QRect(620, 570, 101, 32));
        commentButton = new QPushButton(centralwidget);
        commentButton->setObjectName("commentButton");
        commentButton->setGeometry(QRect(90, 330, 100, 32));
        commentButton->setAutoExclusive(false);
        commentButton->setFlat(false);
        confirmCommentButton = new QPushButton(centralwidget);
        confirmCommentButton->setObjectName("confirmCommentButton");
        confirmCommentButton->setGeometry(QRect(87, 570, 101, 32));
        commentBox = new QTextEdit(centralwidget);
        commentBox->setObjectName("commentBox");
        commentBox->setGeometry(QRect(13, 410, 251, 161));
        createAccButton = new QPushButton(centralwidget);
        createAccButton->setObjectName("createAccButton");
        createAccButton->setGeometry(QRect(340, 350, 121, 32));
        enterNameText = new QTextEdit(centralwidget);
        enterNameText->setObjectName("enterNameText");
        enterNameText->setGeometry(QRect(340, 230, 121, 31));
        enterZipText = new QTextEdit(centralwidget);
        enterZipText->setObjectName("enterZipText");
        enterZipText->setGeometry(QRect(340, 290, 121, 31));
        enterYearText = new QTextEdit(centralwidget);
        enterYearText->setObjectName("enterYearText");
        enterYearText->setGeometry(QRect(340, 350, 121, 31));
        enterNameLabel2 = new QLabel(centralwidget);
        enterNameLabel2->setObjectName("enterNameLabel2");
        enterNameLabel2->setGeometry(QRect(340, 210, 111, 16));
        enterZipLabel = new QLabel(centralwidget);
        enterZipLabel->setObjectName("enterZipLabel");
        enterZipLabel->setGeometry(QRect(340, 270, 101, 16));
        enterYearLabel = new QLabel(centralwidget);
        enterYearLabel->setObjectName("enterYearLabel");
        enterYearLabel->setGeometry(QRect(340, 330, 101, 16));
        createButton = new QPushButton(centralwidget);
        createButton->setObjectName("createButton");
        createButton->setGeometry(QRect(350, 390, 100, 32));
        nameExistsLabel = new QLabel(centralwidget);
        nameExistsLabel->setObjectName("nameExistsLabel");
        nameExistsLabel->setGeometry(QRect(340, 180, 141, 20));
        SocialNetworkWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SocialNetworkWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 992, 24));
        SocialNetworkWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SocialNetworkWindow);
        statusbar->setObjectName("statusbar");
        SocialNetworkWindow->setStatusBar(statusbar);

        retranslateUi(SocialNetworkWindow);

        QMetaObject::connectSlotsByName(SocialNetworkWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SocialNetworkWindow)
    {
        SocialNetworkWindow->setWindowTitle(QCoreApplication::translate("SocialNetworkWindow", "SocialNetworkWindow", nullptr));
        nameTextEdit->setHtml(QCoreApplication::translate("SocialNetworkWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        enterNameLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "Enter your name", nullptr));
        loginButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Login", nullptr));
        profileLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "            My Profile", nullptr));
        friendsLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "Friends List", nullptr));
        backButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Go Back", nullptr));
        suggestionsLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "Friend Suggestions", nullptr));
        addFriendButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Add Friend", nullptr));
        searchButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Search", nullptr));
        searchWarningLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "User not found!", nullptr));
        myPostsButton->setText(QCoreApplication::translate("SocialNetworkWindow", "My Posts", nullptr));
        friendsPostsButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Friends", nullptr));
        trendingPostsButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Trending", nullptr));
        postButton1->setText(QString());
        postButton5->setText(QString());
        postButton4->setText(QString());
        postButton3->setText(QString());
        postButton2->setText(QString());
        clickedPostLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "                                                                                                  Clicked Post Text Here", nullptr));
        likeButton->setText(QCoreApplication::translate("SocialNetworkWindow", "\360\237\244\215", nullptr));
        likesLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "9 BILLION!!", nullptr));
        reactionButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Add Reaction", nullptr));
        confirmReactionButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Add", nullptr));
        commentButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Add Comment", nullptr));
        confirmCommentButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Comment", nullptr));
        createAccButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Create Account", nullptr));
        enterNameLabel2->setText(QCoreApplication::translate("SocialNetworkWindow", "Enter Name", nullptr));
        enterZipLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "Enter Zip Code", nullptr));
        enterYearLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "Enter Birth Year", nullptr));
        createButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Create", nullptr));
        nameExistsLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SocialNetworkWindow: public Ui_SocialNetworkWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCIALNETWORKWINDOW_H
