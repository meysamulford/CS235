#include <iostream>
#include <string>
#include "TodoList.h"
using namespace std;

int main(int argc, char *argv[]) {
	TodoList myList;
  for(int i = 0; i < argc; i++) {
    cout << "argv[" << i << "]=" << argv[i] << endl;
  }
	string firstarg = argv[1];
	if(firstarg.compare("add")==0) {
		cout << "Doing an add" << endl;
		string date = argv[2];
		string task = argv[3];
		cout << "date: " << date << " task: " << task << endl;
		myList.add(date, task);
	}
	if(firstarg.compare("remove")==0) {
		cout << "Doing a remove" << endl;
		string task = argv[2];
		myList.remove(task);
	}
	if(firstarg.compare("print")==0) {
		cout << "Doing a print" << endl;
		myList.printTodoList();
	}
	if(firstarg.compare("printDaysTasks")==0) {
		cout << "Doing a print for single day" << endl;
		//not sure how this one is going to work
	}
}