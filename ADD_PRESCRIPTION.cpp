#include <bits/stdc++.h>
using namespace std;

class pat
{
private:
    string first_name;
    string last_name;
    int pat_id;
    string pat_number;
    int pat_age;
    string pat_genders;
    string pat_BloodGroup;
    string Diseases;
    string symptoms;
    string pat_diagnose;
    string medicine;
    string pat_admission;

public:
    int Add_patient();
    int Add_Prescription();
    bool check_id(int);
};

int pat::Add_patient()
{
    cout << "FIRST NAME : ";
    getline(cin, first_name);
    cout << "LAST NAME : ";
    getline(cin >> ws, last_name);
    cout << "PATIENT ID : ";
    cin >> pat_id;
}

int pat::Add_Prescription()
{
    int ID;
    cout << "ENTER PATIENT ID : ";
    cin >> ID;
    if (ID=pat_id)
        
        {   
            cout<<"NAME : "<<first_name<<" "<<last_name<<endl;
            
            cout<<" --------------------------------------"<<endl;
            cout<<"| FOR DIAGNOSIS FILL THE BELOW DETAILS |"<<endl;
            cout<<" --------------------------------------"<<endl;

            cout << "ENTER SYMPTOMS : ";
            getline(cin>>ws, symptoms);
            cout << "ENTER DIAGNOSIS : ";
            getline(cin, pat_diagnose);
            cout << "DISEASE FOUND AFTER DIAGNOSIS : ";
            getline(cin, Diseases);
            cout << "MEDICINES : ";
            getline(cin, medicine);
            cout << "ADMIT REQUIRED TO HOSPITAL : ";
            getline(cin, pat_admission);
        }

    else
    {
        cout << "INVALID ID" << endl;
    }
}
int main()
{
    pat x;
    x.Add_patient();
    x.Add_Prescription();
    return 0;
}