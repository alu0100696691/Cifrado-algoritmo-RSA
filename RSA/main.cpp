#include "rsa.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RSA w;
    w.show();
    
    return a.exec();
}
