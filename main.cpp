#include <iostream>
#include <vector>
#include "lib/main.h"
#include <conio.h>
#include <thread>
#include <chrono>

int main() {

    if (is_legacy()) {
        std::cerr << "Legacy mode affects performance. Aborting...\n";
        getch();

        return 0xbad6e3f0;
    }

    int n, m, d, delay;
    std::cin >> n >> m >> d >> delay;

    n = abs(n);
    m = abs(m);
    d = abs(d);
    delay = abs(delay);

    if (n == 0) n = 1;
    if (m == 0) m = 1;

    srand(time(0));
    std::cout << "\x1b[2J\x1b[H";

    std::vector<std::vector<int>> mat(n, std::vector<int>(m, d));
    int cnt;

    while (true) {
        cnt = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (randbool() && mat[i][j] != 0)
                    mat[i][j]++;

                mat[i][j] %= 10;
            }

        std::cout << "\x1b[H";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    cnt++;
                    std::cout << "\x1b[92m" << mat[i][j] << "\x1b[0m";
                }

                else { std::cout << mat[i][j]; }
            }
            
            std::cout << '\n';
        }

        if (cnt == n * m) break;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }

    getch();

    return 0;
}