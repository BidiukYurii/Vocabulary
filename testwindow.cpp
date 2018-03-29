#include "testwindow.h"
#include "ui_testwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
TestWindow::TestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);
    initConnection();
}

void TestWindow::initConnection()
{
    connect(ui->openFileBtn,SIGNAL(clicked()),this,SLOT(slotOpenFile()));
}
TestWindow::~TestWindow()
{
    delete ui;
}
void TestWindow::slotOpenFile()
{
    qDebug() << "slotOpen";
    nameFile = QFileDialog::getOpenFileName(this,tr("Open file"));
    QFile *file;
    if(!nameFile.isEmpty())
    {
        file = new QFile(nameFile);
        if(!file->open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        if(_dictionery.fillDictionery(*file))
        {
            ui->layoutTest->setEnabled(true);
            updateWord();
        }
        file->close();

    }


}
void TestWindow::setEngToUkrMode()
{
    _MODE = modes::ENGTOUKR;
    connect(ui->chekBtn,SIGNAL(clicked()),this,SLOT(slotChekEngToUkr()));
    connect(ui->translatedWordET,SIGNAL(editingFinished()),this,SLOT(slotChekEngToUkr()));
}
void TestWindow::setUkrToEngMode()
{
    _MODE = modes::UKRTOENG;
    connect(ui->chekBtn,SIGNAL(clicked()),this,SLOT(slotChekUkrToEng()));
    connect(ui->translatedWordET,SIGNAL(editingFinished()),this,SLOT(slotChekUkrToEng()));
}
void TestWindow::slotChekUkrToEng()
{
    if(ui->translatedWordET->text()==_dictionery.getENGWord(ui->wordForTranslate->text()))
    {
        ui->answer->setText("Correct!");
    }else
    {
        ui->answer->setText("Incorrect!\n Correct answer: "+
                            _dictionery.getENGWord(ui->wordForTranslate->text()));
    }
    ui->translatedWordET->clear();
    QString engWord = _dictionery.getRandomPair().second;
    ui->wordForTranslate->setText(engWord);
}
void TestWindow::slotChekEngToUkr()
{
    if(ui->translatedWordET->text()==_dictionery.getUkrWord(ui->wordForTranslate->text()))
    {
        ui->answer->setText("Correct!");
        if(ui->checkBox->isChecked())
            delMode();
    }else
    {
        ui->answer->setText("Incorrect!\n Correct answer: "+
                            _dictionery.getUkrWord(ui->wordForTranslate->text()));
    }
    ui->translatedWordET->clear();
    QString engWord = _dictionery.getRandomPair().first;
    ui->wordForTranslate->setText(engWord);

}
void TestWindow::updateWord()
{
    QString engWord;
    if(_MODE==modes::ENGTOUKR)
    {
        engWord = _dictionery.getRandomPair().first;
    }else
    {
        engWord = _dictionery.getRandomPair().second;
    }
    ui->wordForTranslate->setText(engWord);
}
void TestWindow::slotClear()
{
    _dictionery.clear();
    ui->wordForTranslate->clear();
    ui->answer->clear();
}
void TestWindow::delMode()
{
    QString temp_data;
    if(_MODE == modes::ENGTOUKR)
    {
        temp_data = ui->wordForTranslate->text();

    }else
    {
        temp_data = _dictionery.getENGWord(ui->wordForTranslate->text());

    }
    _dictionery.deleteWord(temp_data);
}

