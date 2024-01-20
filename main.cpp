#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask(const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
}

void viewTasks() {
    cout << "Tasks:" << endl;
    for (const auto& task : tasks) {
        cout << "- " << task.description;
        if (task.completed) {
            cout << " (Completed)" << endl;
        } else {
            cout << " (Pending)" << endl;
        }
    }
}

void markTaskAsCompleted(int index) {
    if (index>=0 && index < tasks.size()) {
        tasks[index-1].completed = true;
        cout << "The task has been marked as completed!" << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

void removeTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "The task has been removed." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    cout << "Welcome to the To-Do List manager" << endl;

    while (true) {
        cout << "Options:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice:" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter task description:" << endl;
            string description;
            cin.ignore();
            getline(cin, description);
            addTask(description);
            cout << "The task has been added!" << endl;
        } else if (choice == 2) {
            viewTasks();
        } else if (choice == 3) {
            cout << "Enter the task index:" << endl;
            int index;
            cin >> index;
            markTaskAsCompleted(index);
        } else if (choice == 4) {
            cout << "Enter the task index:" << endl;
            int index;
            cin >> index;
            removeTask(index);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
