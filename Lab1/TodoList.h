#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include "TodoListInterface.h"
#include <fstream>
#include <vector>
//#include <ofstream>

using namespace std;

class TodoList : public TodoListInterface {
public:
		vector <string> daysList;
		vector <string> taskList;
		//constructor
    TodoList() {
			cout << "This is constructor" << endl;
			ifstream infile ("TODOList.txt");
			string line;
			if (infile.is_open()) {
				while (getline (infile, line)) {
					cout << line << endl;
					daysList.push_back(line);
					taskList.push_back(line);
				}
			}
			infile.close();		
		} 
		//destructor
    virtual ~TodoList() {
			cout << "This is destructor" << endl;
			ofstream outfile;
			outfile.open("TODOList.txt", ofstream::out | ofstream::trunc);
			for (int i = 0; i < daysList.size(); ++i) {
				outfile << daysList[i] << endl;
				outfile << taskList[i] << endl;
			}
			outfile.close();
		}

    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
    virtual void add(string _duedate, string _task) {
			cout << "This is add" << endl;
			daysList.push_back(_duedate);
			taskList.push_back(_task);
		}

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task) {
			cout << "This is remove" << endl;
			unsigned int i = 0;
			bool found = false;
			while(!found && (i < taskList.size())) {
				if(taskList.at(i) == _task) {
					daysList.erase(daysList.begin() + i);
					taskList.erase(taskList.begin() + i);
					found = true;
				}
				++i;
			}
		}
		//substr -> start after the space

    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList() {
			cout << "This is print" << endl;
			for(int i = 0; i < daysList.size(); ++i) {
				cout << daysList[i] << endl;
				//cout << taskList[i] << endl;
			}
		}
    
    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    virtual void printDaysTasks(string _date) {
			cout << "This is print by day" << endl;
		}
};

#endif