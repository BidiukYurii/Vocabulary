#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "testwindow.h"
namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT
private:
    MainWindow *_mainWindow;
    TestWindow *_testWindow;
    Ui::MenuWindow *ui;

    void initConnection();

public:
    explicit MenuWindow(QWidget *parent = 0);
    ~MenuWindow();
public slots:
    void onStartAddWords();
    void slotStartTest();

};

#endif // MENUWINDOW_H
