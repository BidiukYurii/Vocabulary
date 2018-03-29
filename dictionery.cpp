#include "dictionery.h"
#include <utility>
#include <map>
Dictionery::Dictionery()
{

}
void Dictionery::addWord(QString word, QString translate)
{
    _words.insert(word, translate);
}
QString Dictionery::getENGWord(QString word)
{
    return _words.key(word);
}
QString Dictionery::getUkrWord(QString word)
{
    return _words.value(word);
}
int Dictionery::getSize()
{
    return _words.size();
}
QPair<QString,QString> Dictionery::getRandomPair()
{
    int temp = rand() % _words.size();
    QMap<QString,QString>::Iterator iter = _words.begin();
    return QPair<QString,QString>((iter+temp).key(),(iter+temp).value());
}
void Dictionery::clear()
{
    _words.clear();
}
QMap<QString, QString>::Iterator Dictionery::begin()
{
    return _words.begin();
}
QMap<QString, QString>::Iterator Dictionery::end()
{
    return _words.end();
}
void Dictionery::saveToFile(QTextStream& textStream)
{
    QMap<QString,QString>::Iterator iter = _words.begin();
    while (iter!=_words.end())
    {
        textStream<<iter.key()<<"\t"<<iter.value();
        textStream<<"\r\n";
        ++iter;
    }
}
bool Dictionery::fillDictionery(QFile& file)
{
    QString line;
    if(file.isReadable())
    {
        QTextStream inStream(&file);
        do
        {
            line = inStream.readLine();
            if(!line.isEmpty())
            {
                QString word1 = line.section("\t",0,0),
                        word2 = line.section("\t",1,1);

                addWord(word1,word2);
            }
        }while(!line.isNull());
        return true;
    }
    return false;
}
void Dictionery::deleteWord(QString& key)
{
    _words.remove(key);
}
