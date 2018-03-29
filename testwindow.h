#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>
#include "dictionery.h"


namespace Ui {
class TestWindow;
}

class TestWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestWindow(QWidget *parent = 0);
    ~TestWindow();

private:
    enum modes{ENGTOUKR,UKRTOENG};
    int _MODE;
    Ui::TestWindow *ui;
    Dictionery _dictionery;
    QString nameFile;

    void updateWord();
    void initConnection();
    void delMode();
public slots:
    void setUkrToEngMode();
    void setEngToUkrMode();
    void slotOpenFile();
    void slotChekEngToUkr();
    void slotChekUkrToEng();
    void slotClear();
};

#endif // TESTWINDOW_H
