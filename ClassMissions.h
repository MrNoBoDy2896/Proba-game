#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <clocale>
#include <stdlib.h>
#include "Values.h"

using namespace std;

class QuestTask {
private:
    string description;
    bool completed;

public:
    QuestTask(string desc) : description(desc), completed(false) {}

    void completeTask() {
        completed = true;
        cout << "Task completed: " << description << endl;
    }

    bool isCompleted() const {
        return completed;
    }

    const string& getDescription() const {
        return description;
    }
};

class Quest {
private:
    string name;
    vector<QuestTask> tasks;
    bool completed;

public:
    Quest(const string questName) : name(questName), completed(false) {}

    void addTask(const string& taskDesc) {
        tasks.push_back(QuestTask(taskDesc));
    }

    void completeTask(const string& taskDesc) {
        for (auto& task : tasks) {
            if (task.getDescription() == taskDesc) {
                task.completeTask();
                break;
            }
        }
    }

    bool isCompleted() const {
        for (const auto& task : tasks) {
            if (!task.isCompleted()) {
                return false;
            }
        }
        return true;
    }

    void completeQuest() {
        if (isCompleted()) {
            completed = true;
            cout << "Quest completed: " << name << endl;
        }
        else {
            cout << "Cannot complete quest. Some tasks are not completed yet." << endl;
        }
    }
};
