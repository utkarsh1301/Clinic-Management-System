#include <bits/stdc++.h>
#include <string.h>
#include <conio.h>
using namespace std;

class pat
{
private:
    string patientName;
    string add_pat;
    string pat_number;
    string pat_id;
    int pat_age;
    string pat_genders;
    string pat_BloodGroup;
    string deases;
    string symptoms;
    string pat_diagnose;
    string medicine;
    bool pat_admission;

public:
    int start();
    int user_FuncPanel();
    int Admin_FuncPanel();
    int Add_Patient();
    int Add_Prescription();
    int pat_rec();
    string up_pat_rec(string id);
    int Del_patRec();
    int update_patRec();
    void save_Patient();
    int rowCount(string id);
};
int tagline()
{
    cout << "Enter the number you want to choose" << endl;
    return 0;
}
int pat::Admin_FuncPanel()
{
    system("cls");
    cout << "Enter Admin ID" << endl;
    fflush(stdin);
    string admin_id;
    getline(cin, admin_id);
    cout << "Enter Admin Password" << endl;
    string admin_pass;
    getline(cin, admin_pass);
    if (admin_pass != "admin" || admin_id != "admin")
    {
        cout << "Wrong Admin ID or Password" << endl;
        cout << "Press any key to continue" << endl;
        getch();
        start();
    }
    system("cls");
    tagline();
    char opt;
    cout << "[1] Add Patient\n";
    cout << "[2] search Patient Records\n";
    cout << "[3] Update Patient Records\n";
    cout << "[4] Delete Patient Records\n";
    cout << "[5] Exit\n";
    opt = getch();
    system("cls");
    switch (opt)
    {
    case '1':
        Add_Patient();
        break;
    case '2':
        pat_rec();
        break;
    case '3':
        update_patRec();
        break;
    case '4':
        Del_patRec();
        break;
    case '5':
        return 0;
    default:
        cout << "Invalid Input" << endl;
        break;
    }
}

// User Function panel

int pat::user_FuncPanel()
{
    system("cls");
    tagline();
    char opt;
    cout << "[1] Add Patient\n";
    cout << "[2] Search Patient records\n";
    cout << "[3] Exit\n";
    opt = getch();
    system("cls");
    switch (opt)
    {
    case '1':
        Add_Patient();
        break;
    case '2':
        pat_rec();
        break;
    case '3':
        return 0;
    default:
        cout << "Invalid Input" << endl;
        start();
        break;
    }
}
// ADD PATIENT
int pat::Add_Patient()
{
    // add function code here
    cout << "PATIENT ID : ";
    cin >> pat_id;
    cout << "NAME : ";
    fflush(stdin);
    getline(cin, patientName);
    cout << "Patient contact number : ";
    cin >> pat_number;
    cout << "PATIENT AGE : ";
    cin >> pat_age;
    cout << "PATIENT GENDER (M/F/other) : ";
    fflush(stdin);
    getline(cin, pat_genders);
    cout << "PATIENT BLOOD GROUP : ";
    getline(cin, pat_BloodGroup);
    cout << "PATIENT SYMTOMS : ";
    getline(cin, symptoms);
    cout << "PATIENT DIAGNOSE : ";
    getline(cin, pat_diagnose);
    cout << "PATIENT DIASES : ";
    getline(cin, deases);
    cout << "PATIENT MEDICINE : ";
    getline(cin, medicine);
    cout << "PATIENT ADMISSION : ";
    cout << "\n[1] Yes\n[2] No\n";
    char opt;
    fflush(stdin);
    opt = getch();
    if (opt == '1')
    {
        pat_admission = true;
    }
    else
    {
        pat_admission = false;
    }
    fflush(stdin);
    save_Patient();
    start();
}
// for output in excel
void pat::save_Patient()
{
    ofstream outData;
    outData.open("bin/Data.csv", ios::app);
    outData << endl;
    outData << pat_id << ",";
    outData << patientName << ",";
    outData << pat_number << ",";
    outData << pat_age << ",";
    outData << pat_genders << ",";
    outData << pat_BloodGroup << ",";
    outData << symptoms << ",";
    outData << pat_diagnose << ",";
    outData << deases << ",";
    outData << medicine << ",";
    outData << pat_admission << ",";
    outData << endl;

    cout << "Data Registered successfully " << endl;
    cout << "Press any key to continue" << endl;
    getch();
}
// ADD PRESCRIPTION
int pat::Add_Prescription()
{
    string ID;
    cout << "ENTER PATIENT ID : ";
    cin >> ID;
    if (ID == pat_id)

    {
        cout << "NAME : " << patientName << endl;

        cout << " --------------------------------------" << endl;
        cout << "| FOR DIAGNOSIS FILL THE BELOW DETAILS |" << endl;
        cout << " --------------------------------------" << endl;

        cout << "ENTER SYMPTOMS : ";
        getline(cin >> ws, symptoms);
        cout << "ENTER DIAGNOSIS : ";
        getline(cin, pat_diagnose);
        cout << "DISEASE FOUND AFTER DIAGNOSIS : ";
        getline(cin, deases);
        cout << "MEDICINES : ";
        getline(cin, medicine);
        cout << "ADMIT REQUIRED TO HOSPITAL : ";
        cout << "[1] Yes\n[2] No\n";
    }

    else
    {
        cout << "INVALID ID" << endl;
        cout << "Press any key to continue" << endl;
        getch();
    }
}
int pat::update_patRec()
{
    fstream fin, fout;
    fin.open("bin/Data.csv", ios::in);
    fout.open("bin/Datanew.csv", ios::out);

    string id, marks;
    int count = 0, i;
    char sub;
    int index;
    string new_marks;
    string line, word;
    vector<string> row;

    cout << "Enter the Contact Number of the Patient to be updated : ";
    getline(cin, id);
    up_pat_rec(id);
    cout << "Enter [Number] of field to be updated : ";
    cin >> index;
    --index;
    cout << "Enter new Data : ";
    fflush(stdin);
    getline(cin, new_marks);
    while (!fin.eof())
    {
        row.clear();
        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        int row_size = row.size();
        if (row[2] == id)
        {
            count = 1;
            stringstream convert;
            convert << new_marks;
            row[index] = convert.str();
            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else
        {
            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        if (fin.eof())
            break;
    }
    if (count == 0)
        cout << "Record not found\n";
    fin.close();
    fout.close();
    remove("bin/Data.csv");
    rename("bin/Datanew.csv", "bin/Data.csv");
    cout << "Record Updated successfully" << endl;
    cout << "Press any key to continue" << endl;
    getch();
    system("cls");
    Admin_FuncPanel();
}
int pat::rowCount(string id)
{
    ifstream file("bin/Data.csv");
    string line;
    int i = 0;
    while (getline(file, line))
    {
        i++;
        if (line.find(id) != string::npos)
        {
            cout << "The row number of the id is: " << i << endl;
            return i;
        }
    }
    cout << "The id is not found in the file" << endl;
    return 0;
}
int pat::pat_rec()
{
    system("cls");
    ifstream myFile;
    myFile.open("bin/Data.csv");
    string line;
    cout << "Enter Contact Number of patient : ";
    string id;
    getline(cin, id);
    int n = rowCount(id); // desired row number
    int a = 0;            // counter
    string x[15];
    while (getline(myFile, line))
    {
        a++;
        if (a == n)
        {
            stringstream ss(line);
            string token;
            int i = 0;
            while (getline(ss, token, ','))
            {
                x[i] = token;
                i++;
            }
            break;
        }
    }
    cout << " ====================================" << endl;
    cout << "|| [1]ID                             : " << x[0] << endl;
    cout << "|| [2]NAME                           : " << x[1] << endl;
    cout << "|| [3]CONTACT NUMBER                 : " << x[2] << endl;
    cout << "|| [4]PATIENT AGE                    : " << x[3] << endl;
    cout << "|| [5]PATIENT GENDER                 : " << x[4] << endl;
    cout << "|| [6]PATIENT BLOOD GROUP            : " << x[5] << endl;
    cout << "|| [7]SYMPTOMS                       : " << x[6] << endl;
    cout << "|| [8]DIAGNOSIS                      : " << x[7] << endl;
    cout << "|| [9]DEASES FOUND AFTER DIAGNOSIS  : " << x[8] << endl;
    cout << "|| [10]MEDICINES                     : " << x[9] << endl;
    cout << "|| [11]]ADMIT REQUIRED TO HOSPITAL   : " << x[10] << endl;
    cout << " ====================================" << endl;
    cout << "Press any key to go to Main Menu ";
    getch();
    system("cls");
    start();
}
string pat::up_pat_rec(string id)
{
    system("cls");
    ifstream myFile;
    myFile.open("bin/Data.csv");
    string line;
    cout << "Enter Contat Number of Patient to update details : ";
    int n = rowCount(id); // desired row number
    int a = 0;            // counter
    string x[15];
    while (getline(myFile, line))
    {
        a++;
        if (a == n)
        {
            stringstream ss(line);
            string token;
            int i = 0;
            while (getline(ss, token, ','))
            {
                x[i] = token;
                i++;
            }
            break;
        }
    }
    cout << " ====================================" << endl;
    cout << "|| [1]ID                             : " << x[0] << endl;
    cout << "|| [2]NAME                           : " << x[1] << endl;
    cout << "|| [3]CONTACT NUMBER                 : " << x[2] << endl;
    cout << "|| [4]PATIENT AGE                    : " << x[3] << endl;
    cout << "|| [5]PATIENT GENDER                 : " << x[4] << endl;
    cout << "|| [6]PATIENT BLOOD GROUP            : " << x[5] << endl;
    cout << "|| [7]SYMPTOMS                       : " << x[6] << endl;
    cout << "|| [8]DIAGNOSIS                      : " << x[7] << endl;
    cout << "|| [9]DEASES FOUND AFTER DIAGNOSIS   : " << x[8] << endl;
    cout << "|| [10]MEDICINES                     : " << x[9] << endl;
    cout << "|| [11]ADMIT REQUIRED TO HOSPITAL    : " << x[10] << endl;
    cout << " ====================================" << endl;
}

int pat::Del_patRec()
{

    fstream fin, fout;
    fin.open("bin/Data.csv", ios::in);
    fout.open("bin/Datanew.csv", ios::out);
    string id;
    int count = 0, i;
    int index;
    string line, word;
    vector<string> row;
    cout << "Enter the Contact number of patient to be deleted: ";
    getline(cin, id);
    up_pat_rec(id);
    cout << "Are you sure You want to delete this record (y/n) : ";
    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        while (!fin.eof())
        {
            row.clear();
            getline(fin, line);
            stringstream s(line);
            while (getline(s, word, ','))
            {
                row.push_back(word);
            }
            int row_size = row.size();
            if (row[2] != id)
            {
                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++)
                    {
                        fout << row[i] << ",";
                    }
                    fout << row[row_size - 1] << "\n";
                }
            }
            else
            {
                count = 1;
            }
            if (fin.eof())
                break;
        }
        if (count == 1){
            cout << "Record deleted Successfully\n";
            cout<<"press any key to go to continue";
            getch();
            }
        else
            cout << "Record not found\n";
        fin.close();
        fout.close();
        remove("bin/Data.csv");
        rename("bin/Datanew.csv", "bin/Data.csv");
        system("cls");
        Admin_FuncPanel();
    }
    else if (ch == 'n' || ch == 'N')
    {
        system("cls");
        Admin_FuncPanel();
    }
    else
    {
        cout << "Invalid Input\n";
        cout<<"Press any key to continue\n";
        getch();
        Admin_FuncPanel();
    }
}
int pat::start()
{
    pat x;
    cout << "         ++++         " << endl;
    cout << "         ++++         " << endl;
    cout << "         ++++         " << endl;
    cout << "++++++++++++++++++++++" << endl;
    cout << "++++++++++++++++++++++" << endl;
    cout << "         ++++         " << endl;
    cout << "         ++++         " << endl;
    cout << "         ++++         " << endl
         << endl;

    cout << "##############################" << endl;
    cout << "# HOSPITAL MANAGEMENT SYSTEM #" << endl;
    cout << "##############################" << endl
         << endl;
    cout << "Select login Account" << endl;
    cout << "[1] User Account" << endl;
    cout << "[2] Admin Account" << endl;

    char opt;
    opt = getch();

    if (opt == '1')
    {
        x.user_FuncPanel();
    }
    else if (opt == '2')
    {
        x.Admin_FuncPanel();
    }
    else
    {
        cout << "invalid input" << endl;
        start();
        system("cls");
    }
}
int main()
{
    pat x;
    system("cls");
    x.start();
    return 0;
}
