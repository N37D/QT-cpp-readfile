#include "txtfunction.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TxtFunction w;
    w.show();

    return a.exec();
}
