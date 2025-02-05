#ifndef PRIORITY_H
#define PRIORITY_H

#include <iostream>

enum class Priority {
    Low = 0,
    Medium = 1,
    High = 2
};

std::ostream& operator<<(std::ostream& os, const Priority& priority);

#endif // PRIORITY_H
