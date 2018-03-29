#ifndef DICTIONERY_H
#define DICTIONERY_H
#include <map>
#include <QString>
#include <QMap>
#include <QTextStream>
#include <QFile>

class Dictionery
{
private:
    QMap <QString, QString> _words;
public:  
    Dictionery();

    void addWord(QString word,QString tranlate);
    QString getENGWord(QString word);
    QString getUkrWord(QString word);

    int getSize();
    void deleteWord(QString &key);
    QPair<QString,QString> getRandomPair();
    void clear();
    QMap<QString, QString>::Iterator begin();
    QMap<QString, QString>::Iterator end();
    void saveToFile(QTextStream& textStream);

    bool fillDictionery(QFile& file);
};

#endif // DICTIONERY_H
