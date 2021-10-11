#include <iostream>
#include "PCB_s_1.h"
int main() {
    PCB_1::PCB pl;
    pl.arr[0].exist = true;
    pl.arr[0].connect = 8;
    pl.print(std::cout);
    std::cout << std::endl;
    return 0;
}
