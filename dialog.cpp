#include "dialog.h"
#include "ui_dialog.h"
using namespace std;
//#include <algorithm>
//#include <iostream>
#include <fstream>
//#include <iterator>
#include <QFile>
#include <QTextStream>
template <class T>
void ReadDataFile(const char* pFilename, list<T>& pDataList)
{
    pDataList.clear();
    ifstream inFile(pFilename, std::ios::in);
    if (inFile.good())
    {
        std::copy(istream_iterator<T>(inFile), istream_iterator<T>(), back_insert_iterator<list<T> >(pDataList));
        inFile.close();
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    std::list<int> my_list = { 12, 5, 10, 9 };
    ReadDataFile("/home/viktor/my_projects_qt_2/iz_file_v_massiv/list.txt", my_list);
    // тут прочитали из файла в список а если из файла в textedit?
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    QString result; // textEdit содержит строку, значит делаем строковую переменную, пока пустую
//    for (unsigned long i = 0; i < my_list.size(); ++i) // Проходим по номерам всех элементов списка
//    {
//        result += my_list.at(i) + QString("\n"); // Добавляем в результирующую строку очередной элемент списка и перевод строки (чтобы каждый элемент с новой строки был)
//    }
//    ui->textEdit->append ( result); // Присваиваем тексту эдита полученную строку и вуаля
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //   int lineNum = 0;
    QFile inputFile("/home/viktor/my_projects_qt_2/iz_file_v_massiv/list.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
      //  QString pepoles[1000];
   //     while ( !in.atEnd() && lineNum < my_list.size())
       // for (unsigned long  x=0; x< my_list.size();x++ )
        for (int n : my_list)
        {
            QString line = QString::number(n);
            // pepoles[lineNum++] = line;
            ui->textEdit->append ( line);
        }
        
        
        // перебор в цикле
    }
///     
}

Dialog::~Dialog()
{
    delete ui;
}


