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
			//cout << "In constructor" << endl;
			ifstream inFile ("TODOList.txt");
			string line;
			if(inFile.is_open()) {
				while(getline (inFile, line)) {
					cout << line << '\n';
					tasks.push_back(line);
				}
				inFile.close();
			}

		}
    virtual ~TodoList() {
			//cout << "In destructor" << endl;
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
			//cout << "In add" << endl;
			tasks.push_back(_duedate);
			tasks.push_back(_task);
		}

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task) {
			//cout << "In remove" << endl;
			for(int i = 0; i < tasks.size(); ++i) {
				if(tasks[i] == _task) {
					tasks.erase(tasks.begin() + i);
					tasks.erase(tasks.begin() + (i-1));
				}
			}
		}

    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList() {
			//cout << "In print" << endl;
			cout << "---- TODO LIST ----" << endl;
			for(int i = 0; i < tasks.size(); ++i) {
				cout << tasks[i] << endl;
			}
		}
    
    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    virtual void printDaysTasks(string _date) {
			//cout << "In print days" << endl;
			cout << "---- " << _date << "'s tasks ----" << endl; 
			for(int i = 0; i < tasks.size(); ++i) {
				if(tasks[i] == _date) {
					cout << tasks[i] << " " << tasks[i+1] << endl;
				}
			}
		}
};

#endif