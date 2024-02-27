#code by Kung Samrach
#Phone : 0889766644
# FaceBook : Samrach Kung

class Student:
    def __init__(self):
        self.name = ""
        self.id = ""
        self.sex = ""
        self.total = 0.0
        self.avg = 0.0
        self.ds = 0
        self.c = 0
        self.eng = 0

stu = []

while True:
    print("-------------------------------------------------------------------------------------------------------")
    print("\t 1.Add  \t 2.Delete \t 3.Display \t 4.Update \t  5.Sort  ")
    print("-------------------------------------------------------------------------------------------------------")
    choose = int(input(" ====>> Please Choose one 1 - 5 = "))

    if choose == 1:
        temp = Student()  # Create a new Student instance
        print("---------------------------------------------")
        print("-----------------------<<<<<<<<<  Add Student >>>>>>>>>>-----------------------")
        print("- Student", len(stu) + 1)
        while True:
            temp.id = input("\tPlease Input ID   = ")
            if not any(student.id == temp.id for student in stu):
                break
            print("You can't Input the same ID!\n Please Try to Enter Again..")
        temp.name = input("\tPlease Input Name = ")
        temp.sex = input("\tPlease Input Sex  = ")
        temp.ds = int(input("\tPlease Input DS   = "))
        temp.c = int(input("\tPlease Input C#   = "))
        temp.eng = int(input("\tPlease Input Eng  = "))
        temp.total = temp.ds + temp.c + temp.eng
        temp.avg = temp.total / 3
        stu.append(temp)
        print("Data Added Successfully")

    elif choose == 2:
        print("-------------------------------")
        print("\t[Delete Option]\n1.Delete By ID\n2.Delete By Name\nchoose:")
        want = int(input())
        if want == 1:
            delID = input("Which Student (ID) you want to delete?: ")
            found = False
            for student in stu:
                if student.id == delID:
                    print(f"ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\tResult")
                    print(f"{student.id}\t{student.name}\t{student.sex}\t{student.ds}\t{student.c}\t{student.eng}\t{student.total}\t{student.avg}\t{'Pass' if student.avg >= 50 else 'Fail'}")
                    sure = input("Are you sure to delete!![y/n]: ")
                    if sure.lower() == 'y':
                        stu.remove(student)
                        print("Data Deleted Successfully!")
                    found = True
                    break
            if not found:
                print("Data not found")
        elif want == 2:
            delName = input("Which Student (Name) you want to delete?: ")
            found = False
            for student in stu:
                if student.name == delName:
                    print(f"ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\tResult")
                    print(f"{student.id}\t{student.name}\t{student.sex}\t{student.ds}\t{student.c}\t{student.eng}\t{student.total}\t{student.avg}\t{'Pass' if student.avg >= 50 else 'Fail'}")
                    sure = input("Are you sure to delete!![y/n]: ")
                    if sure.lower() == 'y':
                        stu.remove(student)
                        print("Data Deleted Successfully!")
                    found = True
                    break
            if not found:
                print("Data not found")

    elif choose == 3:
        print("------------------------------------------------------------------------------------")
        print("------------------------   Display info student ----------------------------------")
        print("ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\tResult")
        for student in stu:
            print(f"{student.id}\t{student.name}\t{student.sex}\t{student.ds}\t{student.c}\t{student.eng}\t{student.total}\t{student.avg}\t{'Pass' if student.avg >= 50 else 'Fail'}")

    elif choose == 4:
        print("-------------------------------")
        print("\t[Update]")
        up = input("Which Student (ID) you want to Update?: ")
        for student in stu:
            if student.id == up:
                print(f"ID\tName\tSex\tDS\tC#\tEng\tTotal\tAverage\tResult")
                print(f"{student.id}\t{student.name}\t{student.sex}\t{student.ds}\t{student.c}\t{student.eng}\t{student.total}\t{student.avg}\t{'Pass' if student.avg >= 50 else 'Fail'}")
                field = input("Which Field = ")
                if field.lower() == "name":
                    student.name = input("Name: ")
                elif field.lower() == "id":
                    student.id = input("ID: ")
                elif field.lower() == "sex":
                    student.sex = input("Sex: ")
                elif field.lower() == "ds":
                    student.ds = int(input("DS: "))
                elif field.lower() == "eng":
                    student.eng = int(input("Eng: "))
                elif field.lower() == "c#":
                    student.c = int(input("C#: "))
                else:
                    print("Wrong Field!\n")
                    continue
                student.total = student.ds + student.c + student.eng
                student.avg = student.total / 3
                chooseUp = input("Do you want to update more?[Y/N]: ")
                if chooseUp.lower() == 'n':
                    break
        else:
            print("Don't Found!!")

    elif choose == 5:
        print("--------------------------------------sort by average----------------------------------")
        for i in range(len(stu)):
            for j in range(len(stu) - i - 1):
                if stu[j].avg > stu[j + 1].avg:
                    stu[j], stu[j + 1] = stu[j + 1], stu[j]
                elif stu[j].avg == stu[j + 1].avg and stu[j].name > stu[j + 1].name:
                    stu[j], stu[j + 1] = stu[j + 1], stu[j]

    else:
        break
