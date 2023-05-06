#include <iostream>

using namespace std;

class test
{
    public:
        int x = 10, y = 20;
        void display() {
            cout << "X: " << x << " Y: " << y << endl;
        }
        void setx(int x) {
            this->x = x;
        }
        void sety(int y) {
            this->y = y;
        }
};

int main() {
    int* x;
    // *x = 6;
    cout << x << endl;
}
