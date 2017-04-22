#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

unsigned long long hex2dec(const string &input);

unsigned long long hex2dec_c(const char *s, int length);

int main(int argc, char *argv[]) {
    string i1 = "d0";
    int var = hex2dec(i1) % 9 + 1;
    cout << var << endl;
    return 0;
}

unsigned long long hex2dec(const string &input) {
    unsigned long long n;
    stringstream ss;
    ss << hex << uppercase << input;
    //ss << hex << lowercase << input;
    ss >> n;
    return n;
}

unsigned long long hex2dec_c(const char *s, int length) {
    unsigned long long n = 0;
    for (int i = 0, v = 0; i < length && s[i] != '\0'; i++) {
        if ('a' <= s[i] && s[i] <= 'f') { v = s[i] - 97 + 10; }
        else if ('A' <= s[i] && s[i] <= 'F') { v = s[i] - 65 + 10; }
        else if ('0' <= s[i] && s[i] <= '9') { v = s[i] - 48; }
        else break;
        n *= 16;
        n += v;
    }
    return n;
}