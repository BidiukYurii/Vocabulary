#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dictionery.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void addSlot();
    void slotSave();
private:
    Ui::MainWindow *ui;
    Dictionery _dictionery;

    void initConnection();
};

#endif // MAINWINDOW_H
