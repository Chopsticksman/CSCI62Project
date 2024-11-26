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
    SocialNetworkWindow(QWidget *parent = nullptr);
    ~SocialNetworkWindow();
    void loginButtonClick();
    void backButtonClick();
    void addFriendButtonClick();
    void searchButtonClick();
    void myPostsButtonClick();
    void friendsPostsButtonClick();
    void trendingPostsButtonClick();
    void display();

public slots:
    void tableClick(int row, int column);
    void suggestionsClick(int row, int column);

private:
    Ui::SocialNetworkWindow *ui;
};
#endif // SOCIALNETWORKWINDOW_H
