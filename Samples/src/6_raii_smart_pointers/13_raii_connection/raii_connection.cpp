#include "Connection.h"
#include "demos.h"

#include <cstdlib>

namespace {

bool run_query() {
    // RAII ensures the connection is disconnected when this function returns.
    Connection conn;
    conn.query();
    return true;
}

}

void demo_raii_connection() {
    // Even if this function returned early, the connection would still disconnect.
    if (!run_query()) {
        std::exit(1);
    }
}
