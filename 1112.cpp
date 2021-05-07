#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>

class class_for_check_NE;

class class_for_check_NE
{
public:

    int mini, maxi;
//   проверяем что left not equal   this
    bool operator < (class_for_check_NE& l) const
    {
        if(maxi != l.maxi){return maxi < l.maxi;;};
        return mini < l.mini;
    }
};


class_for_check_NE massiv[100001];;

std::vector <class_for_check_NE> otbet;;

int main() {

    unsigned char n;;
    //ide ругается но это хак
    std::scanf("%d", &n);
    unsigned char i = 0;
    while (i<n){
        int minimumis, maximimus;
        //ide ругается но это хак
        std::scanf("%d%d", &minimumis, &maximimus);
        massiv[i].mini = std::min(minimumis, maximimus);
        massiv[i].maxi = std::max(minimumis, maximimus);

        i+=1;
    }


    unsigned char m = 0;;;
    std::sort(massiv, massiv + n);;
    otbet.push_back(massiv[m]); // m = 0

    unsigned char j = 1;
    while (j < n) {
        if (massiv[j].mini < massiv[m].maxi) {}
        else {
            m = j;
            otbet.push_back(massiv[m]);

        };
        j++;;
    };
    if (!otbet.empty()){printf("%zu\n", otbet.size());
    for (auto &otveti : otbet) {printf("%d %d\n", otveti.mini, otveti.maxi);;;}};;;
};
