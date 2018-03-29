#include "menuwindow.h"
#include "ui_menuwindow.h"
#include <QPushButton>
#include <QDebug>

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);

    initConnection();

}


MenuWindow::~MenuWindow()
{
    delete ui;
}
void MenuWindow::slotStartTest()
{
    //if(_testWindow)
      //  delete _testWindow;
    _testWindow = new TestWindow();
    if(sender()->objectName()==
            ui->EngToUkrBtn->objectName())
    {
        _testWindow->setEngToUkrMode();

    }else
    {
        _testWindow->setUkrToEngMode();
    }
    _testWindow->slotClear();
    _testWindow->show();
}

void MenuWindow::onStartAddWords()
{
    if(_mainWindow)
        delete _mainWindow;
    _mainWindow = new MainWindow();
    _mainWindow->show();
}
void MenuWindow::initConnection()
{
    connect(ui->addWordsBtn,SIGNAL(clicked()),this,SLOT(onStartAddWords()));
    connect(ui->UkrToEngButton,SIGNAL(clicked()),this,SLOT(slotStartTest()));
    connect(ui->EngToUkrBtn,SIGNAL(clicked()),this,SLOT(slotStartTest()));
}

