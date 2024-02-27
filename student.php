<?php
//code by Kung Samrach
//Phone : 0889766644
// FaceBook : Samrach Kung

// Define a class named Student to represent student information
class Student {
    public $name, $id;
    public $sex;
    public $total, $avg;
    public $ds, $c, $eng;
}

// Declare an array of Student objects to store student data
$stu = array();
$i = 0;

$sure;
$chooseUp;
$choose;
$result = array();
$found;
$want;
$count;
$del;
$up;
$delName;
$IDjonknea;
$same = array();
$field;

start:
system("cls"); // Clear the console screen
// Display menu options
echo "-------------------------------------------------------------------------------------------------------" . PHP_EOL;
echo "\t 1.Add  \t 2.Delete \t 3.Display \t 4.Update \t  5.sort  " . PHP_EOL;
echo "-------------------------------------------------------------------------------------------------------" . PHP_EOL;
echo " ====>> Please Choose one 1 - 5 = ";
$choose = readline();

switch ($choose) {
    case 1:
        // Add a new student
        echo "---------------------------------------------" . PHP_EOL;
        echo "-----------------------<<<<<<<<<  Add Student >>>>>>>>>>-----------------------" . PHP_EOL;
        echo "- Student " . ($i + 1) . PHP_EOL;
    ID:
        echo "\tPlease Input ID   = ";
        $stu[$i]->id = readline();
        $IDjonknea = $stu[$i]->id;
        // Check for duplicate IDs
        for ($j = 0; $j < $i; $j++) {
            if ($IDjonknea == $stu[$j]->id) {
                echo "You can't Input the same ID!\n Please Try to Enter Again..";
                goto ID;
            }
        }
        // Input student information
        echo "\tPlease Input Name = ";
        $stu[$i]->name = readline();
        echo "\tPlease Input Sex  = ";
        $stu[$i]->sex = readline();
        echo "\tPlease Input DS   = ";
        $stu[$i]->ds = readline();
        echo "\tPlease Input C#   = ";
        $stu[$i]->c = readline();
        echo "\tPlease Input Eng  = ";
        $stu[$i]->eng = readline();
        echo "Data Added Successfully" . PHP_EOL;
        // Calculate total and average marks
        $stu[$i]->total = $stu[$i]->ds + $stu[$i]->c + $stu[$i]->eng;
        $stu[$i]->avg = $stu[$i]->total / 3;
        $i++; // Increment the number of students
          system("pause"); // Pause the system to display message before continuing
        goto start; // Go back to the start of the loop
    case 2:
        // Delete a student
        echo "-------------------------------" . PHP_EOL;
        echo "\t[Delete Option]\n1.Delete By ID\n2.Delete By Name\nchoose:";
        $want = readline();
        switch ($want) {
            case 1:
                // Delete by ID
                echo "Which Student (ID) you want to delete?:";
                $del = readline();
                $found = 0;
                // Find the student with the given ID
                for ($j = 0; $j < $i; $j++) {
                    if ($del == $stu[$j]->id) {
                        // Display student information
                        echo "ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult" . PHP_EOL;
                        echo $stu[$j]->id . "\t" . $stu[$j]->name . "\t" . $stu[$j]->sex . "\t";
                        echo $stu[$j]->ds . "\t" . $stu[$j]->c . "\t" . $stu[$j]->eng . "\t" . $stu[$j]->total . "\t" . $stu[$j]->avg . "\t";
                        if ($stu[$j]->avg >= 50)
                            echo "\tPass" . PHP_EOL;
                        else
                            echo "\tFail" . PHP_EOL;
                        $found = 1; // Set found flag
                        echo "Are you sure to delete!![y/n]:";
                        $sure = readline();
                        switch ($sure) {
                            case 'y':
                            case 'Y':
                                // Shift remaining students in the array
                                for ($k = $j; $k < $i - 1; $k++) {
                                    $stu[$k] = $stu[$k + 1];
                                }
                                $i--; // Decrement the number of students
                                echo "Data Deleted Successfully!" . PHP_EOL;
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
                echo "Which Student (Name) you want to delete?:";
                $delName = readline();
                $found = 0;
                $count = 0;
                $s = 0;
                // Display student information
                echo "ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult" . PHP_EOL;
                for ($j = 0; $j < $i; $j++) {
                    if ($delName == $stu[$j]->name) {
                        echo $stu[$j]->id . "\t" . $stu[$j]->name . "\t" . $stu[$j]->sex . "\t";
                        echo $stu[$j]->ds . "\t" . $stu[$j]->c . "\t" . $stu[$j]->eng . "\t" . $stu[$j]->total . "\t" . $stu[$j]->avg . "\t";
                        if ($stu[$j]->avg >= 50)
                            echo "\tPass" . PHP_EOL;
                        else
                            echo "\tFail" . PHP_EOL;
                        $found = 1; // Set found flag
                        $count++;
                        $same[$s++] = $stu[$j]->id;
                    }
                }
                // If multiple students have the same name, prompt for ID
                if ($count > 1) {
                    $found = 0;
                    echo "Which Student (ID) you want to delete?:";
                    $del = readline();
                    for ($j = 0; $j <= $s; $j++) {
                        if ($del == $same[$j]) {
                            $found = 1;
                            for ($k = 0; $k < $i; $k++) {
                                if ($stu[$k]->id == $del) {
                                    echo "Are you sure to delete!![y/n]:";
                                    $sure = readline();
                                    if ($sure == 'Y' || $sure == 'y') {
                                        // Shift remaining students in the array
                                        for ($l = $k; $l < $i - 1; $l++)
                                            $stu[$l] = $stu[$l + 1];
                                        $i--; // Decrement the number of students
                                        echo "Data Deleted Successfully!" . PHP_EOL;
                                    } else if ($sure == 'n' || $sure == 'N') {
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
                else if ($count == 1) {
                    for ($j = 0; $j < $i; $j++) {
                        if ($delName == $stu[$j]->name) {
                            echo "Are you sure to delete!![y/n]:";
                            $sure = readline();
                            switch ($sure) {
                                case 'y':
                                case 'Y':
                                    // Shift remaining students in the array
                                    for ($k = $j; $k < $i - 1; $k++) {
                                        $stu[$k] = $stu[$k + 1];
                                    }
                                    $i--; // Decrement the number of students
                                    echo "Data Deleted Successfully!" . PHP_EOL;
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
        if ($found == 0)
            echo "Data not found" . PHP_EOL;
        system("color 1");
        system("pause");
        goto start;
    case 3:
        // Display student information
        echo "------------------------------------------------------------------------------------" . PHP_EOL;
        echo "------------------------   Display info student ----------------------------------" . PHP_EOL;
        echo "ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult" . PHP_EOL;
        for ($j = 0; $j < $i; $j++) {
            echo $stu[$j]->id . "\t" . $stu[$j]->name . "\t" . $stu[$j]->sex . "\t";
            echo $stu[$j]->ds . "\t" . $stu[$j]->c . "\t" . $stu[$j]->eng . "\t" . $stu[$j]->total . "\t" . $stu[$j]->avg . "\t";
            if ($stu[$j]->avg >= 50)
                echo "\tPass" . PHP_EOL;
            else
                echo "\tFail" . PHP_EOL;
        }
        system("pause");
        goto start;
    case 4:
        // Update student information
        $found = 0;
        echo "-------------------------------" . PHP_EOL;
        echo "\t[Update]" . PHP_EOL;
        echo "Which Student (ID) you want to Update?: ";
        $up = readline();
        for ($j = 0; $j < $i; $j++) {
            if ($up == $stu[$j]->id) {
                // Display student information
                echo "ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult" . PHP_EOL;
                echo $stu[$j]->id . "\t" . $stu[$j]->name . "\t" . $stu[$j]->sex . "\t";
                echo $stu[$j]->ds . "\t" . $stu[$j]->c . "\t" . $stu[$j]->eng . "\t" . $stu[$j]->total . "\t" . $stu[$j]->avg . "\t";
                if ($stu[$j]->avg >= 50)
                    echo "\tPass" . PHP_EOL;
                else
                    echo "\tFail" . PHP_EOL;
                $found = 1; // Set found flag
            up:
                echo "Which Field=";
                $field = readline();
                // Update the selected field
                if ($field == "name" || $field == "Name") {
                    echo "Name:";
                    $stu[$j]->name = readline();
                } else if ($field == "ID" || $field == "id") {
                    echo "ID:";
                    $stu[$j]->id = readline();
                } else if ($field == "sex" || $field == "Sex") {
                    echo "Sex:";
                    $stu[$j]->sex = readline();
                } else if ($field == "ds" || $field == "DS") {
                    echo "DS:";
                    $stu[$j]->ds = readline();
                } else if ($field == "Eng" || $field == "eng") {
                    echo "Eng:";
                    $stu[$j]->eng = readline();
                } else if ($field == "C#" || $field == "c#") {
                    echo "C#:";
                    $stu[$j]->c = readline();
                } else {
                    echo "Wrong Field!\n";
                    goto up;
                }
                // Recalculate total and average marks
                $stu[$j]->total = $stu[$j]->ds + $stu[$j]->c + $stu[$j]->eng;
                $stu[$j]->avg = $stu[$j]->total / 3;
                echo "Do you want to update more?[Y/N]:";
                $chooseUp = readline();
                switch ($chooseUp) {
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
        if ($found == 0)
            echo "Don't Found!!";
        system("pause");
        goto start;
    case 5:
        // Sort students by average marks
        echo "--------------------------------------sort by average----------------------------------" . PHP_EOL;
        $len = $i; // Initialize len with the number of students
        for ($i = 0; $i < $len; $i++) {
            for ($j = 0; $j + 1 < $len - $i; $j++) {
                if ($stu[$j]->avg > $stu[$j + 1]->avg) {
                    $temp = $stu[$j];
                    $stu[$j] = $stu[$j + 1];
                    $stu[$j + 1] = $temp;
                } else if ($stu[$j]->avg == $stu[$j + 1]->avg && $stu[$j]->name > $stu[$j + 1]->name) {
                    $temp = $stu[$j];
                    $stu[$j] = $stu[$j + 1];
                    $stu[$j + 1] = $temp;
                }
            }
        }
        break;
    default:
        goto start;
}
?>
