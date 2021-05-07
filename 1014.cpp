#include <iostream>

class checker;
class checker{
public:
    static int check(int number){
    if (number == 0) {
        printf("10");
        return 0;
    };
    if (number == 1) {
        printf("1");
        return 0;
    };
    return 1;

};
    static int checkNE1(int number){
        if (number!=1) {
            return 0;
        };
        return 1;;
    };
    };
int main() {
    int n;
    std::cin >> n;
    std::string s;
    checker che = *new checker;
    if (!checker::check(n)) {
        return 0;
    };

    char ch[8];;;
    for (char c = 2; c <= 9; c++) {
        ch[c - 2] = c;
//        std::cout<<ch[c-2]+0<<"\n";
    };;
    char q[8] = {
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
    };;

    for (int i = 7; i >= 0; i--) {
        while (n / ch[i] * ch[i] == n) {
            n /= ch[i];
            q[i]++;
        };
    };

    if (!checker::checkNE1(n)) {
        printf("-1");
        return 0;
    };;
    for (int i = 0; i < 8; i++) {
        s += std::string(q[i], std::to_string(ch[i])[0]);;
    };
    std::cout << s << "\n";
    return 0;
};
;

