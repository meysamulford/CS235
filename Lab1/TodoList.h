#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include "TodoListInterface.h"

using namespace std;

class TodoList : public TodoListInterface {
public:
    TodoList() {
			cout << "This is constructor" << endl;
		} //constructor
    virtual ~TodoList() {
			cout << "This is destructor" << endl;
		} //destructor

    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
    virtual void add(string _duedate, string _task) {
			cout << "This is add" << endl;
		}

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task) {
			cout << "This is remove" << endl;
		}

    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList() {
			cout << "This is print" << endl;
		}
    
    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    virtual void printDaysTasks(string _date) {
			cout << "This is print by day" << endl;
		}
};

#endif
