#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Task
{
    int id;
    string title;
    string priority;
    bool completed;
};

class TodoList
{
private:
    vector<Task> tasks;
    const string filename = "tasks.txt";

public:
    TodoList()
    {
        loadTasks();
    }

    ~TodoList()
    {
        saveTasks();
    }

    void loadTasks()
    {
        tasks.clear();

        ifstream fin(filename);

        if (!fin)
            return;

        Task t;

        while (fin >> t.id)
        {
            fin.ignore();

            getline(fin, t.title);
            getline(fin, t.priority);

            fin >> t.completed;
            fin.ignore();

            tasks.push_back(t);
        }

        fin.close();
    }

    void saveTasks()
    {
        ofstream fout(filename);

        for (Task t : tasks)
        {
            fout << t.id << endl;
            fout << t.title << endl;
            fout << t.priority << endl;
            fout << t.completed << endl;
        }

        fout.close();
    }

    int generateID()
    {
        if (tasks.empty())
            return 1;

        return tasks.back().id + 1;
    }

    void addTask()
    {
        Task t;

        t.id = generateID();

        cin.ignore();

        cout << "\nEnter Task Name : ";
        getline(cin, t.title);

        cout << "Priority (High/Medium/Low): ";
        getline(cin, t.priority);

        t.completed = false;

        tasks.push_back(t);

        cout << "\nTask Added Successfully.\n";
    }

    void viewTasks()
    {
        if (tasks.empty())
        {
            cout << "\nNo Tasks Available.\n";
            return;
        }

        cout << "\n===============================================================\n";

        cout << left
             << setw(6) << "ID"
             << setw(30) << "Task"
             << setw(12) << "Priority"
             << setw(12) << "Status" << endl;

        cout << "===============================================================\n";

        for (Task t : tasks)
        {
            cout << left
                 << setw(6) << t.id
                 << setw(30) << t.title
                 << setw(12) << t.priority
                 << setw(12) << (t.completed ? "Done" : "Pending")
                 << endl;
        }
    }

    void searchTask()
    {
        cin.ignore();

        string key;

        cout << "\nEnter Task Name : ";
        getline(cin, key);

        bool found = false;

        for (Task t : tasks)
        {
            if (t.title.find(key) != string::npos)
            {
                cout << "\nID : " << t.id << endl;
                cout << "Task : " << t.title << endl;
                cout << "Priority : " << t.priority << endl;
                cout << "Status : "
                     << (t.completed ? "Completed" : "Pending")
                     << endl;

                found = true;
            }
        }

        if (!found)
            cout << "\nTask Not Found.\n";
    }

    void editTask()
    {
        int id;

        cout << "\nEnter Task ID : ";
        cin >> id;

        for (Task &t : tasks)
        {
            if (t.id == id)
            {
                cin.ignore();

                cout << "New Task Name : ";
                getline(cin, t.title);

                cout << "New Priority : ";
                getline(cin, t.priority);

                cout << "\nTask Updated Successfully.\n";

                return;
            }
        }

        cout << "\nTask Not Found.\n";
    }