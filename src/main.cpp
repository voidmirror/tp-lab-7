#include "../include/Ocean.h"
#include "../include/params.h"


using namespace std;
int main() {
    auto * o = new Ocean(N, M);
    o->startGame();
    return 0;
}
