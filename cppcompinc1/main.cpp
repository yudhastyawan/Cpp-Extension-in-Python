#include <stdio.h>

class Mynum {
    private:
        int num;

    public:
        Mynum(int i) {
            num = i;
        }

        int getter() {
            return num;
        }
};

int main() {
    // Mynum c(10);
    // printf("%d\n", c.getter());
    Mynum* c = new Mynum(10);
    printf("%d\n", c->getter());
    delete(c);
    return 0;
}