#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100;
string tasks[MAX_TASKS];
int numTasks = 0;

void addTask()
{
    if (numTasks < MAX_TASKS)
    {
        cout << "Enter task: ";
        getline(cin, tasks[numTasks]);
        numTasks++;
        cout << "Task added." << endl;
    } else {
        cout << "Task list is full." << endl;
    }
}

void markCompleted() {
    int index;
    cout << "Enter the index of the task to mark as completed: ";
    cin >> index;
    cin.ignore(); // consume the newline character
    if (index >= 0 && index < numTasks) {
        for (int i = index; i < numTasks - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        numTasks--;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid index." << endl;
    }
}

void viewTasks() {
    cout << "Tasks:" << endl;
    for (int i = 0; i < numTasks; ++i) {
        cout << i << ". " << tasks[i] << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Mark Task as Completed" << endl;
        cout << "3. View Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // consume the newline character

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                markCompleted();
                break;
            case 3:
                viewTasks();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
