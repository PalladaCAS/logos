#include <stdio.h>

#define LOGS_ENABLE
#define LOGS_FILENAME "1.log"
#include "../logos.h"

int main() {
    logos_general_log("General logging test\n");

    return 0;
}
