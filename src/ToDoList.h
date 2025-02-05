#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include <string>
#include "Task.h"

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const Task& task);
    void displayTasks() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    void sortTasksByPriority();
    void markTaskCompleted(const std::string& taskName);
};

#endif // TODOLIST_H
