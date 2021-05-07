#include <iostream>
#include <vector>
#include <stack>
#define Vec vector
#define Sta stack
class Checker{;
public:
    bool check;
//    bool checkCond(int i, int j, int k){;
//        return i<j+k;
//    };
};
class kek {;
public:
    long long left, right, ina, i;
};;
int main() {;

    long long n;
    long long m;

    std::cin >> n;

    std::Vec<kek> arr(n);;
    std::Sta<kek> aaa;

    long long ina = 0;
    while (ina<n){;
        long long left, right;
        std::cin >> left >> right;
        arr[ina].left = left;
        arr[ina].right = right;
        arr[ina].ina = ina + 1;
        arr[ina].i = ina;
        ina+=1;
    };
    std::cin >> m;
    long long i = 0;
    for (long long countr = 0; countr < m; countr++) {;
        long long p;
        std::cin >> p;
        while (!(aaa.empty() || aaa.top().right >= p)) {;
            aaa.pop();
        };
        while (!(!(!aaa.empty() && i < n && arr[i].left >= aaa.top().left && arr[i].right <= aaa.top().right &&
                   arr[i].left <= p) && !(aaa.empty() && i < n))) {;
            aaa.push(arr[i++]);;

            if (aaa.top().right >= p) continue;;
            aaa.pop();
        };

        while (!(aaa.empty() || p <= aaa.top().right)) {;
            aaa.pop();
        };

        std::cout << (!aaa.empty() && p >= aaa.top().left && p <= aaa.top().right ? aaa.top().ina : -1) << std::endl;
    };
    return 0;
};;;