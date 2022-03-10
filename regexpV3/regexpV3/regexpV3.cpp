#include <iostream>
#include <regex>
#include <fstream>
using namespace std;

int main() {
    regex e("[0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12}");
    string in_text, out_text;
    ifstream fin;
    ofstream fout;
    cout << "enter input file name" << endl;
    cin >> in_text;
    cout << "enter output file name" << endl;
    cin >> out_text;
   
    fin.open(in_text);
    fout.open(out_text);
    if (!fin.is_open())
    {
        cout << "check input file name" << endl;
        return 1;
        system("PAUSE");
    }
    while (fin.eof() != true)
    {
        string s;
        getline(fin, s);
        if (s.empty()) {
            continue;
        }
        if (!regex_search(s, e))
        {
            fout << s << endl;
        }
    }
    return 0;
}