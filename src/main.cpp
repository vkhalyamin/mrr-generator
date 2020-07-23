#include "ui.h"
#include <QApplication>
#include <Qtcore>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ui ui;
    ui.show();

    return a.exec();
}
