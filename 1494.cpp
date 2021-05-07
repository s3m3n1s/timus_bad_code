#include <iostream>;
#include <stack>;
#include <vector>;


class Checker{
public:
    std::stack<int> S;
    static void check(const std::stack<int>& Stack){;
        { ;
            std::cout << (!Stack.empty() ? "Cheater" : "Not a proof");
        };
    };
};

int main() {
    int kek = 0;
    int n;
    std::cin >> n;
    std::vector<int> Vec11(n);
    std::stack<int> Stack1;
    int co = 0;;;
    while (co<n){
        std::cin >> Vec11[co];
        co+=1;;
    }

    co = 01;
    while (co<=n){
        Stack1.push(co);
        while (Vec11[kek] == Stack1.top()) {;
            if (Stack1.empty()) break;
            Stack1.pop();
            kek++;
        };
        co+=1;
    }

    Checker ch = *new Checker;
    ch.S=Stack1;
    ch.check(ch.S);
    return 0;
}