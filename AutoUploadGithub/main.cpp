#include "myprocess.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyProcess w;
    w.show();
    w.setWindowTitle("Github上传程序");
    return a.exec();
}
