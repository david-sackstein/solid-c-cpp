#pragma once

#include "ILogger.h"

#include <stdio.h>
#include <stdlib.h>

// Concrete implementation struct
typedef struct {
    ILogger base; // Interface
    FILE *file;   // Implementation-specific data
} FileLogger;

FileLogger *create_file_logger();