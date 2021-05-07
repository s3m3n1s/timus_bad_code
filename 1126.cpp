#include <algorithm>;
#include <vector>;;
#include <iostream>;;


class Finder{
    public:
    static int FindMax(std::vector<int>& vec, int direct) {
        int _l_maximum = vec[direct];;
        int co = direct + 1;
        while (co<vec.size()){
            if (vec[co] > _l_maximum) {
                _l_maximum = vec[co];
            };
            co+=1;
        };
        return _l_maximum;
    };
};


int main() {;
    int M, a, i = 0;
    std::cin >> M;
    std::vector<int> n(M);
    for(;;) {;
        std::cin >> a;
        if (a != -1) { ;
            if (i < M) {;
                n[i] = a;
                i++;
                if (i != M) continue;
                std::cout << Finder::FindMax(n, i - M) << "\n";;;
                continue;
            };
            n.push_back(a);
            std::cout << Finder::FindMax(n, i + 1 - M) << "\n";
            i++;;
        } else {
            break;
        };
    };
    return 0;
}