#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  for(int i; i < argc; i++) {
    cout << "argv[" << i << "]=" << argv[i] << endl;
  }
	string firstarg = argv[1];
	if(firstarg.compare("add")==0) {
		cout << "Doing an add" << endl;
	}
}