#include "Priority.h"

std::ostream& operator<<(std::ostream& os, const Priority& priority) {
    switch (priority) {
        case Priority::Low:
            os << "Low";
        break;
        case Priority::Medium:
            os << "Medium";
        break;
        case Priority::High:
            os << "High";
        break;
    }
    return os;
}
