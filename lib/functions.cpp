#include "funcionts.h"

string setColor(int r, int g, int b) {
    return "\033[38;2;" + to_string(r) + ";" + to_string(g) + ";" + to_string(b) + "m";
}

string resetColor() {
    return "\033[0m";
}