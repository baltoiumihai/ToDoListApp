#include <iostream>
#include <string>
#include "ToDoList.h"

using namespace std;

int main() {
    ToDoList todoList;
    int choice;

    while (true) {
        cout << "\nTo-Do List Application\n";
        cout << "1. Add Task\n";
        cout << "2. Display Tasks\n";
        cout << "3. Save to File\n";
        cout << "4. Load from File\n";
        cout << "5. Sort Tasks by Priority\n";
        cout << "6. Mark Task as Completed\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 7) {
            break;
        }

        switch (choice) {
            case 1: {
                string name;
                int priorityChoice;
                string dueDate;

                cout << "Enter task name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter priority (0 = Low, 1 = Medium, 2 = High): ";
                cin >> priorityChoice;

                Priority priority = static_cast<Priority>(priorityChoice);

                cout << "Enter due date (YYYY-MM-DD): ";
                cin >> dueDate;

                Task task(name, priority, dueDate);
                todoList.addTask(task);
                cout << "Task added!" << endl;
                break;
            }
            case 2:
                todoList.displayTasks();
                break;
            case 3: {
                string filename;
                cout << "Enter filename to save tasks: ";
                cin >> filename;
                todoList.saveToFile(filename);
                break;
            }
            case 4: {
                string filename;
                cout << "Enter filename to load tasks: ";
                cin >> filename;
                todoList.loadFromFile(filename);
                break;
            }
            case 5:
                todoList.sortTasksByPriority();
                cout << "Tasks sorted by priority.\n";
                break;
            case 6: {
                string taskName;
                cout << "Enter task name to mark as completed: ";
                cin.ignore();
                getline(cin, taskName);
                todoList.markTaskCompleted(taskName);
                break;
            }
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
