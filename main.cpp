#include "notepad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // create instance of ntoepad
    Notepad notePad;
    // show notepad widget
    notePad.show();

    // start main loop
    return a.exec();
}
