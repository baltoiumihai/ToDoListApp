#ifndef TASK_H
#define TASK_H

#include <string>
#include "Priority.h"

class Task {
private:
    std::string name;
    Priority priority;
    std::string dueDate;
    bool completed;

public:
    Task(const std::string& name, Priority priority, const std::string& dueDate);

    void display() const;

    const std::string& getName() const;
    Priority getPriority() const;
    const std::string& getDueDate() const;

    void markCompleted();

    bool isCompleted() const;
};

#endif // TASK_H
