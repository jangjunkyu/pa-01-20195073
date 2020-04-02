#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char* argv[]){
	ifstream inputfile; // ifstream: used to read from files
	ofstream outputfile; // ofstream: used to create files and write on files
	

	if(argc < 3) {
		cout <<"Usage: " << argv[0] << "inputfile output_file" <<endl; 
	}
	

	inputfile.open(argv[1]);
	if(inputfile.fail()) 
		cout << "Cannot open inpufile" <<endl;

	outputfile.open(argv[2]);
	if(outputfile.fail()) 
		cout << "Cannot open outputfile" << endl;


	if(inputfile.is_open()) {
		string line;
		while (getline(inputfile, line)) {
			cout << line << endl;
			outputfile << line;
			outputfile << endl;
		}
  
	}
	inputfile.close();
	outputfile.close();
	return 0;
}
