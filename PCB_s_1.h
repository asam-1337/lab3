//
// Created by sam on 08.10.2021.
//

#ifndef LAB3_PCB_S_1_H
#define LAB3_PCB_S_1_H
#include <iostream>

namespace PCB_1 {
    struct contact {
        bool exist;
        bool type; //F - out, T - in
        int connect;
        double x;
        double y;
        contact(){
            exist = false;
            type = false;
            connect = -1;
            x = 0;
            y = 0;
        }
    };

    class PCB {
    public:
        static const int sz = 10;
        contact arr[sz];
    public:
        PCB(){}
        int create_contact(bool type, double x, double y);
        int establish_connect(int name1, int name2);
        int add_contact(const contact & src);
        int correction_check(int name1, int name2);
        int get_track_length(int name1, int name2);
        void select_group(int type);
        std::ostream & print(std::ostream& buff);
    };
}
#endif //LAB3_PCB_S_1_H
