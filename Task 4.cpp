#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask() {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available!\n";
        return;
    }
    cout << "\nYour To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "Done" : "Not") << "] " << tasks[i].description << "\n";
    }
}

void markTaskCompleted() {
    int taskNum;
    viewTasks();
    cout << "Enter task number to mark as completed: ";
    cin >> taskNum;
    if (taskNum > 0 && taskNum <= tasks.size()) {
        tasks[taskNum - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

void removeTask() {
    int taskNum;
    viewTasks();
    cout << "Enter task number to remove: ";
    cin >> taskNum;
    if (taskNum > 0 && taskNum <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNum - 1);
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Have a productive day!\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);
    return 0;
}
