#include <iostream>

using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time() : hour(0), minute(0), second(0) {}

    int hours() {
        return hour;
    }

    int minutes() {
        return minute;
    }

    int seconds() {
        return second;
    }

    void reset(int h, int m, int s) {
        hour = h % 24;
        minute = m % 60;
        second = s % 60;
    }

    void advance(int h, int m, int s) {
        second += s;
        minute += m + second / 60;
        hour += h + minute / 60;
        second %= 60;
        minute %= 60;
        hour %= 24;
    }

    void print() {
        cout << hour << ":" << minute << ":" << second << endl;
    }
};

int main() {
    Time t;
    t.reset(23,50,40);
    t.advance(6,55,28);
    cout<<t.hours()<<endl;
    t.print();
    return 0;
}
