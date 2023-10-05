#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

int ID = 0;

struct Task {
    int id;
    string description;
    bool completed;

    Task(int _id, string _description) : id(_id), description(_description), completed(false) {}
};

vector<Task> taskList;

void addTask() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    string description;
    cout << "\n\tEnter a new task: ";
    cin.ignore();
    getline(cin, description);

    ID++;
    Task newTask(ID, description);

    taskList.push_back(newTask);

    cout << "\n\tTask has been added successfully." << endl;
}

void viewTasks() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    cout << "\n\t------------------Your current Tasks in the list--------------------" << endl;
    
    for (int i = 0; i < taskList.size(); i++) {
        cout << "\n\tID: " << taskList[i].id;
        cout << "\n\tTask: " << taskList[i].description;
        cout << "\n\tStatus: " << (taskList[i].completed ? "Completed" : "Pending") << endl;
    }
}

void markAsCompleted() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    int taskId;
    cout << "\n\tEnter the ID of the task you want to mark as completed: ";
    cin >> taskId;

    for (int i = 0; i < taskList.size(); i++) {
        if (taskList[i].id == taskId) {
            taskList[i].completed = true;
            cout << "\n\tTask marked as completed." << endl;
            return;
        }
    }

    cout << "\n\tTask not found." << endl;
}

void removeTask() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    int taskId;
    cout << "\n\tEnter the ID of the task you want to remove: ";
    cin >> taskId;

    for (int i = 0; i < taskList.size(); i++) {
        if (taskList[i].id == taskId) {
            taskList.erase(taskList.begin() + i);
            cout << "\n\tTask removed successfully." << endl;
            return;
        }
    }

    cout << "\n\tTask not found." << endl;
}

int main() {
    system("cls");
    // system("Color E0"); // Remove this line to use default console colors
    system("title todoapp @copyassignment");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t*                                                                     *" << endl;
    cout << "\t\t\t*                      WELCOME TO Your ToDo List                      *" << endl;
    cout << "\t\t\t*                                                                     *" << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl << endl;

    while (true) {
        cout << endl << endl;
        cout << "\n\t1. Add Task";
        cout << "\n\t2. View Tasks";
        cout << "\n\t3. Mark Task as Completed";
        cout << "\n\t4. Remove Task";
        cout << "\n\t5. Exit";

        int choice;
        cout << "\n\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addTask();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            markAsCompleted();
            break;
        case 4:
            removeTask();
            break;
        case 5:
            return 0;
        default:
            cout << "\n\tInvalid choice. Please try again." << endl;
        }
    }
}
