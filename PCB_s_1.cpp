//
// Created by sam on 08.10.2021.
//

#include "PCB_s_1.h"
#include <cmath>

namespace PCB_1
{

    int PCB::create_contact(bool type, double x, double y)
    {
        for (auto & i : arr)
        {
            if (!i.exist)
            {
                i.exist = true;
                i.type = true;
                i.x = x;
                i.y = y;
                return 0;
            }
        }
        return 1;
    }

    int PCB::establish_connect(int name1, int name2)
    {
        if ((arr[name1].exist && arr[name2].exist) && (arr[name1].connect < 0 && arr[name2].connect < 0))
            if (arr[name1].type && !arr[name2].type || (!arr[name1].type && arr[name2].type))
            {
                arr[name1].connect = name2;
                arr[name2].connect = name1;
                return 0;
            }
        return 1;
    }
    int PCB::add_contact(const contact &src)
    {
        for (int i = 0; i < sz; i++) {
            if (!arr[i].exist) {
                arr[i].exist = src.exist;
                arr[i].type = src.type;
                arr[i].connect = src.connect;
                arr[i].x = src.x;
                arr[i].y = src.y;
                return 0;
            }
        }
        return 1;
    }

    int PCB::correction_check(int name1, int name2)
    {
        if (arr[name1].exist && arr[name2].exist)
            if ((arr[name1].type && !arr[name2].type)
            || (!arr[name1].type && arr[name2].type))
                return 0;
        return 1;

    }

    int PCB::get_track_length(int name1, int name2)
    {
        if (!correction_check(name1, name2))
        {
            sqrt(pow(arr[name1].x - arr[name2].x,2) + pow(arr[name1].x - arr[name2].y, 2));
            return 0;
        }
        return 1;
    }

    void PCB::select_group(int type)
    {
        int j = 0;
        contact tmp[10];
        for (int i = 0; i < sz && arr[i].exist; i++)
            if (arr[i].type = type) {
                tmp[j] = arr[i];
                j++;
            }
        print(std::cout);
    }

    std::ostream & PCB::print(std::ostream & buff)
    {
        buff << "number\t|\ttype\t|\tconnect\t|\tcoords" << std:: endl;
        for (int i = 0; arr[i].exist && i < sz; i++)
        {
            buff
            << i
            << "\t\t|\t" << arr[i].type
            << "\t\t|\t" << arr[i].connect
            << "\t\t|\t" << "(" << arr[i].x << ", " << arr[i].y << ")"
            << std::endl;
        }
        return buff;
    }
}
