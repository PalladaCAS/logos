#define LOGS_ENABLE
#define LOGS_FILENAME "4.log"
#include "../logos.h"

int main(void) {
    logos_init();
    
    logos_enter();
    logos_note("Test note");
    logos_warning("Test warning");
    logos_error("Test error");
    logos_leave();
    
    logos_deinit();
    
    return 0;
}
