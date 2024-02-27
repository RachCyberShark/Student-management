//code by Kung Samrach
//Phone : 0889766644
// FaceBook : Samrach Kung

#include<stdio.h>
#include<string.h>

// Define a struct named Student to represent student information
struct Student {
    char name[50], id[10];
    char sex;
    float  total, avg;
    int ds, c, eng;
};

int main() {
    // Declare an array of Student structs to store student data
    struct Student stu[100], temp;
    int i = 0, len;

    char sure, chooseUp;
    int choose, result[100], found, want, count;
    char del[10], up[10];
    char delName[50], IDjonknea[10], same[100][10], field[10];

start:
    system("cls"); // Clear the console screen
    // Display menu options
    printf("-------------------------------------------------------------------------------------------------------\n");
    printf("\t 1.Add  \t 2.Delete \t 3.Display \t 4.Update \t  5.sort  \n");
    printf("-------------------------------------------------------------------------------------------------------\n");
    printf(" ====>> Please Choose one 1 - 5 = "); scanf("%d", &choose);

    switch (choose) {
    case 1:
        // Add a new student
        printf("---------------------------------------------\n");
        printf("-----------------------<<<<<<<<<  Add Student >>>>>>>>>>-----------------------\n");
        printf("- Student %d\n", i + 1);
    ID:
        printf("\tPlease Input ID   = "); scanf("%s", stu[i].id);
        strcpy(IDjonknea, stu[i].id);
        // Check for duplicate IDs
        for (int j = 0; j < i; j++) {
            if (strcmp(IDjonknea, stu[j].id) == 0) {
                printf("You can't Input the same ID!\n Please Try to Enter Again..");
                goto ID;
            }
        }
        // Input student information
        printf("\tPlease Input Name = "); scanf("%s", stu[i].name);
        printf("\tPlease Input Sex  = "); scanf(" %c", &stu[i].sex);
        printf("\tPlease Input DS   = "); scanf("%d", &stu[i].ds);
        printf("\tPlease Input C#   = "); scanf("%d", &stu[i].c);
        printf("\tPlease Input Eng  = "); scanf("%d", &stu[i].eng);
        printf("Data Added Successfully\n");
        // Calculate total and average marks
        stu[i].total = stu[i].ds + stu[i].c + stu[i].eng;
        stu[i].avg = stu[i].total / 3;
        i++; // Increment the number of students
        system("pause"); // Pause the system to display message before continuing
        goto start; // Go back to the start of the loop
    case 2:
        // Delete a student
        printf("-------------------------------\n");
        printf("\t[Delete Option]\n1.Delete By ID\n2.Delete By Name\nchoose:");
        scanf("%d", &want);
        switch (want) {
        case 1:
            // Delete by ID
            printf("Which Student (ID) you want to delete?:"); scanf("%s", del);
            found = 0;
            // Find the student with the given ID
            for (int j = 0; j < i; j++) {
                if (strcmp(del, stu[j].id) == 0) {
                    // Display student information
                    printf("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult\n");
                    printf("%s\t%s\t%c\t", stu[j].id, stu[j].name, stu[j].sex);
                    printf("%d\t%d\t%d\t%.2f\t%.2f\t", stu[j].ds, stu[j].c, stu[j].eng, stu[j].total, stu[j].avg);
                    if (stu[j].avg >= 50)
                        printf("\tPass\n");
                    else
                        printf("\tFail\n");
                    found = 1; // Set found flag
                    printf("Are you sure to delete!![y/n]:"); scanf(" %c", &sure);
                    switch (sure) {
                    case 'y':
                    case 'Y':
                        // Shift remaining students in the array
                        for (int k = j; k < i - 1; k++) {
                            stu[k] = stu[k + 1];
                        }
                        i--; // Decrement the number of students
                        printf("Data Deleted Successfully!\n");
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
            printf("Which Student (Name) you want to delete?:"); scanf("%s", delName);
            found = 0;
            count = 0;
            int s = 0;
            // Display student information
            printf("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult\n");
            for (int j = 0; j < i; j++) {
                if (strcmp(delName, stu[j].name) == 0) {
                    printf("%s\t%s\t%c\t", stu[j].id, stu[j].name, stu[j].sex);
                    printf("%d\t%d\t%d\t%.2f\t%.2f\t", stu[j].ds, stu[j].c, stu[j].eng, stu[j].total, stu[j].avg);
                    if (stu[j].avg >= 50)
                        printf("\tPass\n");
                    else
                        printf("\tFail\n");
                    found = 1; // Set found flag
                    count++;
                    strcpy(same[s++], stu[j].id);
                }
            }
            // If multiple students have the same name, prompt for ID
            if (count > 1) {
                found = 0;
                printf("Which Student (ID) you want to delete?:"); scanf("%s", del);
                for (int j = 0; j <= s; j++) {
                    if (strcmp(del, same[j]) == 0) {
                        found = 1;
                        for (int k = 0; k < i; k++) {
                            if (strcmp(stu[k].id, del) == 0) {
                                printf("Are you sure to delete!![y/n]:"); scanf(" %c", &sure);
                                if (sure == 'Y' || sure == 'y') {
                                    // Shift remaining students in the array
                                    for (int l = k; l < i - 1; l++)
                                        stu[l] = stu[l + 1];
                                    i--; // Decrement the number of students
                                    printf("Data Deleted Successfully!\n");
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
                    if (strcmp(delName, stu[j].name) == 0) {
                        printf("Are you sure to delete!![y/n]:"); scanf(" %c", &sure);
                        switch (sure) {
                        case 'y':
                        case 'Y':
                            // Shift remaining students in the array
                            for (int k = j; k < i - 1; k++) {
                                stu[k] = stu[k + 1];
                            }
                            i--; // Decrement the number of students
                            printf("Data Deleted Successfully!\n");
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
            printf("Data not found\n");
        system("color 1");
        system("pause");
        goto start;
    case 3:
        // Display student information
        printf("------------------------------------------------------------------------------------\n");
        printf("------------------------   Display info student ----------------------------------\n");
        printf("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult\n");
        for (int j = 0; j < i; j++) {
            printf("%s\t%s\t%c\t", stu[j].id, stu[j].name, stu[j].sex);
            printf("%d\t%d\t%d\t%.2f\t%.2f\t", stu[j].ds, stu[j].c, stu[j].eng, stu[j].total, stu[j].avg);
            if (stu[j].avg >= 50)
                printf("\tPass\n");
            else
                printf("\tFail\n");
        }
        system("pause");
        goto start;
    case 4:
        // Update student information
        found = 0;
        printf("-------------------------------\n");
        printf("\t[Update]\n");
        printf("Which Student (ID) you want to Update?: "); scanf("%s", up);
        for (int j = 0; j < i; j++) {
            if (strcmp(up, stu[j].id) == 0) {
                // Display student information
                printf("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult\n");
                printf("%s\t%s\t%c\t", stu[j].id, stu[j].name, stu[j].sex);
                printf("%d\t%d\t%d\t%.2f\t%.2f\t", stu[j].ds, stu[j].c, stu[j].eng, stu[j].total, stu[j].avg);
                if (stu[j].avg >= 50)
                    printf("\tPass\n");
                else
                    printf("\tFail\n");
                found = 1; // Set found flag
            up:
                printf("Which Field="); scanf("%s", field);
                // Update the selected field
                if (strcmp(field, "name") == 0 || strcmp(field, "Name") == 0) {
                    printf("Name:"); scanf("%s", stu[j].name);
                }
                else if (strcmp(field, "ID") == 0 || strcmp(field, "id") == 0) {
                    printf("ID:"); scanf("%s", stu[j].id);
                }
                else if (strcmp(field, "sex") == 0 || strcmp(field, "Sex") == 0) {
                    printf("Sex:"); scanf(" %c", &stu[j].sex);
                }
                else if (strcmp(field, "ds") == 0 || strcmp(field, "DS") == 0) {
                    printf("DS:"); scanf("%d", &stu[j].ds);
                }
                else if (strcmp(field, "Eng") == 0 || strcmp(field, "eng") == 0) {
                    printf("Eng:"); scanf("%d", &stu[j].eng);
                }
                else if (strcmp(field, "C#") == 0 || strcmp(field, "c#") == 0) {
                    printf("C#:"); scanf("%d", &stu[j].c);
                }
                else {
                    printf("Wrong Field!\n");
                    goto up;
                }
                // Recalculate total and average marks
                stu[j].total = stu[j].ds + stu[j].c + stu[j].eng;
                stu[j].avg = stu[j].total / 3;
                printf("Do you want to update more?[Y/N]:"); scanf(" %c", &chooseUp);
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
            printf("Don't Found!!\n");
        system("pause");
        goto start;
    case 5:
        // Sort students by average marks
        printf("--------------------------------------sort by average----------------------------------\n");
        len = i; // Initialize len with the number of students
        for (int i = 0; i < len; i++) {
            for (int j = 0; j + 1 < len - i; j++) {
                if (stu[j].avg > stu[j + 1].avg) {
                    temp = stu[j];
                    stu[j] = stu[j + 1];
                    stu[j + 1] = temp;
                }
                else if (stu[j].avg == stu[j + 1].avg && strcmp(stu[j].name, stu[j + 1].name) > 0) {
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
