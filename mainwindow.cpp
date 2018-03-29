#include "mainwindow.h"
#include "dictionery.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initConnection();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initConnection()
{
    connect(ui->add_Button,SIGNAL(clicked()),this,SLOT(addSlot()));
    connect(ui->show_Button,SIGNAL(clicked()),this,SLOT(slotSave()));
    connect(ui->Eng_word_lineEdit,SIGNAL(editingFinished()),ui->Ukr_word_lineEdit,SLOT(setFocus()));
    connect(ui->Ukr_word_lineEdit,SIGNAL(editingFinished()),this,SLOT(addSlot()));

}
void MainWindow::addSlot()
{
    _dictionery.addWord(ui->Eng_word_lineEdit->text(),
                        ui->Ukr_word_lineEdit->text());
    ui->Eng_word_lineEdit->clear();
    ui->Ukr_word_lineEdit->clear();
    ui->Eng_word_lineEdit->setFocus();
}
void MainWindow::slotSave()
{
   QString Name = QFileDialog::getSaveFileName(this,
                                        tr("Save file"),
                                        "dictionery",
                                               "*.txt"
                                        );
   if(!Name.isEmpty())
   {
       QFile file(Name);
       if(file.open(QIODevice::WriteOnly))
       {
           QTextStream stream(&file);
           _dictionery.saveToFile(stream);
       }
       file.close();
   }
}
