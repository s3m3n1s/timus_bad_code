#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <vector>


class cabelscounter;
class mathem;

class cabelscounter{
public:
    static unsigned long long cabelcount(std::vector<unsigned long long>& a, double x) {
        unsigned long long otb = 0;
    
        for (unsigned long long i : a) {
            otb = otb +  (i / x);
        };

        return otb;
    };
};
class mathem{
public:
    static unsigned int find_middle(unsigned int a, unsigned int b){
        return (a+b)/2+1;
    };
    static unsigned long round_to_long_d_m_x(double num, int x){
        return long (num*x);
    };
};
int main() {
	unsigned long long n;
    unsigned long long k;
    unsigned int j = 0;
	std::cin >> n >> k;
	std::vector<unsigned long long> array_(n);
    unsigned int leftffir = 0;
    unsigned int rightlast = 10000000 + 1;
    while (j < n)
    {
        double d;
        std::cin >> d;
        array_[j] = mathem::round_to_long_d_m_x(d, 100);
        j++;
    };

    //бинпоиск
	while (rightlast > leftffir) {
        unsigned int middle = mathem::find_middle(rightlast, leftffir);
		
		if (cabelscounter::cabelcount(array_, middle) >= k) {
            leftffir = middle;
		}
		else{
            rightlast = middle - 1;
		};
	};

	std::cout << std::fixed << std::setprecision(2) << rightlast / 100.0;

	return 0;
}