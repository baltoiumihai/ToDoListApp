#include "Task.h"
#include <iostream>

Task::Task(const std::string& name, Priority priority, const std::string& dueDate)
    : name(name), priority(priority), dueDate(dueDate), completed(false) {}

void Task::display() const {
    std::cout << "Task: " << name << ", Priority: " << priority << ", Due Date: " << dueDate;
    if (completed) {
        std::cout << " [Completed]";
    }
    std::cout << std::endl;
}

const std::string& Task::getName() const {
    return name;
}

Priority Task::getPriority() const {
    return priority;
}

const std::string& Task::getDueDate() const {
    return dueDate;
}

void Task::markCompleted() {
    completed = true;
}

bool Task::isCompleted() const {
    return completed;
}
