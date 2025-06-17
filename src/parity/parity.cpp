#include <iostream>
#include <string>
using namespace std;

int main() {

	int num;
    while (cin >> num) {
        if (num == 0) break;

        int count = 1;
        string s_num = "";
        int c_num = num;

        while (c_num >= 2) {
            if (c_num % 2 == 1) {
                count++;
                s_num = "1" + s_num;
            } else {
                s_num = "0" + s_num;
            }
            c_num /= 2;
        }
        s_num = "1" + s_num;

        cout << "The parity of " << s_num << " is " << count << " (mod 2)." << endl;
    }

    return 0;
}