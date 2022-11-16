//ADMIN FUNCTIONS: HEADER DATA

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>


using std::cout;
using std::cin;
using std::fstream;
using std::ios;
using std::string;
using std::vector;
using std::stringstream;


//declaring struct for student data-note that this needs to be initialized in each function that uses it(or globally)
struct studentData {
    int id;
    string lastName;
    string firstName;
    int year;
    string fatherName;
    string motherName;
    string teacherName;
    int math;
    int eng;
    int sci;
    int geo;
    int hist;
    int total;
};
//_________________________________________________________________________________________________________________________________
//Print Student Data
//this function displays the content of a studentData-type struct.
void printStudent(studentData row) {
    cout << row.lastName << "," << row.firstName << "," << row.year << "," << row.fatherName << "," << row.motherName << "," << row.teacherName << "," << row.math << "," << row.eng << "," << row.sci << "," << row.geo << "," << row.hist << "," << "row.total";

}
//_________________________________________________________________________________________________________________________________
//Lookup Student
//This function displays a list of names and then allows a user to select a student and display their information.(is this required? Needs to be included in admin menu if so, could be redundant


void lookUpStudent(string& filename) {

    string line;
    //First create an instance of the file
    fstream file(filename, ios::out | ios::app);

    //declare a studentData-type struct called row
    studentData row;

    //Check if file is open
    if (!file.is_open()) {
        cout << "warning no file is open to write to; please open a file first\n";
        return;
    }

    //if prior checks are cleared, create a vector of structs

    vector < studentData> fileContent;

    string showFirstName;//string to take user input, show an entry
    string showLastName;

    //populate structs
    while (std::getline(file, line, '\n')) {

        stringstream stream(line);


        file <<  row.id<< ","<< row.lastName<< ","<< row.firstName<< ','<< row.year<< ','<< row.motherName<< ','<< row.fatherName<< ','<< row.math<< ','<< row.eng<< ','<< row.sci<< ','<< row.geo<< ','<< row.hist<<','<< row.total;
        //problem here seems to be that getline dosen't like to take in struct members as parameters. 


        fileContent.push_back(row);
        //new line should go here

        cout << "\n\n Please enter the LAST and FIRST names of the student you want to veiw:\n";
        for (studentData row : fileContent) {
            cout << row.lastName << "_" << row.firstName << "\t";
            //this outputs everything in position 1 and 2 of the vector-of-structs.

        }//Here we are asking for the name you want to display, THEN printing out the names in the database to show options.

        cout << "Enter Last Name: ";
        cin >> showLastName;//takes user input for the name to delete
        cout << "\n";
        cout << "Enter First Name: ";
        cin >> showFirstName;//takes user input for the name to delete
        cout << "\n";
        //now loop through and display student where lastname/firstname match user entry

        for (studentData row : fileContent) {
            if (row.lastName == showLastName && row.firstName == showFirstName) {
                printStudent(row);
            
            else continue;
            }

        }
    }
}

//________________________________________________________________________________________________________________________________
//Write to a file/Create Student Entry
void fileWrite(string& fileName) {


    studentData database;


    //create an instance of the file 
    fstream file(fileName, ios::out | ios::app);
    if (!file.is_open()) {
        cout << "warning no file is open to write to; please open a file first\n";
        return;
    }


    //taking user inputs

    cout << "enter student details:";
    cout << "\nLast name of student: ";
    cin >> database.id;
    cout << "\nLast name of student: ";
    cin >> database.lastName;
    cout << "\nFirst name of student: ";
    cin >> database.firstName;
    cout << "\nyear level of student: ";
    cin >> database.year;
    cout << "\nstudent's father's name (enter . if not applicable): ";
    cin >> database.fatherName;
    cout << "\nstudent's mother's name (enter .if not applicable):  ";
    cin >> database.motherName;
    cout << "\nstudent's teacher's name: ";
    cin >> database.teacherName;
    cout << "\nstudent's math grade:  ";
    cin >> database.math;
    cout << "\nstudent's english grade: ";
    cin >> database.eng;
    cout << "\nstudent's science grade:  ";
    cin >> database.sci;
    cout << "\nstudent's geography grade: ";
    cin >> database.geo;
    cout << "\nstudent's history grade:  ";
    cin >> database.hist;
    cout << "\nstudent's cumulative grade:  ";
    cin >> database.total;

    cout << "\n\n";

    //send the information to the file
    file << database.lastName << "," << database.firstName << "," << database.year << "," << database.fatherName << "," << database.motherName << "," << database.teacherName << "," << database.math << "," << database.eng << "," << database.sci << "," << database.geo << "," << database.hist << "," << database.total << "\n";
    file.close();

    if (!file.is_open()) {
        cout << "file has been succesfully closed\n\n";

    }
}
//________________________________________________________________________________________________________________________________
//Read File


vector<studentData> fileRead(string& fileName) {


    studentData row;
    vector < studentData> fileContent;//the outer vector is named fileContent and contains studentData structs named Row.

    //create an instance of the file stream
    fstream file(fileName, ios::in | ios::beg);
    //make our check to see if the file is open
    if (!file.is_open()) {
        cout << "warning no file is open\n\n";
        return fileContent;
    }
    //iterate through csv file to populate vectors
    while (std::getline(file, line, '\n')) {

        stringstream stream(line);


        getline(stream, row.id, ",", row.lastName, ",", row.firstName, ',', row.year, ',', row.motherName, ',', row.fatherName, ',', row.math, ',', row.eng, ',', row.sci, ',', row.geo, ',', row.hist, ',', row.total);
        /*getline(stream, row.lastName, ',');
        getline(stream, row.firstName, ',');
        getline(stream, row.year, ',');
        getline(stream, row.motherName, ',');
        getline(stream, row.fatherName, ',');
        getline(stream, row.teacherName, ',');
        getline(stream, row.math, ',');
        getline(stream, row.eng, ',');
        getline(stream, row.sci, ',');
        getline(stream, row.geo, ',');
        getline(stream, row.hist, ',');
        getline(stream, row.total, ',');*/


        fileContent.push_back(row);

    }
    //need to loop through the created vector so we can output the data

    for (studentData row : fileContent) {

        printStudent(row); //outputs the content of structs

        cout << "\n";//new line
    }
    //close out file
    file.close();
    //check to make sure file has closed
    if (!file.is_open()) {
        cout << "File Successfully Closed\n\n";
    }
    //return file content
    return fileContent;

}
//________________________________________________________________________________________________________________________________
//Delete from file/delete student entry
void rowClear(string& fileName) {
    //create a new file
    string tempFileName = "temp" + fileName;
    //create pointers to give a reference to the file
    char* fileNamePtr = &fileName[0];
    char* tempFileNamePtr = &tempFileName[0];

    //create an instance of the file stream
    fstream fileIn(fileName, ios::in);
    if (!fileIn.is_open()) {//check to ensure file is open
        cout << "Warning: no file is open\n\n";
        return;//ends function if file is not open
    }
    fstream fileOut(tempFileName, ios::out); //initializing content assigned from a read file
    vector<studentData>fileContent = fileRead(fileName);

    //check to see if file has content
    if (fileContent.size() == 0) {
        cout << "warning file contains no data\n\n";
        fileIn.close();//close input file
        fileOut.close();//close output file
        remove(tempFileNamePtr);//removing the output file
        return;//ends execution of function
    }

    //if prior checks are cleared, create a vector

    vector<studentData>replacementContent;
    string delFirstName;//string to take user input, remove an entry
    string delLastName;

    cout << "\n\n Please enter the name of the student you wish to delete\n";
    for (studentData row : fileContent) {
        cout << row.lastName << "_" << row.firstName << "\t";
        //this outputs everything in position 1 and 2 of the vector-of-vectors

    }//Here we are asking for the name you want to delete, THEN printing out the names in the database to show options.

    cout << "Enter Last Name: ";
    cin >> delLastName;//takes user input for the name to delete
    cout << "\n";
    cout << "Enter First Name: ";
    cin >> delFirstName;//takes user input for the name to delete
    cout << "\n";

    //loop through content we will push to our new vector(remove cout from final product)
    for (studentData row : fileContent) {
        if (row.lastName == delLastName && row.firstName == delFirstName) {
            cout << "continuing through, skipping content where first and last names match entered target\n\n";//if name at position 1 and 2 is equal to dellastname and delFirstName, skip it and continue looping
            continue;
        }
        else {
            replacementContent.push_back(row);//push back replacement content vector

        }
    }

    //loop through replacement content displaying new data (get rid of in final product)
    cout << "Data within new file:\n";
    for (studentData row : replacementContent) {
        printStudent(row);
        cout << "\n";
    }
    //output everything into new temp file
    for (studentData row : replacementContent) {
        fileOut << row.lastName << "," << row.firstName << "," << row.year << "," << row.fatherName << "," << row.motherName << "," << row.teacherName << "," << row.math << "," << row.eng << "," << row.sci << "," << row.geo << "," << row.hist << "," << "row.total";
    }

    //close files
    fileIn.close();
    fileOut.close();
    remove(fileNamePtr); //deleting original file
    rename(tempFileNamePtr, fileNamePtr);



}

//________________________________________________________________________________________________________________________________
//Edit Student Entry
void editStudent(string fileName) {
    //create a new file
    string tempFileName = "temp" + fileName;
    //create pointers to give a reference to the file
    char* fileNamePtr = &fileName[0];
    char* tempFileNamePtr = &tempFileName[0];

    //create an instance of the file stream
    fstream fileIn(fileName, ios::in);
    if (!fileIn.is_open()) {//check to ensure file is open
        cout << "Warning: no file is open\n\n";
        return;//ends function if file is not open
    }
    fstream fileOut(tempFileName, ios::out); //initializing content assigned from a read file
    vector<studentData>fileContent = fileRead(fileName);

    //check to see if file has content
    if (fileContent.size() == 0) {
        cout << "warning file contains no data\n\n";
        fileIn.close();//close input file
        fileOut.close();//close output file
        remove(tempFileNamePtr);//removing the output file
        return;//ends execution of function
    }

    //if prior checks are cleared, create a vector

    vector<studentData>replacementContent;
    string delFirstName;//string to take user input, remove an entry
    string delLastName;

    cout << "\n\n Please enter the name of the student you wish to delete\n";
    for (studentData row : fileContent) {
        cout << row.lastName << "_" << row.firstName << "\t";
        //this outputs everything in position 1 and 2 of the vector-of-vectors

    }//Here we are asking for the name you want to delete, THEN printing out the names in the database to show options.

    cout << "Enter Last Name: ";
    cin >> delLastName;//takes user input for the name to delete
    cout << "\n";
    cout << "Enter First Name: ";
    cin >> delFirstName;//takes user input for the name to delete
    cout << "\n";

    //loop through content we will push to our new vector(remove cout from final product)
    for (studentData row : fileContent) {
        if (row.lastName == delLastName && row.firstName == delFirstName) {
            //PLACE EDIT STRUCT FUNCTIONS HERE: COUT STRUCT CONTENTS,CIN NEW DATA AND ADD TO FILECONTENT

            continue;
        }
        else {
            replacementContent.push_back(row);//push back replacement content vector

        }
    }

    //loop through replacement content displaying new data (get rid of in final product)
    cout << "Data within new file:\n";
    for (studentData row : replacementContent) {
        printStudent(row);
        cout << "\n";
    }
    //output everything into new temp file
    for (studentData row : replacementContent) {
        fileOut << row.lastName << "," << row.firstName << "," << row.year << "," << row.fatherName << "," << row.motherName << "," << row.teacherName << "," << row.math << "," << row.eng << "," << row.sci << "," << row.geo << "," << row.hist << "," << "row.total";
    }

    //close files
    fileIn.close();
    fileOut.close();
    remove(fileNamePtr); //deleting original file
    rename(tempFileNamePtr, fileNamePtr);



}





//________________________________________________________________________________________________________________________________
//Admin Menu function
void adminMenu(bool b_fileOpen)

{


    string fileName = "testfile.csv";
    //THIS NEEDS TO BE FED IN FROM MAIN

    int userChoice;

    do {
        cout << "what function would you like to preform?\n";
        cout << "1)Add Student  2)Show Student  3)Delete Student  4)Edit Student  5)Exit\n";
        cout << "enter choice: ";
        cin >> userChoice;
        cout << '\n';

        switch (userChoice)
        {


        case 1:
            //write to a file/Add Student
            if (!b_fileOpen) {
                cout << "Warning: please open a file first\n\n";
            }
            else {
                fileWrite(fileName);
            }

            break;

        case 2:
            //read from a file/Show Student Data
            if (!b_fileOpen) {
                cout << "Warning: please open a file first\n\n";
            }
            else {
                fileRead(fileName);
            }

            break;

        case 3:
            //delete from a file/Delete Student

            if (!b_fileOpen) {
                cout << "Warning: please open a file first\n\n";
            }
            else {
                rowClear(fileName);
            }

            break;

        case 4:
            //Edit Student
            if (!b_fileOpen) {
                cout << "Warning: please open a file first\n\n";
            }
            else {
                //editStudent(fileName);
            }

        case 5:
            //exit
            cout << "thank you for using this app\n\n";
            break;


        }

    } while (userChoice != 5);


}







//________________________________________________________________________________________________________________________________
// Main (for testing)

int main()
{

    fstream testFile;
    testFile.open("testfile.csv", ios::out | ios::in | ios::app);//Open test File
    bool fileOpen = true;//declare file open as true, feed to admin menu

    adminMenu(fileOpen);



    return 0;
}