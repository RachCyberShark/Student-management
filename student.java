//code by Kung Samrach
//Phone : 0889766644
// FaceBook : Samrach Kung

import java.util.Scanner;

// Define a class named Student to represent student information
class Student {
    String name, id;
    char sex;
    float total, avg;
    int ds, c, eng;
}

public class Main {
    public static void main(String[] args) {
        // Declare an array of Student objects to store student data
        Student[] stu = new Student[100];
        Student temp;
        int i = 0, len;

        char sure, chooseUp;
        int choose, result[] = new int[100], found, want, count;
        String del, up;
        String delName, IDjonknea, same[] = new String[100], field;

        Scanner scanner = new Scanner(System.in);

    start:
        // Clear the console screen
        System.out.print("\033[H\033[2J");
        System.out.flush();

        // Display menu options
        System.out.println("-------------------------------------------------------------------------------------------------------");
        System.out.println("\t 1.Add  \t 2.Delete \t 3.Display \t 4.Update \t  5.sort  ");
        System.out.println("-------------------------------------------------------------------------------------------------------");
        System.out.print(" ====>> Please Choose one 1 - 5 = ");
        choose = scanner.nextInt();

        switch (choose) {
            case 1:
                // Add a new student
                System.out.println("---------------------------------------------");
                System.out.println("-----------------------<<<<<<<<<  Add Student >>>>>>>>>>-----------------------");
                System.out.println("- Student " + (i + 1));

                ID:
                System.out.print("\tPlease Input ID   = ");
                stu[i].id = scanner.next();
                IDjonknea = stu[i].id;

                // Check for duplicate IDs
                for (int j = 0; j < i; j++) {
                    if (IDjonknea.equals(stu[j].id)) {
                        System.out.println("You can't Input the same ID!\n Please Try to Enter Again..");
                        goto ID;
                    }
                }

                // Input student information
                System.out.print("\tPlease Input Name = ");
                stu[i].name = scanner.next();
                System.out.print("\tPlease Input Sex  = ");
                stu[i].sex = scanner.next().charAt(0);
                System.out.print("\tPlease Input DS   = ");
                stu[i].ds = scanner.nextInt();
                System.out.print("\tPlease Input C#   = ");
                stu[i].c = scanner.nextInt();
                System.out.print("\tPlease Input Eng  = ");
                stu[i].eng = scanner.nextInt();
                System.out.println("Data Added Successfully");

                // Calculate total and average marks
                stu[i].total = stu[i].ds + stu[i].c + stu[i].eng;
                stu[i].avg = stu[i].total / 3;
                i++; // Increment the number of students

                scanner.nextLine(); // Consume the newline character
                System.out.println("Press Enter to continue...");
                scanner.nextLine(); // Pause the system to display message before continuing
                goto start; // Go back to the start of the loop

            case 2:
                // Delete a student
                System.out.println("-------------------------------");
                System.out.println("\t[Delete Option]\n1.Delete By ID\n2.Delete By Name\nchoose:");
                want = scanner.nextInt();

                switch (want) {
                    case 1:
                        // Delete by ID
                        System.out.print("Which Student (ID) you want to delete?: ");
                        del = scanner.next();
                        found = 0;

                        // Find the student with the given ID
                        for (int j = 0; j < i; j++) {
                            if (del.equals(stu[j].id)) {
                                // Display student information
                                System.out.println("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult");
                                System.out.print(stu[j].id + "\t" + stu[j].name + "\t" + stu[j].sex + "\t");
                                System.out.print(stu[j].ds + "\t" + stu[j].c + "\t" + stu[j].eng + "\t" + stu[j].total + "\t" + stu[j].avg + "\t");
                                if (stu[j].avg >= 50)
                                    System.out.println("\tPass");
                                else
                                    System.out.println("\tFail");

                                found = 1; // Set found flag

                                System.out.print("Are you sure to delete!![y/n]: ");
                                sure = scanner.next().charAt(0);

                                switch (sure) {
                                    case 'y':
                                    case 'Y':
                                        // Shift remaining students in the array
                                        for (int k = j; k < i - 1; k++) {
                                            stu[k] = stu[k + 1];
                                        }
                                        i--; // Decrement the number of students
                                        System.out.println("Data Deleted Successfully!");
                                        break;
                                    case 'N':
                                    case 'n':
                                        System.out.println("Press Enter to continue...");
                                        scanner.nextLine(); // Consume the newline character
                                        scanner.nextLine(); // Pause the system to display message before continuing
                                        goto start;
                                }
                            }
                        }
                        break;

                    case 2:
                        // Delete by name
                        System.out.print("Which Student (Name) you want to delete?: ");
                        delName = scanner.next();
                        found = 0;
                        count = 0;
                        int s = 0;

                        // Display student information
                        System.out.println("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult");

                        for (int j = 0; j < i; j++) {
                            if (delName.equals(stu[j].name)) {
                                System.out.print(stu[j].id + "\t" + stu[j].name + "\t" + stu[j].sex + "\t");
                                System.out.print(stu[j].ds + "\t" + stu[j].c + "\t" + stu[j].eng + "\t" + stu[j].total + "\t" + stu[j].avg + "\t");
                                if (stu[j].avg >= 50)
                                    System.out.println("\tPass");
                                else
                                    System.out.println("\tFail");

                                found = 1; // Set found flag
                                count++;
                                same[s++] = stu[j].id;
                            }
                        }

                        // If multiple students have the same name, prompt for ID
                        if (count > 1) {
                            found = 0;
                            System.out.print("Which Student (ID) you want to delete?: ");
                            del = scanner.next();

                            for (int j = 0; j <= s; j++) {
                                if (del.equals(same[j])) {
                                    found = 1;

                                    for (int k = 0; k < i; k++) {
                                        if (stu[k].id.equals(del)) {
                                            System.out.print("Are you sure to delete!![y/n]: ");
                                            sure = scanner.next().charAt(0);

                                            if (sure == 'Y' || sure == 'y') {
                                                // Shift remaining students in the array
                                                for (int l = k; l < i - 1; l++)
                                                    stu[l] = stu[l + 1];
                                                i--; // Decrement the number of students
                                                System.out.println("Data Deleted Successfully!");
                                            } else if (sure == 'n' || sure == 'N') {
                                                System.out.println("Press Enter to continue...");
                                                scanner.nextLine(); // Consume the newline character
                                                scanner.nextLine(); // Pause the system to display message before continuing
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
                                if (delName.equals(stu[j].name)) {
                                    System.out.print("Are you sure to delete!![y/n]: ");
                                    sure = scanner.next().charAt(0);

                                    switch (sure) {
                                        case 'y':
                                        case 'Y':
                                            // Shift remaining students in the array
                                            for (int k = j; k < i - 1; k++) {
                                                stu[k] = stu[k + 1];
                                            }
                                            i--; // Decrement the number of students
                                            System.out.println("Data Deleted Successfully!");
                                            break;
                                        case 'N':
                                        case 'n':
                                            System.out.println("Press Enter to continue...");
                                            scanner.nextLine(); // Consume the newline character
                                            scanner.nextLine(); // Pause the system to display message before continuing
                                            goto start;
                                    }
                                }
                            }
                        }
                }

                if (found == 0)
                    System.out.println("Data not found");

                System.out.println("Press Enter to continue...");
                scanner.nextLine(); // Consume the newline character
                scanner.nextLine(); // Pause the system to display message before continuing
                goto start;

            case 3:
                // Display student information
                System.out.println("------------------------------------------------------------------------------------");
                System.out.println("------------------------   Display info student ----------------------------------");
                System.out.println("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult");

                for (int j = 0; j < i; j++) {
                    System.out.print(stu[j].id + "\t" + stu[j].name + "\t" + stu[j].sex + "\t");
                    System.out.print(stu[j].ds + "\t" + stu[j].c + "\t" + stu[j].eng + "\t" + stu[j].total + "\t" + stu[j].avg + "\t");
                    if (stu[j].avg >= 50)
                        System.out.println("\tPass");
                    else
                        System.out.println("\tFail");
                }

                System.out.println("Press Enter to continue...");
                scanner.nextLine(); // Consume the newline character
                scanner.nextLine(); // Pause the system to display message before continuing
                goto start;

            case 4:
                // Update student information
                found = 0;
                System.out.println("-------------------------------");
                System.out.println("\t[Update]");
                System.out.print("Which Student (ID) you want to Update?: ");
                up = scanner.next();

                for (int j = 0; j < i; j++) {
                    if (up.equals(stu[j].id)) {
                        // Display student information
                        System.out.println("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult");
                        System.out.print(stu[j].id + "\t" + stu[j].name + "\t" + stu[j].sex + "\t");
                        System.out.print(stu[j].ds + "\t" + stu[j].c + "\t" + stu[j].eng + "\t" + stu[j].total + "\t" + stu[j].avg + "\t");
                        if (stu[j].avg >= 50)
                            System.out.println("\tPass");
                        else
                            System.out.println("\tFail");

                        found = 1; // Set found flag

                        up:
                        System.out.print("Which Field= ");
                        field = scanner.next();

                        // Update the selected field
                        if (field.equalsIgnoreCase("name")) {
                            System.out.print("Name: ");
                            stu[j].name = scanner.next();
                        } else if (field.equalsIgnoreCase("ID")) {
                            System.out.print("ID: ");
                            stu[j].id = scanner.next();
                        } else if (field.equalsIgnoreCase("sex")) {
                            System.out.print("Sex: ");
                            stu[j].sex = scanner.next().charAt(0);
                        } else if (field.equalsIgnoreCase("ds")) {
                            System.out.print("DS: ");
                            stu[j].ds = scanner.nextInt();
                        } else if (field.equalsIgnoreCase("Eng")) {
                            System.out.print("Eng: ");
                            stu[j].eng = scanner.nextInt();
                        } else if (field.equalsIgnoreCase("C#")) {
                            System.out.print("C#: ");
                            stu[j].c = scanner.nextInt();
                        } else {
                            System.out.println("Wrong Field!\n");
                            goto up;
                        }

                        // Recalculate total and average marks
                        stu[j].total = stu[j].ds + stu[j].c + stu[j].eng;
                        stu[j].avg = stu[j].total / 3;

                        System.out.print("Do you want to update more?[Y/N]: ");
                        chooseUp = scanner.next().charAt(0);

                        switch (chooseUp) {
                            case 'y':
                            case 'Y':
                                goto up;
                            case 'n':
                            case 'N':
                                System.out.println("Press Enter to continue...");
                                scanner.nextLine(); // Consume the newline character
                                scanner.nextLine(); // Pause the system to display message before continuing
                                goto start;
                        }
                    }
                }

                if (found == 0)
                    System.out.println("Don't Found!!");

                System.out.println("Press Enter to continue...");
                scanner.nextLine(); // Consume the newline character
                scanner.nextLine(); // Pause the system to display message before continuing
                goto start;

            case 5:
                // Sort students by average marks
                System.out.println("--------------------------------------sort by average----------------------------------");
                len = i; // Initialize len with the number of students

                for (int x = 0; x < len; x++) {
                    for (int j = 0; j + 1 < len - x; j++) {
                        if (stu[j].avg > stu[j + 1].avg) {
                            temp = stu[j];
                            stu[j] = stu[j + 1];
                            stu[j + 1] = temp;
                        } else if (stu[j].avg == stu[j + 1].avg && stu[j].name.compareTo(stu[j + 1].name) > 0) {
                            temp = stu[j];
                            stu[j] = stu[j + 1];
                            stu[j + 1] = temp;
                        }
                    }
                }
                break;

