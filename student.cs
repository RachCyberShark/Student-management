//code by Kung Samrach
//Phone : 0889766644
// FaceBook : Samrach Kung

using System;

// Define a struct named Student to represent student information
struct Student
{
    public string name, id;
    public char sex;
    public float total, avg;
    public int ds, c, eng;
}

class Program
{
    static void Main(string[] args)
    {
        // Declare an array of Student structs to store student data
        Student[] stu = new Student[100];
        Student temp;
        int i = 0, len;

        char sure, chooseUp;
        int choose, result, found, want, count;
        string del, up;
        string delName, IDjonknea;
        string[] same = new string[100];
        string field;

    start:
        Console.Clear(); // Clear the console screen
        // Display menu options
        Console.WriteLine("-------------------------------------------------------------------------------------------------------");
        Console.WriteLine("\t 1.Add  \t 2.Delete \t 3.Display \t 4.Update \t  5.sort  ");
        Console.WriteLine("-------------------------------------------------------------------------------------------------------");
        Console.Write(" ====>> Please Choose one 1 - 5 = ");
        choose = int.Parse(Console.ReadLine());

        switch (choose)
        {
            case 1:
                // Add a new student
                Console.WriteLine("---------------------------------------------");
                Console.WriteLine("-----------------------<<<<<<<<<  Add Student >>>>>>>>>>-----------------------");
                Console.WriteLine("- Student " + (i + 1));
            ID:
                Console.Write("\tPlease Input ID   = ");
                stu[i].id = Console.ReadLine();
                IDjonknea = stu[i].id;
                // Check for duplicate IDs
                for (int j = 0; j < i; j++)
                {
                    if (IDjonknea == stu[j].id)
                    {
                        Console.WriteLine("You can't Input the same ID!\n Please Try to Enter Again..");
                        goto ID;
                    }
                }
                // Input student information
                Console.Write("\tPlease Input Name = ");
                stu[i].name = Console.ReadLine();
                Console.Write("\tPlease Input Sex  = ");
                stu[i].sex = char.Parse(Console.ReadLine());
                Console.Write("\tPlease Input DS   = ");
                stu[i].ds = int.Parse(Console.ReadLine());
                Console.Write("\tPlease Input C#   = ");
                stu[i].c = int.Parse(Console.ReadLine());
                Console.Write("\tPlease Input Eng  = ");
                stu[i].eng = int.Parse(Console.ReadLine());
                Console.WriteLine("Data Added Successfully");
                // Calculate total and average marks
                stu[i].total = stu[i].ds + stu[i].c + stu[i].eng;
                stu[i].avg = stu[i].total / 3;
                i++; // Increment the number of students
                Console.ReadLine(); // Pause the system to display message before continuing
                goto start; // Go back to the start of the loop
            case 2:
                // Delete a student
                Console.WriteLine("-------------------------------");
                Console.WriteLine("\t[Delete Option]\n1.Delete By ID\n2.Delete By Name\nchoose:");
                want = int.Parse(Console.ReadLine());
                switch (want)
                {
                    case 1:
                        // Delete by ID
                        Console.Write("Which Student (ID) you want to delete?:");
                        del = Console.ReadLine();
                        found = 0;
                        // Find the student with the given ID
                        for (int j = 0; j < i; j++)
                        {
                            if (del == stu[j].id)
                            {
                                // Display student information
                                Console.WriteLine("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult");
                                Console.Write(stu[j].id + "\t" + stu[j].name + "\t" + stu[j].sex + "\t");
                                Console.Write(stu[j].ds + "\t" + stu[j].c + "\t" + stu[j].eng + "\t" + stu[j].total + "\t" + stu[j].avg + "\t");
                                if (stu[j].avg >= 50)
                                    Console.WriteLine("\tPass");
                                else
                                    Console.WriteLine("\tFail");
                                found = 1; // Set found flag
                                Console.Write("Are you sure to delete!![y/n]:");
                                sure = char.Parse(Console.ReadLine());
                                switch (sure)
                                {
                                    case 'y':
                                    case 'Y':
                                        // Shift remaining students in the array
                                        for (int k = j; k < i - 1; k++)
                                        {
                                            stu[k] = stu[k + 1];
                                        }
                                        i--; // Decrement the number of students
                                        Console.WriteLine("Data Deleted Successfully!");
                                        break;
                                    case 'N':
                                    case 'n':
                                        Console.ReadLine();
                                        goto start;
                                }
                            }
                        }
                        break;
                    case 2:
                        // Delete by name
                        Console.Write("Which Student (Name) you want to delete?:");
                        delName = Console.ReadLine();
                        found = 0;
                        count = 0;
                        int s = 0;
                        // Display student information
                        Console.WriteLine("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult");
                        for (int j = 0; j < i; j++)
                        {
                            if (delName == stu[j].name)
                            {
                                Console.Write(stu[j].id + "\t" + stu[j].name + "\t" + stu[j].sex + "\t");
                                Console.Write(stu[j].ds + "\t" + stu[j].c + "\t" + stu[j].eng + "\t" + stu[j].total + "\t" + stu[j].avg + "\t");
                                if (stu[j].avg >= 50)
                                    Console.WriteLine("\tPass");
                                else
                                    Console.WriteLine("\tFail");
                                found = 1; // Set found flag
                                count++;
                                same[s++] = stu[j].id;
                            }
                        }
                        // If multiple students have the same name, prompt for ID
                        if (count > 1)
                        {
                            found = 0;
                            Console.Write("Which Student (ID) you want to delete?:");
                            del = Console.ReadLine();
                            for (int j = 0; j <= s; j++)
                            {
                                if (del == same[j])
                                {
                                    found = 1;
                                    for (int k = 0; k < i; k++)
                                    {
                                        if (stu[k].id == del)
                                        {
                                            Console.Write("Are you sure to delete!![y/n]:");
                                            sure = char.Parse(Console.ReadLine());
                                            if (sure == 'Y' || sure == 'y')
                                            {
                                                // Shift remaining students in the array
                                                for (int l = k; l < i - 1; l++)
                                                    stu[l] = stu[l + 1];
                                                i--; // Decrement the number of students
                                                Console.WriteLine("Data Deleted Successfully!");
                                            }
                                            else if (sure == 'n' || sure == 'N')
                                            {
                                                Console.ReadLine();
                                                goto start;
                                            }
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        // If only one student found, directly delete
                        else if (count == 1)
                        {
                            for (int j = 0; j < i; j++)
                            {
                                if (delName == stu[j].name)
                                {
                                    Console.Write("Are you sure to delete!![y/n]:");
                                    sure = char.Parse(Console.ReadLine());
                                    switch (sure)
                                    {
                                        case 'y':
                                        case 'Y':
                                            // Shift remaining students in the array
                                            for (int k = j; k < i - 1; k++)
                                            {
                                                stu[k] = stu[k + 1];
                                            }
                                            i--; // Decrement the number of students
                                            Console.WriteLine("Data Deleted Successfully!");
                                            break;
                                        case 'N':
                                        case 'n':
                                            Console.ReadLine();
                                            goto start;
                                    }
                                }
                            }
                        }
                        break;
                }
                if (found == 0)
                    Console.WriteLine("Data not found");
                Console.ForegroundColor = ConsoleColor.Blue;
                Console.ReadLine();
                goto start;
            case 3:
                // Display student information
                Console.WriteLine("------------------------------------------------------------------------------------");
                Console.WriteLine("------------------------   Display info student ----------------------------------");
                Console.WriteLine("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult");
                for (int j = 0; j < i; j++)
                {
                    Console.Write(stu[j].id + "\t" + stu[j].name + "\t" + stu[j].sex + "\t");
                    Console.Write(stu[j].ds + "\t" + stu[j].c + "\t" + stu[j].eng + "\t" + stu[j].total + "\t" + stu[j].avg + "\t");
                    if (stu[j].avg >= 50)
                        Console.WriteLine("\tPass");
                    else
                        Console.WriteLine("\tFail");
                }
                Console.ReadLine();
                goto start;
            case 4:
                // Update student information
                found = 0;
                Console.WriteLine("-------------------------------");
                Console.WriteLine("\t[Update]");
                Console.Write("Which Student (ID) you want to Update?: ");
                up = Console.ReadLine();
                for (int j = 0; j < i; j++)
                {
                    if (up == stu[j].id)
                    {
                        // Display student information
                        Console.WriteLine("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\t\tResult");
                        Console.Write(stu[j].id + "\t" + stu[j].name + "\t" + stu[j].sex + "\t");
                        Console.Write(stu[j].ds + "\t" + stu[j].c + "\t" + stu[j].eng + "\t" + stu[j].total + "\t" + stu[j].avg + "\t");
                        if (stu[j].avg >= 50)
                            Console.WriteLine("\tPass");
                        else
                            Console.WriteLine("\tFail");
                        found = 1; // Set found flag
                    up:
                        Console.Write("Which Field=");
                        field = Console.ReadLine();
                        // Update the selected field
                        if (field == "name" || field == "Name")
                        {
                            Console.Write("Name:");
                            stu[j].name = Console.ReadLine();
                        }
                        else if (field == "ID" || field == "id")
                        {
                            Console.Write("ID:");
                            stu[j].id = Console.ReadLine();
                        }
                        else if (field == "sex" || field == "Sex")
                        {
                            Console.Write("Sex:");
                            stu[j].sex = char.Parse(Console.ReadLine());
                        }
                        else if (field == "ds" || field == "DS")
                        {
                            Console.Write("DS:");
                            stu[j].ds = int.Parse(Console.ReadLine());
                        }
                        else if (field == "Eng" || field == "eng")
                        {
                            Console.Write("Eng:");
                            stu[j].eng = int.Parse(Console.ReadLine());
                        }
                        else if (field == "C#" || field == "c#")
                        {
                            Console.Write("C#:");
                            stu[j].c = int.Parse(Console.ReadLine());
                        }
                        else
                        {
                            Console.WriteLine("Wrong Field!\n");
                            goto up;
                        }
                        // Recalculate total and average marks
                        stu[j].total = stu[j].ds + stu[j].c + stu[j].eng;
                        stu[j].avg = stu[j].total / 3;
                        Console.Write("Do you want to update more?[Y/N]:");
                        chooseUp = char.Parse(Console.ReadLine());
                        switch (chooseUp)
                        {
                            case 'y':
                            case 'Y':
                                goto up;
                            case 'n':
                            case 'N':
                                Console.ForegroundColor = ConsoleColor.Green;
                                Console.ReadLine();
                                goto start;
                        }
                    }
                }
                if (found == 0)
                    Console.WriteLine("Don't Found!!");
                Console.ReadLine();
                goto start;
            case 5:
                // Sort students by average marks
                Console.WriteLine("--------------------------------------sort by average----------------------------------");
                len = i; // Initialize len with the number of students
                for (int x = 0; x < len; x++)
                {
                    for (int j = 0; j + 1 < len - x; j++)
                    {
                        if (stu[j].avg > stu[j + 1].avg)
                        {
                            temp = stu[j];
                            stu[j] = stu[j + 1];
                            stu[j + 1] = temp;
                        }
                        else if (stu[j].avg == stu[j + 1].avg && stu[j].name.CompareTo(stu[j + 1].name) > 0)
                        {
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
    }
}
