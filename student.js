//code by Kung Samrach
//Phone : 0889766644
// FaceBook : Samrach Kung

// Define a struct named Student to represent student information
class Student {
    constructor(name, id, sex, total, avg, ds, c, eng) {
        this.name = name;
        this.id = id;
        this.sex = sex;
        this.total = total;
        this.avg = avg;
        this.ds = ds;
        this.c = c;
        this.eng = eng;
    }
}

// Declare an array of Student objects to store student data
let stu = [];
let i = 0;

let sure, chooseUp;
let choose, result = [], found, want, count;
let del, up;
let delName, IDjonknea, same = [], field;


console.clear(); // Clear the console screen
// Display menu options
console.log("-------------------------------------------------------------------------------------------------------");
console.log("\t 1.Add  \t 2.Delete \t 3.Display \t 4.Update \t  5.sort  ");
console.log("-------------------------------------------------------------------------------------------------------");
console.log(" ====>> Please Choose one 1 - 5 = ");
choose = parseInt(prompt(" ====>> Please Choose one 1 - 5 = "));

switch (choose) {
    case 1:
        // Add a new student
        console.log("---------------------------------------------");
        console.log("-----------------------<<<<<<<<<  Add Student >>>>>>>>>>-----------------------");
        console.log("- Student " + (i + 1));
    ID:
        stu[i] = new Student();
        stu[i].id = prompt("\tPlease Input ID   = ");
        IDjonknea = stu[i].id;
        // Check for duplicate IDs
        for (let j = 0; j < i; j++) {
            if (IDjonknea == stu[j].id) {
                console.log("You can't Input the same ID!\n Please Try to Enter Again..");
                goto ID;
            }
        }
        // Input student information
        stu[i].name = prompt("\tPlease Input Name = ");
        stu[i].sex = prompt("\tPlease Input Sex  = ");
        stu[i].ds = parseInt(prompt("\tPlease Input DS   = "));
        stu[i].c = parseInt(prompt("\tPlease Input C#   = "));
        stu[i].eng = parseInt(prompt("\tPlease Input Eng  = "));
        console.log("Data Added Successfully");
        // Calculate total and average marks
        stu[i].total = stu[i].ds + stu[i].c + stu[i].eng;
        stu[i].avg = stu[i].total / 3;
        i++; // Increment the number of students
        prompt("Press any key to continue...");
        goto start; // Go back to the start of the loop
    case 2:
        // Delete a student
        console.log("-------------------------------");
        console.log("\t[Delete Option]\n1.Delete By ID\n2.Delete By Name\nchoose:");
        want = parseInt(prompt("\t[Delete Option]\n1.Delete By ID\n2.Delete By Name\nchoose:"));
        switch (want) {
            case 1:
                // Delete by ID
                del = prompt("Which Student (ID) you want to delete?:");
                found = 0;
                // Find the student with the given ID
                for (let j = 0; j < i; j++) {
                    if (del == stu[j].id) {
                        // Display student information
                        console.log("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult");
                        console.log(stu[j].id + "\t" + stu[j].name + "\t" + stu[j].sex + "\t" + stu[j].ds + "\t" + stu[j].c + "\t" + stu[j].eng + "\t" + stu[j].total + "\t" + stu[j].avg + "\t");
                        if (stu[j].avg >= 50)
                            console.log("\tPass");
                        else
                            console.log("\tFail");
                        found = 1; // Set found flag
                        sure = prompt("Are you sure to delete!![y/n]:");
                        switch (sure) {
                            case 'y':
                            case 'Y':
                                // Shift remaining students in the array
                                for (let k = j; k < i - 1; k++) {
                                    stu[k] = stu[k + 1];
                                }
                                i--; // Decrement the number of students
                                console.log("Data Deleted Successfully!");
                                break;
                            case 'N':
                            case 'n':
                                prompt("Press any key to continue...");
                                goto start;
                        }
                    }
                }
                break;
            case 2:
                // Delete by name
                delName = prompt("Which Student (Name) you want to delete?:");
                found = 0;
                count = 0;
                let s = 0;
                // Display student information
                console.log("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult");
                for (let j = 0; j < i; j++) {
                    if (delName == stu[j].name) {
                        console.log(stu[j].id + "\t" + stu[j].name + "\t" + stu[j].sex + "\t" + stu[j].ds + "\t" + stu[j].c + "\t" + stu[j].eng + "\t" + stu[j].total + "\t" + stu[j].avg + "\t");
                        if (stu[j].avg >= 50)
                            console.log("\tPass");
                        else
                            console.log("\tFail");
                        found = 1; // Set found flag
                        count++;
                        same[s++] = stu[j].id;
                    }
                }
                // If multiple students have the same name, prompt for ID
                if (count > 1) {
                    found = 0;
                    del = prompt("Which Student (ID) you want to delete?:");
                    for (let j = 0; j <= s; j++) {
                        if (del == same[j]) {
                            found = 1;
                            for (let k = 0; k < i; k++) {
                                if (stu[k].id == del) {
                                    sure = prompt("Are you sure to delete!![y/n]:");
                                    if (sure == 'Y' || sure == 'y') {
                                        // Shift remaining students in the array
                                        for (let l = k; l < i - 1; l++)
                                            stu[l] = stu[l + 1];
                                        i--; // Decrement the number of students
                                        console.log("Data Deleted Successfully!");
                                    }
                                    else if (sure == 'n' || sure == 'N') {
                                        prompt("Press any key to continue...");
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
                    for (let j = 0; j < i; j++) {
                        if (delName == stu[j].name) {
                            sure = prompt("Are you sure to delete!![y/n]:");
                            switch (sure) {
                                case 'y':
                                case 'Y':
                                    // Shift remaining students in the array
                                    for (let k = j; k < i - 1; k++) {
                                        stu[k] = stu[k + 1];
                                    }
                                    i--; // Decrement the number of students
                                    console.log("Data Deleted Successfully!");
                                    break;
                                case 'N':
                                case 'n':
                                    prompt("Press any key to continue...");
                                    goto start;
                            }
                        }
                    }
                }
        }
        if (found == 0)
            console.log("Data not found");
        console.log("Press any key to continue...");
        goto start;
    case 3:
        // Display student information
        console.log("------------------------------------------------------------------------------------");
        console.log("------------------------   Display info student ----------------------------------");
        console.log("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult");
        for (let j = 0; j < i; j++) {
            console.log(stu[j].id + "\t" + stu[j].name + "\t" + stu[j].sex + "\t" + stu[j].ds + "\t" + stu[j].c + "\t" + stu[j].eng + "\t" + stu[j].total + "\t" + stu[j].avg + "\t");
            if (stu[j].avg >= 50)
                console.log("\tPass");
            else
                console.log("\tFail");
        }
        console.log("Press any key to continue...");
        goto start;
    case 4:
        // Update student information
        found = 0;
        console.log("-------------------------------");
        console.log("\t[Update]");
        up = prompt("Which Student (ID) you want to Update?: ");
        for (let j = 0; j < i; j++) {
            if (up == stu[j].id) {
                // Display student information
                console.log("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult");
                console.log(stu[j].id + "\t" + stu[j].name + "\t" + stu[j].sex + "\t" + stu[j].ds + "\t" + stu[j].c + "\t" + stu[j].eng + "\t" + stu[j].total + "\t" + stu[j].avg + "\t");
                if (stu[j].avg >= 50)
                    console.log("\tPass");
                else
                    console.log("\tFail");
                found = 1; // Set found flag
            up:
                field = prompt("Which Field=");
                // Update the selected field
                if (field == "name" || field == "Name") {
                    stu[j].name = prompt("Name:");
                }
                else if (field == "ID" || field == "id") {
                    stu[j].id = prompt("ID:");
                }
                else if (field == "sex" || field == "Sex") {
                    stu[j].sex = prompt("Sex:");
                }
                else if (field == "ds" || field == "DS") {
                    stu[j].ds = parseInt(prompt("DS:"));
                }
                else if (field == "Eng" || field == "eng") {
                    stu[j].eng = parseInt(prompt("Eng:"));
                }
                else if (field == "C#" || field == "c#") {
                    stu[j].c = parseInt(prompt("C#:"));
                }
                else {
                    console.log("Wrong Field!\n");
                    goto up;
                }
                // Recalculate total and average marks
                stu[j].total = stu[j].ds + stu[j].c + stu[j].eng;
                stu[j].avg = stu[j].total / 3;
                chooseUp = prompt("Do you want to update more?[Y/N]:");
                switch (chooseUp) {
                    case 'y':
                    case 'Y':
                        goto up;
                    case 'n':
                    case 'N':
                        console.log("Press any key to continue...");
                        goto start;
                }
            }
        }
        if (found == 0)
            console.log("Don't Found!!");
        console.log("Press any key to continue...");
        goto start;
    case 5:
        // Sort students by average marks
        console.log("--------------------------------------sort by average----------------------------------");
        len = i; // Initialize len with the number of students
        for (let i = 0; i < len; i++) {
            for (let j = 0; j + 1 < len - i; j++) {
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
