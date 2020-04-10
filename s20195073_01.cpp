#include <iostream>
#include <fstream>
#include <string>
#include <map>
#define INF 12345678
using namespace std;

string str;
char ans[INF];
int len, chkstr[INF];
map<string, int> m;
ifstream inputfile;
ofstream outputfile;

void makestr(int startnum)
{
	if (startnum == len){
		if (m.find(ans)==m.end()){
			m[ans] = 1;
			outputfile << ans;
			outputfile << endl;
		}
		return;
	}
	for (int i=0;i<len;i++){
		if (!chkstr[i]){
			chkstr[i] = 1;
			ans[startnum] = str[i];
			makestr(startnum+1);
			chkstr[i] = 0;
		}
	}
	return;
}

int main(int argc, char* argv[])
{	
	if (argc < 3) cout << "Usage: " << argv[0] << " inputfile outputfile" << endl;
	
	inputfile.open(argv[1]);
	if (inputfile.fail()) cout << "Cannot open inputfile" << endl;
	
	outputfile.open(argv[2]);
	if (outputfile.fail()) cout << "Cannot open outputfile" << endl;
	
	if (inputfile.is_open() && outputfile.is_open()){
		string cache = "";
		while(getline(inputfile, cache)){
			str +=  cache.c_str()[0];
			len++;
		}
		if (str[len-1] == '\0') len--;
		makestr(0);
	}
	inputfile.close();
	outputfile.close();
	return 0;
}

