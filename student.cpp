//code by Kung Samrach
//Phone : 0889766644
// FaceBook : Samrach Kung

#include<iostream>
#include<string>
using namespace std;

// Define a struct named Student to represent student information
struct Student {
    string name, id;
    char sex;
    float  total, avg;
    int ds, c, eng;
};

int main() {
    // Declare an array of Student structs to store student data
    Student stu[100], temp;
    int i = 0, len;

    char sure, chooseUp;
    int choose, result[100], found, want, count;
    string del, up;
    string delName, IDjonknea, same[100], field;

start:
    system("cls"); // Clear the console screen
    // Display menu options
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t 1.Add  \t 2.Delete \t 3.Display \t 4.Update \t  5.sort  " << endl;
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    cout << " ====>> Please Choose one 1 - 5 = "; cin >> choose;

    switch (choose) {
    case 1:
        // Add a new student
        cout << "---------------------------------------------" << endl;
        cout << "-----------------------<<<<<<<<<  Add Student >>>>>>>>>>-----------------------" << endl;
        cout << "- Student " << i + 1 << endl;
    ID:
        cout << "\tPlease Input ID   = "; cin >> stu[i].id;
        IDjonknea = stu[i].id;
        // Check for duplicate IDs
        for (int j = 0; j < i; j++) {
            if (IDjonknea == stu[j].id) {
                cout << "You can't Input the same ID!\n Please Try to Enter Again..";
                goto ID;
            }
        }
        // Input student information
        cout << "\tPlease Input Name = "; cin >> stu[i].name;
        cout << "\tPlease Input Sex  = "; cin >> stu[i].sex;
        cout << "\tPlease Input DS   = "; cin >> stu[i].ds;
        cout << "\tPlease Input C#   = "; cin >> stu[i].c;
        cout << "\tPlease Input Eng  = "; cin >> stu[i].eng;
        cout << "Data Added Successfully" << endl;
        // Calculate total and average marks
        stu[i].total = stu[i].ds + stu[i].c + stu[i].eng;
        stu[i].avg = stu[i].total / 3;
        i++; // Increment the number of students
        system("pause"); // Pause the system to display message before continuing
        goto start; // Go back to the start of the loop
    case 2:
        // Delete a student
        cout << "-------------------------------" << endl;
        cout << "\t[Delete Option]\n1.Delete By ID\n2.Delete By Name\nchoose:";
        cin >> want;
        switch (want) {
        case 1:
            // Delete by ID
            cout << "Which Student (ID) you want to delete?:"; cin >> del;
            found = 0;
            // Find the student with the given ID
            for (int j = 0; j < i; j++) {
                if (del == stu[j].id) {
                    // Display student information
                    cout << "ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult" << endl;
                    cout << stu[j].id << "\t" << stu[j].name << "\t" << stu[j].sex << "\t";
                    cout << stu[j].ds << "\t" << stu[j].c << "\t" << stu[j].eng << "\t" << stu[j].total << "\t" << stu[j].avg << "\t";
                    if (stu[j].avg >= 50)
                        cout << "\tPass" << endl;
                    else
                        cout << "\tFail" << endl;
                    found = 1; // Set found flag
                    cout << "Are you sure to delete!![y/n]:"; cin >> sure;
                    switch (sure) {
                    case 'y':
                    case 'Y':
                        // Shift remaining students in the array
                        for (int k = j; k < i - 1; k++) {
                            stu[k] = stu[k + 1];
                        }
                        i--; // Decrement the number of students
                        cout << "Data Deleted Successfully!" << endl;
                        break;
                    case 'N':
                    case 'n':
                        system("pause");
                        goto start;
                    }
                }
            }
            break;
        case 2:
            // Delete by name
            cout << "Which Student (Name) you want to delete?:"; cin >> delName;
            found = 0;
            count = 0;
            int s = 0;
            // Display student information
            cout << "ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult" << endl;
            for (int j = 0; j < i; j++) {
                if (delName == stu[j].name) {
                    cout << stu[j].id << "\t" << stu[j].name << "\t" << stu[j].sex << "\t";
                    cout << stu[j].ds << "\t" << stu[j].c << "\t" << stu[j].eng << "\t" << stu[j].total << "\t" << stu[j].avg << "\t";
                    if (stu[j].avg >= 50)
                        cout << "\tPass" << endl;
                    else
                        cout << "\tFail" << endl;
                    found = 1; // Set found flag
                    count++;
                    same[s++] = stu[j].id;
                }
            }
            // If multiple students have the same name, prompt for ID
            if (count > 1) {
                found = 0;
                cout << "Which Student (ID) you want to delete?:"; cin >> del;
                for (int j = 0; j <= s; j++) {
                    if (del == same[j]) {
                        found = 1;
                        for (int k = 0; k < i; k++) {
                            if (stu[k].id == del) {
                                cout << "Are you sure to delete!![y/n]:"; cin >> sure;
                                if (sure == 'Y' || sure == 'y') {
                                    // Shift remaining students in the array
                                    for (int l = k; l < i - 1; l++)
                                        stu[l] = stu[l + 1];
                                    i--; // Decrement the number of students
                                    cout << "Data Deleted Successfully!" << endl;
                                }
                                else if (sure == 'n' || sure == 'N') {
                                    system("pause");
                                    goto start;
                                }
                                break;
                            }
                        }
                    }
                }
            }
            // If only one student found, directly delete
            else if (count == 1) {
                for (int j = 0; j < i; j++) {
                    if (delName == stu[j].name) {
                        cout << "Are you sure to delete!![y/n]:"; cin >> sure;
                        switch (sure) {
                        case 'y':
                        case 'Y':
                            // Shift remaining students in the array
                            for (int k = j; k < i - 1; k++) {
                                stu[k] = stu[k + 1];
                            }
                            i--; // Decrement the number of students
                            cout << "Data Deleted Successfully!" << endl;
                            break;
                        case 'N':
                        case 'n':
                            system("pause");
                            goto start;
                        }
                    }
                }
            }
        }
        if (found == 0)
            cout << "Data not found" << endl;
        system("color 1");
        system("pause");
        goto start;
    case 3:
        // Display student information
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << "------------------------   Display info student ----------------------------------" << endl;
        cout << "ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult" << endl;
        for (int j = 0; j < i; j++) {
            cout << stu[j].id << "\t" << stu[j].name << "\t" << stu[j].sex << "\t";
            cout << stu[j].ds << "\t" << stu[j].c << "\t" << stu[j].eng << "\t" << stu[j].total << "\t" << stu[j].avg << "\t";
            if (stu[j].avg >= 50)
                cout << "\tPass" << endl;
            else
                cout << "\tFail" << endl;
        }
        system("pause");
        goto start;
    case 4:
        // Update student information
        found = 0;
        cout << "-------------------------------" << endl;
        cout << "\t[Update]" << endl;
        cout << "Which Student (ID) you want to Update?: "; cin >> up;
        for (int j = 0; j < i; j++) {
            if (up == stu[j].id) {
                // Display student information
                cout << "ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult" << endl;
                cout << stu[j].id << "\t" << stu[j].name << "\t" << stu[j].sex << "\t";
                cout << stu[j].ds << "\t" << stu[j].c << "\t" << stu[j].eng << "\t" << stu[j].total << "\t" << stu[j].avg << "\t";
                if (stu[j].avg >= 50)
                    cout << "\tPass" << endl;
                else
                    cout << "\tFail" << endl;
                found = 1; // Set found flag
            up:
                cout << "Which Field="; cin >> field;
                // Update the selected field
                if (field == "name" || field == "Name") {
                    cout << "Name:"; cin >> stu[j].name;
                }
                else if (field == "ID" || field == "id") {
                    cout << "ID:"; cin >> stu[j].id;
                }
                else if (field == "sex" || field == "Sex") {
                    cout << "Sex:"; cin >> stu[j].sex;
                }
                else if (field == "ds" || field == "DS") {
                    cout << "DS:"; cin >> stu[j].ds;
                }
                else if (field == "Eng" || field == "eng") {
                    cout << "Eng:"; cin >> stu[j].eng;
                }
                else if (field == "C#" || field == "c#") {
                    cout << "C#:"; cin >> stu[j].c;
                }
                else {
                    cout << "Wrong Field!\n";
                    goto up;
                }
                // Recalculate total and average marks
                stu[j].total = stu[j].ds + stu[j].c + stu[j].eng;
                stu[j].avg = stu[j].total / 3;
                cout << "Do you want to update more?[Y/N]:"; cin >> chooseUp;
                switch (chooseUp) {
                case 'y':
                case 'Y':
                    goto up;
                case 'n':
                case 'N':
                    system("color A");
                    system("pause");
                    goto start;
                }
            }
        }
        if (found == 0)
            cout << "Don't Found!!";
        system("pause");
        goto start;
    case 5:
        // Sort students by average marks
        cout << "--------------------------------------sort by average----------------------------------" << endl;
        len = i; // Initialize len with the number of students
        for (int i = 0; i < len; i++) {
            for (int j = 0; j + 1 < len - i; j++) {
                if (stu[j].avg > stu[j + 1].avg) {
                    temp = stu[j];
                    stu[j] = stu[j + 1];
                    stu[j + 1] = temp;
                }
                else if (stu[j].avg == stu[j + 1].avg && stu[j].name > stu[j + 1].name) {
                    temp = stu[j];
                    stu[j] = stu[j + 1];
                    stu[j + 1] = temp;
                }
            }
        }
        break;
    default:
        goto start;
    }
    return 0;
}
