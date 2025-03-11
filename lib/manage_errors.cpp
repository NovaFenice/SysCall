#include "manage_errors.h"

string string_to_error(const string &testo) {
    return setColor(255, 0, 0) + testo + resetColor();
}