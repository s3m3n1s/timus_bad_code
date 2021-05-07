#include <cstdio>
#include <algorithm>
#include <iostream>


class Town;

class Town {
public:
    int people, count;
    friend bool operator > (Town first, Town second);
    friend bool operator < (Town first, Town second);
    explicit Town(int count = 0, int people = 0 ) { this -> count = count; this -> people = people;
    };};

bool operator>(const Town first, const Town second) {
    {
        if (first.people == second.people) {
            return first.count < second.count;
        };
        return first.people < second.people;
    };
}

bool operator<(const Town first, const Town second)
    {

        if(first.people == second.people) return first.count < second.count;

        return first.people < second.people;


    };


int main() {
    int n;
    std::cin >> n;
    Town a[70000];
    int i = 0;
    while(i < n)
    {
        std::cin >> a[i].people;
        a[i].count = i + 1;
        i++;
    };

    std::sort(a, a + n);
    int q;
    int l, r, x;
    std::cin >> q;
    while (q>0) {
        std::scanf("%d %d %d", &l, &r, &x);
        int Left;
        int Right;
        Left = std::lower_bound(a, a + n, Town(l, x)) - a;
        Right = std::upper_bound(a, a + n, Town(r, x)) - a;
        std::cout << (Left < Right);

        q-=1;
    };
    printf("\n");

};