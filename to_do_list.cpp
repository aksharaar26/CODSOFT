#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

const int maxTasks = 10;

struct Task {
    string description;
    int status; // 0 for pending, 1 for completed
    time_t completionTime;
};

void displayTasks(const Task tasks[], int taskCount, bool showCompleted) {
    cout << "Come on, Seize the Day!!\n" << endl;
    cout << "Your to-do list:" << endl;
    for (int i = 0; i < taskCount; ++i) {
        if ((showCompleted && tasks[i].status == 1) || (!showCompleted && tasks[i].status == 0)) {
            cout << setw(3) << left << i + 1 << ". ";
            if (tasks[i].status == 1) {
                cout << setw(12) << "[Completed] ";
            } else {
                cout << setw(12) << "[Pending] ";
            }
            cout << tasks[i].description;
            if (tasks[i].status == 1) {
                cout << " (Completed on " << put_time(localtime(&tasks[i].completionTime), "%F %T") << ")";
            }
            cout << endl;
        }
    }
}

void displaySummary(const Task tasks[], int taskCount) {
    int completedCount = 0;
    int pendingCount = 0;

    for (int i = 0; i < taskCount; ++i) {
        if (tasks[i].status == 1) {
            completedCount++;
        } else {
            pendingCount++;
        }
    }

    cout << "\nTask Accomplishments Summary:\n";
    cout << "Completed tasks: " << completedCount << endl;
    cout << "Pending tasks: " << pendingCount << endl;
}

int main() {
    cout << "Come on, Seize the Day!!\n" << endl;

    Task tasks[maxTasks];
    int taskCount = 0;

    while (true) {
        cout << "\nOptions:\n1. Add a task\n2. View all tasks\n3. View completed tasks\n4. View pending tasks\n";
        cout << "5. Mark task as completed\n6. Delete task\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                if (taskCount < maxTasks) {
                    cout << "Enter a task: ";
                    getline(cin, tasks[taskCount].description);
                    tasks[taskCount].status = 0; // 0 for pending
                    taskCount++;
                    cout << "Task added successfully!" << endl;
                } else {
                    cout << "Maximum tasks reached. Cannot add more." << endl;
                }
                break;

            case 2:
                displayTasks(tasks, taskCount, true);
                break;

            case 3:
                displayTasks(tasks, taskCount, true);
                break;

            case 4:
                displayTasks(tasks, taskCount, false);
                break;

            case 5:
                cout << "Enter the task number to mark as completed: ";
                int completeIndex;
                cin >> completeIndex;
                if (completeIndex > 0 && completeIndex <= taskCount) {
                    tasks[completeIndex - 1].status = 1; // 1 for completed
                    tasks[completeIndex - 1].completionTime = time(nullptr);
                    cout << "Task marked as completed!" << endl;
                } else {
                    cout << "Invalid task number." << endl;
                }
                break;

            case 6:
                cout << "Enter the task number to delete: ";
                int deleteIndex;
                cin >> deleteIndex;
                if (deleteIndex > 0 && deleteIndex <= taskCount) {
                    for (int i = deleteIndex - 1; i < taskCount - 1; ++i) {
                        tasks[i] = tasks[i + 1];
                    }
                    taskCount--;
                    cout << "Task deleted successfully!" << endl;
                } else {
                    cout << "Invalid task number." << endl;
                }
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
        displaySummary(tasks, taskCount);
    }
}