#include "include/turing.h"
#include "include/Library.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Turing test;
    test.show();
    return QApplication::exec();
}
