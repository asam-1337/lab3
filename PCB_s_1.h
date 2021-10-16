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
        int x;
        int y;
        contact(){
            exist = false;
            type = false;
            connect = -1;
            x = 0;
            y = 0;
        }
        contact(bool v_type, int v_x, int v_y) {
            exist = true;
            type = v_type;
            connect = -1;
            x = v_x;
            y =v_y;
        }
    };

    class PCB {
    private:
        static const int sz = 10;
        int curr_sz;
        contact arr[sz];
    public:
        PCB() : curr_sz(0) {};

        static int getSZ() {return sz;}
        contact * getARR() {return arr;}

        int create_contact(bool type, int x, int y);
        int establish_connect(int name1, int name2);
        int add_contact(const contact & src);

        int correction_check(int name1, int name2) const;
        int get_track_length(int name1, int name2) const;
        PCB & select_group(int type) const;
        std::ostream & print(std::ostream& buff) const;
    };
}
#endif //LAB3_PCB_S_1_H
