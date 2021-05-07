#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#include <cstdio>


std::vector<std::pair<signed   int, signed   int>> f1();
class comparator;
class comparator{
class check;
public:
    static bool cmpr(std::pair<int, int> n1, std::pair<int, int> n2) {
        if (n1.first != n2.first) {
            return n1.first < n2.first;
        } else {
            return n1.second > n2.second;
        };
    };
};
class check{
public:
    static int checker_fu(int n1, int n2, int m){
        if (n1 != 0 || n2 != 0) {

            if (n1 <= m && n2 >= 0) {
                return 1;
                };
            return 2;
            };
        return 3;
}};




 int main() {
	 signed   int M;
	std::cin >> M;
	std::vector<std::pair<signed   int, signed   int>> yav, otvet, yaw2;

	while (1==1) {
         signed int beggining;
         signed int end;

		std::cin >> beggining >> end;
        int kek = check::checker_fu(beggining, end, M);
        if (kek==1) yav.emplace_back(beggining, end);
        if (kek==2) continue;
        if (kek==3) break;

    };


	sort(yav.begin(),
      yav.end(),
      comparator::cmpr);

     signed   int R = 0;
     signed   int j = 0;

	while (M > R) {
          int rightatlocal = -1;
         signed   int i = j;
        while (i < yav.size()){
            if (rightatlocal >= yav[i].second) {
            } else {
                if (R >= yav[i].first) {
                    rightatlocal = yav[i].second;
                    j = i;
                };
            };
            i+=1;
        };


        if (R < rightatlocal) { ;

            R = rightatlocal;
            otvet.push_back(yav[j]);
        } else {
            break;
        }
    };
;;


    if (R >= M) { ;;

        std::cout << otvet.size() << "\r\n";

        for (auto &iter : otvet) {
            std::cout << iter.first << " " << iter.second << "\r\n";
        };;

        return 0;;
    } else {
        std::cout << "No solution\n";

        return 0;
    }
};;