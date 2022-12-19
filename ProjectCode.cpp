#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include<cstdlib>
using namespace std;
struct Emp_data_Enter {
    string Employee_ID;
    string Employee_Name;
    string Designation;
    int Basic_Salary;
    string Month;
    int Leaves;
    int Allowed_Leaves;
    int Per_Leaves_Deduction_Rate;
    int Salary;

};
// function prototype

int DisplayMenu();

void CaculateSalary();

void GenerateSalarySlip();

void EnterNewEmpDta();


int main()
{
    int choice = 0;
    while (choice != 4)  // loop for reoccuring Menu
    {
        choice = DisplayMenu();
        switch (choice)
        {
        case 1:
            CaculateSalary();
            break;
        case 2:
            GenerateSalarySlip();
            break;
        case 3:
            EnterNewEmpDta();
            break;
        case 4:
            cout << "Program Exit Sucessfully!" << endl;
            break;
        default:
            cout << "Enter Valid Entry" << endl;
        }
    }
    return 0;
}
//****************************************Computing Salary****************************///////
void CaculateSalary()
{
    string line;
    
    string empID = "";
    string empName = "";
    bool isFound = false;

    cout << "Enter following information of Employee, to enter salary details:\n\n";

    cout << "Enter Employee name: ";
    cin.ignore();
    getline(cin, empName);
    cout << "Enter Employee ID: ";
    getline(cin, empID);

    ifstream EmployeeManagmentSystem;
    EmployeeManagmentSystem.open("EmployeeManagementSystem.txt");
    /*--------------Read Data already exist in File & store in array */
    if (EmployeeManagmentSystem.is_open())
    {
        Emp_data_Enter arr[50];
        int i = 0;
        while (EmployeeManagmentSystem.good())
        {
            getline(EmployeeManagmentSystem, line);
            // cout << line << endl;
            stringstream ss;
            ss << line;
            ss >> arr[i].Employee_ID;
            ss >> arr[i].Employee_Name;
            ss >> arr[i].Designation;
            ss >> arr[i].Basic_Salary;
            ss >> arr[i].Month;
            ss >> arr[i].Leaves;
            ss >> arr[i].Allowed_Leaves;
            ss >> arr[i].Per_Leaves_Deduction_Rate;
            ss >> arr[i].Salary;

            if (arr[i].Employee_ID == empID && arr[i].Employee_Name == empName) {
                // record is found
                isFound = true;
                cout << endl << endl;
                cout << "\tEdit the Data of " << arr[i].Employee_ID << endl;
                cout << "\tEmployee Name::  " << arr[i].Employee_Name << endl;
                cout << "\tDesignation::  " << arr[i].Designation << endl;
                cout << "\tEnter the month:: ";
                cin >> arr[i].Month;
                cout << "\tEnter the leaves:: ";
                cin >> arr[i].Leaves;

                if (arr[i].Leaves > arr[i].Allowed_Leaves)
                    arr[i].Salary = arr[i].Basic_Salary - (arr[i].Leaves - arr[i].Allowed_Leaves) * arr[i].Per_Leaves_Deduction_Rate;
                else
                    arr[i].Salary = arr[i].Basic_Salary;
                fstream myfile("EmployeeManagementSystem.txt", ios::in | ios::out | ios::app);
                myfile << endl << arr[i].Employee_ID << "\t" << arr[i].Employee_Name << "\t" << arr[i].Designation << "\t" << arr[i].Basic_Salary << "\t" << arr[i].Month << "\t" << arr[i].Leaves << "\t" << arr[i].Allowed_Leaves << "\t" << arr[i].Per_Leaves_Deduction_Rate << "\t" << arr[i].Salary;
            }
            

            i++;
        }

        if (isFound == false) {
            cout << "\'" << empName << "\' Employee information does not found!\n";
        }
    }

    else
    {
        cout << "File Not Found";
    }
}
/*********************************************DisplayMenu*************************************************/
int DisplayMenu()
{
    int choice = 0;
    cout << "\n\n\n\n******************************************************************************************" << endl;
    cout << "                                     Pay Roll Managment System" << endl;
    cout << "******************************************************************************************" << endl << endl << endl;
    cout << "\tEnter 1 to Enter Information of Employee to Manage Salary of Specific Month" << endl;
    cout << "\tEnter 2 to Print Salary Slips of Specific Month" << endl;
    cout << "\tEnter 3 to Add  new employee" << endl;
    cout << "\tEnter 4 to Quit" << endl << endl;
    cout << "\n******************************************************************************************" << endl;
    cout << "                                                 Menu" << endl;
    cout << "**********************************************************************************************" << endl << endl << endl;
    cout << "\tEnter Your Choice:: ";
    cin >> choice;

    return choice;
}
/*****************************************************Computing Salary**************************************/
void GenerateSalarySlip()
{
    cout << "\n\n\n\n*********************************************" << endl;
    cout << "         Salary Slip Generator " << endl;
    cout << "*********************************************" << endl;
    std::string line, month, file_name;
    cout << "\tEnter Month Against you want print salary::";
    cin >> month;
    ifstream EmployeeManagmentSystem;
    EmployeeManagmentSystem.open("EmployeeManagementSystem.txt");
    /*--------------Read Data already exist in File & store in array */
    if (EmployeeManagmentSystem.is_open())
    {
        Emp_data_Enter SlipData, check;
        while (EmployeeManagmentSystem.good())
        {
            getline(EmployeeManagmentSystem, line);
            //for specifuc month
            stringstream cc;
            cc << line;
            cc >> check.Employee_ID;
            cc >> check.Employee_Name;
            cc >> check.Designation;
            cc >> check.Basic_Salary;
            cc >> check.Month;
            if (check.Month == month)
            {
                //  cout << line << endl;
                stringstream ss;
                ss << line;
                ss >> SlipData.Employee_ID;
                ss >> SlipData.Employee_Name;
                ss >> SlipData.Designation;
                ss >> SlipData.Basic_Salary;
                ss >> SlipData.Month;
                ss >> SlipData.Leaves;
                ss >> SlipData.Allowed_Leaves;
                ss >> SlipData.Per_Leaves_Deduction_Rate;
                ss >> SlipData.Salary;
                file_name = SlipData.Employee_ID + "_" + SlipData.Employee_Name + "_" + SlipData.Month + "_" + "SalarySlip.txt";
                ofstream SalarySlip;
                SalarySlip.open(file_name.c_str());
                SalarySlip << "Salary Month: " << SlipData.Month << endl;
                SalarySlip << "Employee Name: " << SlipData.Employee_Name << endl;
                SalarySlip << "Designation: " << SlipData.Designation << endl;
                SalarySlip << "Salary : " << SlipData.Salary << endl << endl << endl << endl;

                // cout << file_name << endl;
            }
            else
            {
                continue;
            }

        }
        cout << "Sucessfully Generated Salary Slips Against " << month;

    }
    else
    {
        cout << "File Not Found";
    }
}
/*********************************************ADd NEW Employee****************************************************/
void EnterNewEmpDta()
{
    cout << "*********************************************" << endl;
    cout << "         Enter Information Of New Employee" << endl;
    cout << "*********************************************" << endl;
    Emp_data_Enter new_emp_data;
    int exit = 0;
    fstream EmployeeManagmentSystem;
    EmployeeManagmentSystem.open("EmployeeManagementSystem.txt", ios::out | ios::app);
    do
    {
        cout << "Enter Employee ID:: ";
        cin >> new_emp_data.Employee_ID;
        cout << "Enter Employee Name:: ";
        cin >> new_emp_data.Employee_Name;
        cout << "Enter Designation:: ";
        cin >> new_emp_data.Designation;
        cout << "Enter Basic Salary:: ";
        cin >> new_emp_data.Basic_Salary;
        cout << "Enter Month:: ";
        cin >> new_emp_data.Month;
        cout << "Enter Leaves:: ";
        cin >> new_emp_data.Leaves;
        cout << "Enter Allowed Leaves:: ";
        cin >> new_emp_data.Allowed_Leaves;
        cout << "Enter Per Leave Deduction:: ";
        cin >> new_emp_data.Per_Leaves_Deduction_Rate;
        if (new_emp_data.Leaves > new_emp_data.Allowed_Leaves)
        {
            new_emp_data.Salary = new_emp_data.Basic_Salary - (new_emp_data.Leaves - new_emp_data.Allowed_Leaves) * new_emp_data.Per_Leaves_Deduction_Rate;
        }
        else
        {
            new_emp_data.Salary = new_emp_data.Basic_Salary;
        }
        //write data in file
        EmployeeManagmentSystem << endl << new_emp_data.Employee_ID << "\t" << new_emp_data.Employee_Name << "\t" << new_emp_data.Designation << "\t" << new_emp_data.Basic_Salary << "\t" << new_emp_data.Month << "\t" << new_emp_data.Leaves << "\t" << new_emp_data.Allowed_Leaves << "\t" << new_emp_data.Per_Leaves_Deduction_Rate << "\t" << new_emp_data.Salary;
        cout << "Enter -1 to exit and any other number to add new employee:: ";
        cin >> exit;
    } while (exit != -1);
}
