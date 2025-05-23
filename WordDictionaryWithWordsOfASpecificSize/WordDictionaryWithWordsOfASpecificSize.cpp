#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string directory;
string fileName;
int wordSize;

static void initDirectory();
static void initFile();
static void initWordSize();
static void readFile();
static ofstream openWriteFile();
static void closeWriteFile(ofstream& writeFile);
static void writeToFile(ofstream& writeFile, string line);


int main()
{
    initDirectory();
    initFile();
    initWordSize();
    readFile();
    return 0;
}

static void initDirectory() {
    cout << "Enter the directory of the file" << endl;
    cin >> directory;
}
static void initFile() {
    cout << "Enter the name of the file with the extension" << endl;
    cin >> fileName;
}

static void initWordSize() {
    while (true) {
        cout << "Enter the size of the words you want\n";
        cin >> wordSize;
        if (cin.fail() && wordSize <= 0) {
            cout << "Invalid input. Please enter a positive number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
}

static void readFile() {
    ofstream writeFile=openWriteFile();
    ifstream file(directory +"\\" + fileName);
    string line;
    while (getline(file, line)) {
        if (line.size() == wordSize) {
            writeToFile(writeFile, line);
       }
    }
    file.close();
    writeFile.close();
}

static ofstream openWriteFile() {
    ofstream writeFile(directory + "\\" + to_string(wordSize) + "_" + fileName);
    return writeFile;
}
static void closeWriteFile(ofstream& writeFile) {
    writeFile.close();
}
static void writeToFile(ofstream& writeFile,string line) {
    writeFile << line << endl;
}