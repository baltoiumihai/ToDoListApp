#include "ToDoList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

void ToDoList::addTask(const Task& task) {
    tasks.push_back(task);
}

void ToDoList::displayTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
    } else {
        for (const auto& task : tasks) {
            task.display();
        }
    }
}

void ToDoList::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& task : tasks) {
            outFile << task.getName() << "\n"
                    << static_cast<int>(task.getPriority()) << "\n"
                    << task.getDueDate() << "\n"
                    << (task.isCompleted() ? "1" : "0") << "\n";
        }
        outFile.close();
        std::cout << "Tasks saved to " << filename << "\n";
    } else {
        std::cout << "Unable to open file for saving.\n";
    }
}

void ToDoList::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        tasks.clear();
        std::string name;
        int priorityChoice;
        std::string dueDate;
        bool completed;

        while (getline(inFile, name) && getline(inFile, dueDate)) {
            inFile >> priorityChoice >> completed;
            inFile.ignore();  // ignore newline after the priority choice

            Priority priority = static_cast<Priority>(priorityChoice);
            Task task(name, priority, dueDate);
            if (completed) {
                task.markCompleted();
            }
            tasks.push_back(task);
        }
        inFile.close();
        std::cout << "Tasks loaded from " << filename << "\n";
    } else {
        std::cout << "Unable to open file for loading.\n";
    }
}

void ToDoList::sortTasksByPriority() {
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return static_cast<int>(a.getPriority()) < static_cast<int>(b.getPriority());
    });
}

void ToDoList::markTaskCompleted(const std::string& taskName) {
    for (auto& task : tasks) {
        if (task.getName() == taskName) {
            task.markCompleted();
            std::cout << "Task '" << taskName << "' marked as completed.\n";
            return;
        }
    }
    std::cout << "Task not found!\n";
}
