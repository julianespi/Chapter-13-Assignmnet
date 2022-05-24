#pragma once
class studentInfo
{
private:
    int id;
    string name;
    string major;
    double GPA;
public:
    studentInfo()
    {
        id = 0;
        name = "unknown";
        major = "unknown";
        GPA = 0;
    }

    studentInfo(int newId, string newName, string newMajor, double newGPA)
    {
        id = newId;
        name = newName;
        major = newMajor;
        GPA = newGPA;
    }

    //setter
    void setID(int newID)
    {
        id = newID;
    }

    void setName(string newName)
    {
        name = newName;
    }

    void setMajor(string newMajor)
    {
        major = newMajor;
    }

    void setGPA(double newGPA)
    {
        GPA = newGPA;
    }

    //getters
    int getID()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    string getMajor()
    {
        return major;
    }

    double getGPA()
    {
        return GPA;
    }

    bool operator <(const studentInfo& right)
    {
        if (id < right.id)
        {
            return true;
        }
        else
            return false;
    }

    bool operator >(const studentInfo& right)
    {
        if (id > right.id)
        {
            return true;
        }
        else
            return false;
    }

    friend ostream& operator <<(ostream& out, const studentInfo& obj);
};
//overloaded cout operator
ostream& operator <<(ostream& out, const studentInfo& obj)
{
    out << setw(6)<< obj.id << setw(40) << obj.name << setw(20) << obj.major
        << setw(15) << obj.GPA;
    return out;
}


//Precondition: takes in a student info
//Postcondition: swaps the students info
void swap(studentInfo* xp, studentInfo* yp)
{
    studentInfo temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//Precondition: takes in a vector of studentinfo and the size
//Postcondition: sorts the vector in acending order by ID
void selectionSortAscendingID(vector<studentInfo>& studentList, int n)
{
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++)
    {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (studentList[j].getID() < studentList[min_idx].getID())
                min_idx = j;

        // Swap the found minimum element
        // with the first element
        swap(&studentList[min_idx], &studentList[i]);
    }
}

//Precondition: takes in a vector of studentInfo
//Postcondition: sorts them in asccending order by there name
void selectionSortAscendingName(vector<studentInfo>& studentList, int n)
{
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++)
    {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (studentList[j].getName() < studentList[min_idx].getName())
                min_idx = j;

        // Swap the found minimum element
        // with the first element
        swap(&studentList[min_idx], &studentList[i]);
    }
}

//Precondition: takes in a vector of studentInfo and the size
//Postcondition: sorts the vector in asccending order by major
void selectionSortAscendingMajor(vector<studentInfo>& studentList, int n)
{
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++)
    {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (studentList[j].getMajor() < studentList[min_idx].getMajor())
                min_idx = j;

        // Swap the found minimum element
        // with the first element
        swap(&studentList[min_idx], &studentList[i]);
    }
}

//Precondition: takes in a vector of studentInfo and the size
//Postcondition: sorts the vector in ascending order by GPA
void selectionSortAscendingGPA(vector<studentInfo>& studentList, int n)
{
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++)
    {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (studentList[j].getGPA() < studentList[min_idx].getGPA())
                min_idx = j;

        // Swap the found minimum element
        // with the first element
        swap(&studentList[min_idx], &studentList[i]);
    }
}

//Precondition: takes in a vector of studentInfo
//Postcondition: reads a file and adds those elemnents to the vector
void readDataToFile(vector<studentInfo> &studentList)
{
    string fileName = inputString("Enter the name of the file: ", false);
    int newEmployeeIDIncrment = 0;
    string correctFile = "Students.dat";

    cout << "loading file..." << endl;

    ifstream file1;
    file1.open(fileName, ios::in);
    if (file1.fail())
    {
        cout << "ERROR: file cannot be read, try " << correctFile << endl;
        return;
    }

    studentInfo buffer;
    string temp;
    int tempInt = 0;
    while (!file1.eof())
    {
        getline(file1, temp, ','); // this gets student ID
        buffer.setID(stoi(temp));
        getline(file1, temp, ','); // This gets student name
        buffer.setName(temp);
        getline(file1, temp, ','); // this gets student Major
        buffer.setMajor(temp);
        getline(file1, temp, '\n'); //this gets GPA
        buffer.setGPA(stod(temp));


        studentList.push_back(buffer);
    }
    cout << "file loaded and data downloaded" << endl;
    file1.close();
}

//Precondition: takes in a vector of sudentInfo
//Postcondition: displays all the elements
void displayRecords(vector<studentInfo> studentList)
{
    if (studentList.size() == 0)
    {
        cout << "There is no data." << endl;
        return;
    }
    cout << setw(6) << "ID" << setw(40) << "Name" << setw(20) << "Major" << setw(15) << "GPA" << endl;
    for (int i = 0; i < studentList.size(); i++)
    {
        cout << studentList[i] << endl;
    }
}

//Precondition: takes in a vector of StudentInfo
//Postcondition: adds a element to the vector
void insertRecord(vector<studentInfo> &studentList)
{
    studentInfo buffer;
    int newID = inputInteger("Enter the student ID of the student you'd like to add:", 0, 1000);

    buffer.setID(newID);
    buffer.setName(inputString("Enter the full name of the new student: ", true));
    buffer.setMajor(inputString("Enter the major of the new student: ", true));
    buffer.setGPA(inputDouble("Enter the GPA of the new student: ", 0, 4.0));

    studentList.push_back(buffer);
}

//Precondition: takes in a vector of student info
//Postcondition: removes a user specfied element if found
void removeRecord(vector<studentInfo>& studentList)
{
    if (studentList.size() == 0)
    {
        cout << "There is no data." << endl;
        return;
    }
    string findElement = inputString("Enter a student's name to remove: ", true);

    for (int i = 0; i < studentList.size(); i++)
    {
        if (studentList[i].getName() == findElement)
        {
            cout << "The student record has been removed." << endl;
            studentList.erase(studentList.begin() + i);
            return;
        }
    }

    cout << "The student record cannot be found to be removed." << endl;
}

//Precondition: takes in a vector of student info
//Postcondition: sorts the vector in ascending order by ID
void ascendingIDsort(vector<studentInfo>& studentList)
{
    cout << "sorted in ascending order by ID. " << endl;
    selectionSortAscendingID(studentList, studentList.size());
}

//Precondition: takes in a vector of student info
//Postcondition: sorts the vectore in ascending order by name
void ascendingNameSort(vector<studentInfo>& studentList)
{
    cout << "sorted in ascending order by Name. " << endl;
    selectionSortAscendingName(studentList, studentList.size());
}

//Precondition: takes in a vector of student info
//Postcondition: sorts the vector in ascending order by Major
void ascendingMajorSort(vector<studentInfo>& studentList)
{
    cout << "sorted in ascending order by Major. " << endl;
    selectionSortAscendingMajor(studentList, studentList.size());
}

//Precondition: takes in a vector of student info
//Postcondition: sorts the vector in ascending order by GPA
void ascendingGPASort(vector<studentInfo>& studentList)
{
    cout << "sorted in ascending order by GPA. " << endl;
    selectionSortAscendingGPA(studentList, studentList.size());
}

//Precondition: none
//Postcondition: returns an int that determins what the vector will be sorted by
int ascendingsortsMenuOption()
{
    cout << "Choose by (1)-ID, (2)-name, (3)-major or (4)-GPA:";
    int options = inputInteger(" ", 1, 4);
    cout << endl << endl << endl;
    return options;
}

//Precondition: takes in a vector of student info
//Postcondition: chooses what functions to sort by
void ascendingsorts(vector<studentInfo>& studentList)
{
    do
    {
        switch (ascendingsortsMenuOption())
        {
        case 1: ascendingIDsort(studentList); return;
        case 2: ascendingNameSort(studentList); return;
        case 3: ascendingMajorSort(studentList); return;
        case 4: ascendingGPASort(studentList); return;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

}

//Precondition: takes in a vector of student info
//Postcondition: sorts the vector in descendgin order by ID
void descendingIDsort(vector<studentInfo>& studentList)
{
    cout << "sorted in descending order by ID. " << endl;
    selectionSortAscendingID(studentList, studentList.size());
    reverse(studentList.begin(), studentList.end());
}

//Precondition: takes in a vector of student info
//Postcondition: sorts the vector in descending order by Name
void descendingNameSort(vector<studentInfo>& studentList)
{
    cout << "sorted in descending order by Name. " << endl;
    selectionSortAscendingName(studentList, studentList.size());
    reverse(studentList.begin(), studentList.end());
}

//Precondition: takes in a vector of student info
//Postcondition: sorts the vector in descending order by Major
void descendingMajorSort(vector<studentInfo>& studentList)
{
    cout << "sorted in descending order by Major. " << endl;
    selectionSortAscendingMajor(studentList, studentList.size());
    reverse(studentList.begin(), studentList.end());
}

//Precondition: takes in a vector of student info
//Postcondition: sorts the vector in descending order by GPA
void descendingGPASort(vector<studentInfo>& studentList)
{
    cout << "sorted in descending order by GPA. " << endl;
    selectionSortAscendingGPA(studentList, studentList.size());
    reverse(studentList.begin(), studentList.end());
}

//Precondition:none 
//Postcondition: returns an int the descides what method to sort by
int descendingsortsMenuOption()
{
    cout << "Choose by (1)-ID, (2)-name, (3)-major or (4)-GPA:";
    int options = inputInteger(" ", 1, 4);
    cout << endl << endl << endl;
    return options;
};

//Precondition: takes in a vector of student info
//Postcondition: chooses what function to execute 
void descendingSorts(vector<studentInfo>& studentList)
{
    do
    {
        switch (descendingsortsMenuOption())
        {
        case 1: descendingIDsort(studentList); return;
        case 2: descendingNameSort(studentList); return;
        case 3: descendingMajorSort(studentList); return;
        case 4: descendingGPASort(studentList); return;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);
}

//Precondition:none
//Postcondition: chooses what order to sort by
int sortMenuOption()
{
    cout << "Choose sort in (1)-ascending or (2)-descending order:";
    int options = inputInteger(" ", 1, 2);
    cout << endl << endl << endl;
    return options;
}

//Precondition: takes in a vector of student info
//Postcondition: chooses the roder byu which to sort by
void sortStudents(vector<studentInfo>& studentList)
{
    if (studentList.size() == 0)
    {
        cout << "There is no data." << endl;
        return;
    }

    do
    {
        switch (sortMenuOption())
        {
        case 1: ascendingsorts(studentList); return;
        case 2: descendingSorts(studentList); return;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);


    sort(studentList.begin(), studentList.end());
    cout << "Students have been sorted by ID. " << endl;
}

//Precondition: takes in a vector of student info
//Postcondition: wirtes the data to a file 
void writedataFile(vector<studentInfo>& studentList)
{
    if (studentList.size() == 0)
    {
        cout << "There is no data." << endl;
        return;
    }

    ofstream file;
    studentInfo buffer;
    string fileName = inputString("Enter the name of the file you want to write to(include .txt at the end): ", false);
    file.open(fileName);
    cout << "Writing to file..." << endl;
    for (int i = 0; i < studentList.size(); i++)
    {
        buffer = studentList[i];
        file << buffer.getID() << "," << buffer.getName() << "," << buffer.getMajor() << "," << buffer.getGPA() << endl;
    }
    cout << "file complete" << endl;
    file.close();
}

//Precondition: none
//Postcondition: displays the application menu
int appOfStudentRecMenuOption()
{
    cout << endl << "Application of sorting student records";
    cout << endl << "==========================================";
    cout << endl << "1> Read in data file";
    cout << endl << "2> Display records";
    cout << endl << "3> Insert a record";
    cout << endl << "4> remove a record";
    cout << endl << "5> Sort records by ID, name, major or GPA";
    cout << endl << "6> Write out data file";
    cout << endl << "==========================================";
    cout << endl << "Exit 0";
    cout << endl << "==========================================" << endl;
    int options = inputInteger("Options: ", 0, 6);
    cout << endl << endl << endl;
    return options;
}

//Precondition: none 
//Postcondition: choose a functions to tha manipultes the vector
void appOfStudentRec()
{
    vector<studentInfo> studentList;
    do
    {
        switch (appOfStudentRecMenuOption())
        {
        case 0: return; break;
        case 1: readDataToFile(studentList); break;
        case 2: displayRecords(studentList); break;
        case 3: insertRecord(studentList); break;
        case 4: removeRecord(studentList); break;
        case 5: sortStudents(studentList); break;
        case 6: writedataFile(studentList); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);
}
