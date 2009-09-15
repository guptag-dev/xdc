#include <QtCore/QCoreApplication>
#include "xdcstartup.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	new XDCStartup();

    return a.exec();
}
