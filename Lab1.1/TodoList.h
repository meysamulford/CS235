#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "TodoListInterface.h"

using namespace std;

class TodoList : public TodoListInterface {
public:
		vector <string> tasks;
    TodoList() {
			cout << "In constructor" << endl;
			ifstream inFile ("TODOList.txt");
			string line;
			if(inFile.is_open()) {
				while(getline (inFile, line)) {
					cout << line << '\n';
				}
				inFile.close();
			}

		}
    virtual ~TodoList() {
			cout << "In destructor" << endl;
			ofstream outFile;
			outFile.open("TODOList.txt", ofstream::out | ofstream::trunc);
			for(int i = 0; i < tasks.size(); ++i) {
				outFile << tasks[i] << endl;
			}
			outFile.close();
		}

    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
    virtual void add(string _duedate, string _task) {
			cout << "In add" << endl;
			tasks.push_back(_duedate + " " + _task);
		}

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task) {
			cout << "In remove" << endl;
			auto match = find(tasks.begin(), tasks.end(), _task);
		}

    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList() {
			cout << "In print" << endl;
			for(int i = 0; i < tasks.size(); ++i) {
				cout << tasks.at(i) << endl;
			}
		}
    
    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    virtual void printDaysTasks(string _date) {
			cout << "In print days" << endl;
		}
};

#endif