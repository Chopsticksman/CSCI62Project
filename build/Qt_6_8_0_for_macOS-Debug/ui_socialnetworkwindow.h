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
    QLabel *recentPost1;
    QLabel *recentPost2;
    QLabel *recentPost3;
    QLabel *recentPost4;
    QLabel *recentPost5;
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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SocialNetworkWindow)
    {
        if (SocialNetworkWindow->objectName().isEmpty())
            SocialNetworkWindow->setObjectName("SocialNetworkWindow");
        SocialNetworkWindow->resize(1000, 850);
        centralwidget = new QWidget(SocialNetworkWindow);
        centralwidget->setObjectName("centralwidget");
        nameTextEdit = new QTextEdit(centralwidget);
        nameTextEdit->setObjectName("nameTextEdit");
        nameTextEdit->setGeometry(QRect(320, 240, 104, 71));
        enterNameLabel = new QLabel(centralwidget);
        enterNameLabel->setObjectName("enterNameLabel");
        enterNameLabel->setGeometry(QRect(310, 210, 141, 16));
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(320, 320, 100, 32));
        loginButton->setAutoFillBackground(false);
        loginButton->setFlat(false);
        profileLabel = new QLabel(centralwidget);
        profileLabel->setObjectName("profileLabel");
        profileLabel->setGeometry(QRect(290, 110, 171, 20));
        friendsListTable = new QTableWidget(centralwidget);
        friendsListTable->setObjectName("friendsListTable");
        friendsListTable->setGeometry(QRect(10, 160, 256, 192));
        recentPost1 = new QLabel(centralwidget);
        recentPost1->setObjectName("recentPost1");
        recentPost1->setGeometry(QRect(20, 430, 771, 21));
        recentPost2 = new QLabel(centralwidget);
        recentPost2->setObjectName("recentPost2");
        recentPost2->setGeometry(QRect(20, 470, 771, 16));
        recentPost3 = new QLabel(centralwidget);
        recentPost3->setObjectName("recentPost3");
        recentPost3->setGeometry(QRect(20, 510, 781, 16));
        recentPost4 = new QLabel(centralwidget);
        recentPost4->setObjectName("recentPost4");
        recentPost4->setGeometry(QRect(20, 550, 781, 16));
        recentPost5 = new QLabel(centralwidget);
        recentPost5->setObjectName("recentPost5");
        recentPost5->setGeometry(QRect(20, 590, 781, 16));
        friendsLabel = new QLabel(centralwidget);
        friendsLabel->setObjectName("friendsLabel");
        friendsLabel->setGeometry(QRect(90, 110, 81, 16));
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(730, 520, 61, 31));
        suggestionsTable = new QTableWidget(centralwidget);
        suggestionsTable->setObjectName("suggestionsTable");
        suggestionsTable->setGeometry(QRect(470, 160, 256, 192));
        suggestionsLabel = new QLabel(centralwidget);
        suggestionsLabel->setObjectName("suggestionsLabel");
        suggestionsLabel->setGeometry(QRect(530, 120, 121, 16));
        addFriendButton = new QPushButton(centralwidget);
        addFriendButton->setObjectName("addFriendButton");
        addFriendButton->setGeometry(QRect(710, 490, 81, 32));
        searchBar = new QTextEdit(centralwidget);
        searchBar->setObjectName("searchBar");
        searchBar->setGeometry(QRect(250, 30, 221, 31));
        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(480, 30, 51, 32));
        searchWarningLabel = new QLabel(centralwidget);
        searchWarningLabel->setObjectName("searchWarningLabel");
        searchWarningLabel->setGeometry(QRect(300, 70, 91, 16));
        myPostsButton = new QPushButton(centralwidget);
        myPostsButton->setObjectName("myPostsButton");
        myPostsButton->setGeometry(QRect(30, 370, 100, 32));
        friendsPostsButton = new QPushButton(centralwidget);
        friendsPostsButton->setObjectName("friendsPostsButton");
        friendsPostsButton->setGeometry(QRect(150, 370, 100, 32));
        trendingPostsButton = new QPushButton(centralwidget);
        trendingPostsButton->setObjectName("trendingPostsButton");
        trendingPostsButton->setGeometry(QRect(270, 370, 100, 32));
        SocialNetworkWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SocialNetworkWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 24));
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
        enterNameLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "Enter your name. ", nullptr));
        loginButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Login", nullptr));
        profileLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "            My Profile", nullptr));
        recentPost1->setText(QCoreApplication::translate("SocialNetworkWindow", "Recent Post 1", nullptr));
        recentPost2->setText(QCoreApplication::translate("SocialNetworkWindow", "Recent Post 2", nullptr));
        recentPost3->setText(QCoreApplication::translate("SocialNetworkWindow", "Recent Post 3", nullptr));
        recentPost4->setText(QCoreApplication::translate("SocialNetworkWindow", "Recent Post 4", nullptr));
        recentPost5->setText(QCoreApplication::translate("SocialNetworkWindow", "Recent post 5 ", nullptr));
        friendsLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "Friends List", nullptr));
        backButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Go Back", nullptr));
        suggestionsLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "Friend Suggestions", nullptr));
        addFriendButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Add Friend", nullptr));
        searchButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Search", nullptr));
        searchWarningLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "User not found!", nullptr));
        myPostsButton->setText(QCoreApplication::translate("SocialNetworkWindow", "My Posts", nullptr));
        friendsPostsButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Friends", nullptr));
        trendingPostsButton->setText(QCoreApplication::translate("SocialNetworkWindow", "Trending", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SocialNetworkWindow: public Ui_SocialNetworkWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCIALNETWORKWINDOW_H
