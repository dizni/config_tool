#include "config_tool.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Config_Tool w;
    w.show();

    return a.exec();
}
