#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define maxp1 100+1
using namespace std;

int N;
int Q;
int Tree[maxp1][maxp1];
int DP[maxp1][maxp1];
int solve (int current, int parent, int q)
{
 if (q <= 0) return 0;
 int lindex = -1, rindex = -1;
 int & result = DP[current][q];
 if (result != -1) return result;
 for (int i = 0; i < maxp1; i++)
  if (Tree[current][i] != -1 && i != parent) {lindex = i; break;}
 for (int i = (lindex == -1?0:lindex+1); i < maxp1; i++)
  if (Tree[current][i] != -1 && i != parent) {rindex = i; break;}
 if (lindex == -1 || rindex == -1) return 0;
 for (int i = 0; i <= q; i++)
  result = max (result, (i == q?0:Tree[current][lindex] + solve(lindex, current, q - i - 1))
   + (i == 0?0:Tree[current][rindex] + solve(rindex, current, i - 1)));
 return result;
}
int main()
{
 cin >> N >> Q;
 memset (Tree, -1, sizeof Tree);
 memset (DP, -1, sizeof DP);
 for (int i = 0; i < N; i++)
  for (int j = 0, x, y, z; j < N; j++)
  {
   cin >> x >> y >> z;
   Tree [x][y] = z;
   Tree [y][x] = z;
  }
 cout << solve (1, 0, Q)<<"\n";
 return 0;
}
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ /*⣀⣀⣀⣀⣀⣠⣠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⢐⣤⣴⣾⣿⣿⣿⣶⣿⣻⣛⣿⣷⢴⣄⠀⠀⠀⠀⠀⠀⠀⠀⠈⠩⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣷⣵⣿⢿⣿⣴⡴⢤⡀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣻⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⢹⡏⣿⣿⣿⣿⣿⣿⣿⣿
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣿⣿⣿⣿⣿⣿⠿⠟⠋⠙⠛⠛⠋⠛⠛⠋⠉⠉⠉⠻⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠘⠃⣿⣿⣿⣿⣿⣿⣿⣿
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⡾⠋⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⣉⣿⣿⣿⣿⣿⣿⣿
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠙⢩⣿⣿⣿⣿⣿⣿
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⡇⣿⣿⣿⣿
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣢⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠞⠋⠀⠀⠀⠀⠀⠉⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⣿⣿⣿⣿
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣾⠀⠀⠀⠀⠀⠉⣉⠀⠀⠀⠀⠀⠀⣰⠻⠿⠲⠧⠄⠀⠀⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠸⣶⡇⣿⣿⣿⣿
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠐⠴⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠄⣿⡧⣿⣿⣿⣿
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠅⠀⠀⠀⠀⠀⠀⠀⠀⠀⣛⠀⣿⣿⣿⣿
// ⠀⠀⠀⠀⣼⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⡤⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢛⠀⣿⣿⣿⣿
// ⠀⠀⠀⣼⡟⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠉⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣧⣿⣿⣿⣿
// ⠀⠀⢰⣿⡇⠀⠀⠀⡀⠀⢰⣿⣀⠀⠀⠀⠀⠀⠀⠀⡀⠠⠤⠤⠀⠒⠒⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣿⣿⣿⣿⣿⣿
// ⢠⣤⣿⣿⡇⠀⡄⠀⣿⣖⣿⣿⣿⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠤⠖⠒⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿
// ⣼⣿⣿⣇⣦⣼⠃⢠⣿⣿⣿⣿⣿⣿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣾⣿⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⢀⡾⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⢠⣴⡎⠈⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠻⠻⣿⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿⣿⣿⣿⣿⠿⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠻⠿⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⡿⠠⣿⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙
// ⢋⣼⣿⣿⣿⡟⠘⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⣾⢿⠟⠋*/⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀