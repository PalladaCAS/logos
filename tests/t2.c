#define LOGS_ENABLE
#define LOGS_FILENAME "2.log"
#include "../logos.h"

int main() {
    logos_section("INIT");
    logos_entry("TEST", "test entry");
    logos_section("DEINIT");

    return 0;
}
