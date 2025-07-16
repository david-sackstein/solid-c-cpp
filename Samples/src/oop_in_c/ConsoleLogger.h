#pragma once

#include "ILogger.h"

#include <stdio.h>
#include <stdlib.h>

// Concrete implementation struct
typedef struct {
    ILogger base; // Interface
    // No additional data needed for console
} ConsoleLogger;

// Always succeeds, no open needed
ConsoleLogger *create_console_logger(); 