#include <QCoreApplication>
#include <QTextStream>
//#include <iostream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    std::cout << "Qt version " << qVersion() << std::endl;
    QTextStream out(stdout);

    QString str = "love";
    str.append(" You");
    str.prepend("Allah ");
    out << str << Qt::endl;


    out << "The string has: " << str.size() << " characters" << Qt::endl;
    out << str.toLower() << Qt::endl;
    out << str.toUpper() << Qt::endl;


    return a.exec();
}
