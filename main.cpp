#include "mainwindow.h"

#include <QApplication>
#include "notepad.h"
#include "searchpanel.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Notepad notepad;
    notepad.show();

    return a.exec();
}
