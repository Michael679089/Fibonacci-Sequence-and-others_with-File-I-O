#include <iostream> // for Input 'cin' function;
#include <fstream> // this is for ofstreams and ifstreams
#include <string> // This is for getline function

using namespace std;
// Variables:
string tempFile = "temporary.txt";
string fileName = "";

// void functions
void fibonacci()
{
    ofstream writeFile(tempFile);
    int firstTerm = 0;
    int secondTerm = 1;
    cout << "How many Fibonacci numbers (terms) do you want to display?: ";
    int terms;
    cin >> terms;

    cout << "Fibonacci Series: ";
    for (int i = 1; i <= terms - 2; i++) {
        // terms - 2 because I need to print the first & second term without adding them which is 1 and 0.
        if (i == 1) {
            cout << firstTerm << " ";
            writeFile << firstTerm << " ";
        }
        else if (i == 2) {
            cout << secondTerm << " ";
            writeFile << secondTerm << " ";
        }
        int thirdTerm = secondTerm + firstTerm;
        firstTerm = secondTerm;
        secondTerm = thirdTerm;

        cout << thirdTerm << " ";
        writeFile << thirdTerm << " ";
    }
    cout << endl;
    system("pause");
    writeFile.close();

    // Renaming File
    cout << "What's the name of the new file (no spaces): ";
    cin >> fileName;
    string file = fileName + ".txt";
    const char* a = file.c_str();
    const char* b = tempFile.c_str();
    if (rename(b, a) != 0) {
        perror("error");
    }

}
void Pascal()
{
    int max_rows, num = 1, row, w;
    cout << "How many rows do you want?: ";
    cin >> max_rows;

    ofstream writeFile(tempFile);
    for (row = 0; row < max_rows; row++)
    {
        for (w = 0; w <= row; w++)
        {
            if (w == 0 || row == 0) {
                num = 1;

            }
            else {
                num = num * (row - w + 1) / w;
                cout << num << "   ";
                writeFile << num << "   ";
            }
        }
        cout << endl;
        writeFile << "\n";
    }
    writeFile.close();

    // Renaming File
    cout << "What's the name of the new file (no spaces): ";
    cin >> fileName;
    string file = fileName + ".txt";
    const char* a = file.c_str();
    const char* b = tempFile.c_str();
    if (rename(b, a) != 0) {
        perror("error");
    }
}
void Floyd(void)
{
    bool isFileOK = false;
    while (isFileOK == false) {
        while (1 && isFileOK == false) {
            printf("Enter a non-negative number (to exit input any letter): ");
            unsigned int n;

            if (scanf_s("%u", &n) != 1 || n == 0) {
                break;
            }

            int width = 0;

            ofstream writeFile(tempFile);
            for (unsigned int tmp = n * (n + 1) / 2; tmp != 0; tmp /= 10) {
                ++width;
            }

            putchar('\n');
            writeFile << '\n';

            for (unsigned int i = 0; i < n; i++)
            {
                unsigned int value = (n - i) * (n - i + 1) / 2 - (n - i - 1);
                for (unsigned int j = 0; j < n - i; j++)
                {
                    printf("%*u ", -width, value++);
                    writeFile<< width << " " << value; 
                }
                putchar('\n');
                writeFile << '\n';
            }
            putchar('\n');
            writeFile << '\n';

            // Saving
            cout << "Is the File ready to be saved?" << endl;
            char charInput;
            cin >> charInput;
            if (charInput == 'y' || charInput == 'Y') {
                isFileOK = true;
                n = 0;
                break;
            }
        }
    }

    // Message
    cout << "The File will have it's inputs after the file has been finalized." << endl; 

    // Renaming File
    cout << "What's the name of the new file (no spaces): ";
    cin >> fileName;
    string file = fileName + ".txt";
    const char* a = file.c_str();
    const char* b = tempFile.c_str();
    if (rename(b, a) != 0) {
        perror("error");
    }
}

void printFile() {
    cout << "What's the file name: ";
    cin >> fileName;
    ifstream readFile(fileName + ".txt");
    if (readFile) {
        string text;
        while (getline(readFile, text)) {
            cout << text;
        }
    }
    else {
        cout << "File doesn't exist, you must create one to have a file." << endl;
    }
    cout << endl;
    readFile.close(); 
}

// Main Function
int main() {
    char ans = ' ';
    while (ans != '0') {
        cout << "What function do you want to try out?" << endl;
        cout << "1 - Fibonacci sequence" << endl;
        cout << "2 - Pascal's Triangle" << endl;
        cout << "3 - Floyd's Triangle" << endl;
        cout << "4 - Check Old File" << endl;
        cout << "0 - Quit Program" << endl;
        cout << ">";
        cin >> ans;
        system("cls");


        if (ans == '0') {
            cout << "goodbye!";
        }
        else if (ans == '1') {
            fibonacci();
        }
        else if (ans == '2') {
            Pascal();
        }
        else if (ans == '3') {
            Floyd();
        }
        else if (ans == '4') {
            printFile();
        }
    }
    return 0;
}
