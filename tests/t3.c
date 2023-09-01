#define LOGS_ENABLE
#define LOGS_FILENAME "3.log"
#include "../logos.h"

int main(void) {
    logos_init();
    logos_note("Test note");
    logos_warning("Test warning");
    logos_error("Test error");
    logos_deinit();
    
    return 0;
}
