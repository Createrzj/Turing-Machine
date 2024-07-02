#include "include/turing.h"
#include "include/Library.h"
#include "include/main_interface.h"
#include "include/knapsack.h"
#include "include/recur_knapsack.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Knapsack test;
    test.show();
//    Main_Interface mainInterface;
//    mainInterface.show();
//    Turing test;
//    test.show();
    return QApplication::exec();
}
