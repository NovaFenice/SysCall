#include "init.h"

string setColor(int r, int g, int b) {
    return "\033[38;2;" + to_string(r) + ";" + to_string(g) + ";" + to_string(b) + "m";
}

string resetColor() {
    return "\033[0m";
}

void init_ascii() {
    cout << setColor(0, 75, 143) <<"███████╗██╗   ██╗███████╗ ██████╗ █████╗ ██╗     ██╗     "<< resetColor() <<endl;
    cout << setColor(0, 86, 163) <<"██╔════╝╚██╗ ██╔╝██╔════╝██╔════╝██╔══██╗██║     ██║     "<< resetColor() <<endl;
    cout << setColor(0, 97, 184) <<"███████╗ ╚████╔╝ ███████╗██║     ███████║██║     ██║     "<< resetColor() <<endl;
    cout << setColor(0, 110, 207)<<"╚════██║  ╚██╔╝  ╚════██║██║     ██╔══██║██║     ██║     "<< resetColor() <<endl;
    cout << setColor(0, 121, 227)<<"███████║   ██║   ███████║╚██████╗██║  ██║███████╗███████╗"<< resetColor() <<endl;
    cout << setColor(0, 134, 252)<<"╚══════╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝"<< resetColor() <<endl;
}