#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

//Part 1: into a set
int main(int argc, char *argv[]){
	vector<string> tokens;
	set <string> unique;
	string next_line;  // Each data line

	string filename = argv[1];
	vector <string> tokens_vector;

	ifstream in(argv[1]);
	while(getline(in, next_line)){
  	istringstream iss(next_line);
  	string token;
  	while(iss >> token) {
    	string nopunct = "";
    	for(auto &c : token){ // Remove Punctuation      
      	if(isalpha(c)){
        	nopunct +=c;       
      	}
    	}
	    tokens.push_back(nopunct);
		  unique.insert(nopunct);
		  //cout << token <<endl;
	  }
  }
	cout << "Number of words "<<tokens.size()<<endl;
	cout << "Number of unique words "<<unique.size()<<endl;
	ofstream set_file(filename + "_set.txt");
	for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it){
    //cout << ' ' << *it;
		set_file << ' ' << *it << endl;
	}
	cout << endl << endl;

//Part 2: into a vector
	ofstream vector_file(filename + "_vector.txt");
	for(int i = 0; i < tokens.size(); ++i){
		vector_file << ' ' << tokens.at(i) << endl;
	}

// 	Part 3: put the vector values into a map

	// ofstream map_file(filename + "_map.txt");
	// for (map<string, string>::iterator it=wordmap.begin(); it!=wordmap.end(); it++) {
	// 	cout << "first: " << it->first << " second: " << it-> second << endl;
	// 	map_file << it->first << "," << it->second << endl;
	// }
	//these pairs are in alphabetical order. But the key/value pairs should still match up.
	//but it will only keep track of the last occurance of the key

// //Part 4: generate 100 words of text
// 	//string state = "";
// 	for(int i = 0; i < 100; i++){
// 		cout << wordmap[state] << " ";
// 		state = wordmap[state];
// 	}
// 	cout << endl;

// map<string, vector<string>> wordmap;
// string state = "";
// for(vector<string>::iterator it=tokens.begin(); it !=tokens.end(); it++) {
//   wordmap[state].push_back(*it);
//   state = *it;
// }

// //Part 5: create sample text using all the words, not just some
// 	map<string, vector<string>> wordmap;
// 	string state = "";
// 	for(vector<string>::iterator it=tokens.begin(); it !=tokens.end(); it++) {
//   	wordmap[state].push_back(*it);
//   	state = *it;
// 	}

// 	srand(time(NULL)); // this line initializes the random number generated
//                    // so you dont get the same thing every time
// 	state = "";
// 	for (int i = 0; i < 100; i++) {
//   	int ind = rand() % wordmap[state].size();
//   	cout << wordmap[state][ind] << " ";
//   	state = wordmap[state][ind];
// 	}
// cout << endl;

//Part 6: create text that follows patterns of the English language
	const int M = 4;
	map<list<string>, vector<string>> wordmap;
  list<string> state;
  for (int i = 0; i < M; i++) {
    state.push_back("");
  }
                        
  for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
    wordmap[state].push_back(*it);
    state.push_back(*it);
    state.pop_front();
  }

	srand(time(NULL));

	state.clear();
  for (int i = 0; i < M; i++) {
    state.push_back("");
  }
  for (int i = 0; i < 100; i++) {
    int ind = rand() % wordmap[state].size();
    cout << wordmap[state][ind]<<" ";
    state.push_back(wordmap[state][ind]);
    state.pop_front();
  }
}
