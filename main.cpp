#include "include/Library.h"
#include "include/main_interface.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Main_Interface mainInterface;
    mainInterface.show();
    return QApplication::exec();
}
