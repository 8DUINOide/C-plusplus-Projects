//==================================================================================================
//Filename : PAZ_Object Oriented Programming in C++(Polymorphism).cpp
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Exercise Number : 5
//Description : Object Oriented Programming in C++(Polymorphism), A program that contains a base class along with derived classes that
//inherit and depend on one another, along with methods that integrate information
//regarding objects (in this case, employees) that are being inputted in the main function.
//Last modified: May 9, 2023
//==================================================================================================


#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Employee {
    public:
        Employee (string name, double baseSalary) {
            this->name = name;
            this->baseSalary = baseSalary;
            employeeCount++;
            this->employeeID = employeeCount;
            this->bonus = 0.0; // initialize bonus to 0.0
        }

        double getBaseSalary () {
            return this->baseSalary;
        }

        string getName() {
            return this->name;
        }

        int getEmployeeID() {
            return this->employeeID;
        }

        Employee *manager;

        Employee* getManager() {
            return manager;
        }

         void setManager(Employee* e) {
             this->manager=e;
        }


        bool equals(Employee* other) {
            return this->getEmployeeID() == other->getEmployeeID();
        }

        string toString() {
            return to_string(getEmployeeID()) + " " + getName();
        }

        string employeeStatus() {
            return this->status;
        }

    private:
        static int employeeCount;
        string name;
        double baseSalary;
        int employeeID;


    public:
        double bonus;
        string status;

};

class TechnicalEmployee : public Employee {
    public:
        TechnicalEmployee (string name) : Employee (name, 75000.00) {
        }

        string employeeStatus () {
            return to_string(getEmployeeID()) + " " + getName() + " has " + to_string(this->checkins) + " successful checkins";
        }

    private:
        static int checkins;
};

class BusinessEmployee : public Employee {
    public:
        BusinessEmployee (string name) : Employee (name, 50000.00) {
            this->bonusBudget -= this->getBaseSalary();
        }

        double getBonusBudget() {
            return this->bonusBudget;
        }

       string employeeStatus () {
            return to_string(getEmployeeID()) + " " + getName() + " with a budget of " + to_string(this->getBonusBudget());
        }


    private:
        static double bonusBudget;
};
class SoftwareEngineer: public TechnicalEmployee {
public:
    SoftwareEngineer(string name) : TechnicalEmployee (name) {
        this->name = name;
        this->codeAccess = false;
        this->successfulCheckIns = 0;
    }

    bool getCodeAccess() {
        return this->codeAccess;
    }

    void setCodeAccess(bool access) {
        access=this->codeAccess;
    }

    int getSuccessfulCheckIns() {
        return this->successfulCheckIns;
    }

    bool checkInCode() {
        // Check with manager if the check-in is approved
        bool approved = checkWithManager();

        if (approved) {
            // Increase the successful check-in count
            this->successfulCheckIns++;
            return true;
        }
        else {
            // If not approved, revoke code access
            this->codeAccess = false;
            return false;
        }
    }

    string employeeStatus () {
            return to_string(getEmployeeID()) + " " + getName() + " has " + to_string(getSuccessfulCheckIns()) + " successful checkins";
        }


private:
    string name;
    bool codeAccess;
    int successfulCheckIns;

    bool checkWithManager() {
        return true;
    }
};


class TechnicalLead: public TechnicalEmployee {

public:
    TechnicalLead(string name) : TechnicalEmployee(name) {
    baseSalary = getBaseSalary() * 1.3;
    manager = nullptr;
    this->headcount = 4;
    successfulCheckIns=0;
}


    bool hasHeadCount () {
        if (directreports.size() < this->headcount){
            return true;
        } else return false;
    }


    bool addReport(SoftwareEngineer* e) {
    if (hasHeadCount()) {
        directreports.push_back(e);
        e->setManager(this);
        return true;
    } else return false;

}

    bool approveCheckIn(SoftwareEngineer* e) {
        if (e->getCodeAccess()==1 && (addReport(e)==1)){
            return true;
        } else return false;
    }

    bool requestBonus(Employee e, double bonus) {
        if (bonus <= baseSalary) {
            e.bonus = bonus;
            return true;
        } else return false;
    }

    string getTeamStatus() {
        string status=employeeStatus() + " and ";
        if (directreports.empty()) {
                status += "no direct reports yet";
        } else {
            status+=" is managing:\n";
             for (auto *e : directreports) {
                status += "  " + e->employeeStatus() + "\n";
            }
        }
            return status;
        }

     const vector<SoftwareEngineer*>& getDirectReports() {
        return directreports;
    }


private:
    int headcount;
    vector<SoftwareEngineer*> directreports;
    int baseSalary;
    double bonus;
    int successfulCheckIns;

};

class Accountant:public Employee {

public:
    Accountant(string name) : Employee(name, 0.00), bonusBudget(0) {
    teamSupported = nullptr;
}

    TechnicalLead* getTeamSupported() {
        return teamSupported;
    }

    void supportTeam(TechnicalLead* lead) {

    this->teamSupported = lead;
    bonusBudget = 0;
    vector<SoftwareEngineer*> directReports = lead->getDirectReports();
    for (SoftwareEngineer* e : directReports) {
        bonusBudget += e->getBaseSalary() * 1.1;
    }
}

    bool approveBonus(double bonus) {
        if (bonus>bonusBudget) {
            return false;
        } else if (teamSupported==0){
            return false;
        } else return true;
    }

    string employeeStatus() {
        status = to_string(getEmployeeID()) + " " +  getName() + " with a budget of " + to_string(this->bonusBudget) + " is supporting ";
        if (getTeamSupported()== nullptr) {
            status += "no one";
        } else {
            status += getTeamSupported()->getName();
        }
        return status;
    }

private:
    double bonusBudget;
    double bonus;
    TechnicalLead* teamSupported;


};

class BusinessLead: public Accountant {

public:
    BusinessLead(string name):Accountant(name) {
        baseSalary*=2;
        BusinessLead *manager;
        headcount=10;
    }

    bool hasHeadCount () {
        if (directreports.size() < headcount){
            return true;
        } else return false;
    }

    bool addReport(Accountant* e, TechnicalLead supportTeam){
        this->baseSalary=e->getBaseSalary();
        if (hasHeadCount()>=1) {
            directreports.push_back(e);
            this->bonusBudget+=(1.1*this->baseSalary);
            return true;
        } else return false;

    }


  // Request a bonus for an employee
    bool requestBonus(Employee* e, double bonus) {
        if (this->bonusBudget>=bonus){
            bonus+=e->getBaseSalary();
            bonusBudget -= bonus;
            return true;
        } else return false;
    }


    bool approveBonus(SoftwareEngineer* employee, double bonus) {
        for (Accountant* accountant : directreports) {
            if (accountant->getTeamSupported() == employee->getManager()) {
                return accountant->approveBonus(bonus);
            }
        }
        return false;
    }

private:
    int headcount;
    vector<Accountant*> directreports;
    TechnicalLead* supportTeam;
    double bonusBudget;
    double baseSalary;
};



int Employee::employeeCount = 0;
int TechnicalEmployee::checkins = 0;
double BusinessEmployee::bonusBudget = 1000000;


int main() {
    Employee a("PAM", 20000);
    Employee b("SAM", 20000);
    Employee c("AL", 20000);


    cout << "Employee ID: " << a.getEmployeeID() << endl;
    cout << "Name: " << a.getName() << endl;
    cout << "Base Salary: " << a.getBaseSalary() << endl;
    cout << "Status: " << a.employeeStatus() << endl << endl;

    cout << "Employee ID: " << b.getEmployeeID() << endl;
    cout << "Name: " << b.getName() <<endl;
    cout << "Base Salary: " << b.getBaseSalary() <<endl;
    cout << "Status: " << b.employeeStatus() << endl << endl;

    cout << "Employee ID: " << c.getEmployeeID() << endl;
    cout << "Name: " << c.getName() <<endl;
    cout << "Base Salary: " << c.getBaseSalary() <<endl;
    cout << "Status: " << c.employeeStatus() << endl << endl;

    TechnicalEmployee d("Systems Architect");
    cout << "Employee ID: " << d.getEmployeeID() << endl;
    cout << "Name: " << d.getName() << endl;
    cout << "Base Salary: " << d.getBaseSalary() << endl;
    cout << "Status: " << d.employeeStatus() << endl << endl;

    BusinessEmployee e("Marketing Head");
    cout << "Employee ID: " << e.getEmployeeID() << endl;
    cout << "Name: " << e.getName() << endl;
    cout << "Base Salary: " << e.getBaseSalary() << endl;
    cout << "Status: " << e.employeeStatus() << endl << endl;

    SoftwareEngineer f1("Software Engineer John");
    cout << "Employee ID: " << f1.getEmployeeID() << endl;
    cout << "Name: " << f1.getName() << endl;
    f1.setCodeAccess(true);
    cout << "Code Access: " << f1.getCodeAccess() << endl;
    f1.checkInCode();
    f1.checkInCode();
    f1.checkInCode();
    cout << "Successful Check-Ins: " << f1.getSuccessfulCheckIns() << endl<<endl;

    SoftwareEngineer f2("Software Engineer Apple");
    cout << "Employee ID: " << f2.getEmployeeID() << endl;
    cout << "Name: " << f2.getName() << endl;
    f2.setCodeAccess(false);
    cout << "Code Access: " << f2.getCodeAccess() << endl;
    cout << "Successful Check-Ins: " << f2.getSuccessfulCheckIns() << endl;

    TechnicalLead g ("Technical Leader Anna");
    cout << endl << "Employee ID: " << g.getEmployeeID() << endl;
    cout << "Name: " << g.getName() << endl;
    cout << "Head count: " << g.hasHeadCount() << endl;
    cout << "Adding report... " << boolalpha << g.addReport (&f1) << endl;
    cout << "Checking in... " << g.approveCheckIn(&f1) << endl;
    cout << "Adding report... " << boolalpha << g.addReport (&f2) << endl;
    cout << "Checking in... " << g.approveCheckIn(&f2) << endl;
    cout << "Requesting for bonus... " << g.requestBonus (a, 4000.00) << endl;
    cout << "Team Status: "<<endl;
    cout << g.getTeamStatus();

    Accountant h("Accountant Mark");
    cout << endl << "Employee ID: " << h.getEmployeeID() << endl;
    cout << "Name: " << h.getName() << endl;
    cout << "Supported technical leader/s: " << h.getTeamSupported () << endl;
    h.supportTeam (&g);
    h.approveBonus (5000.00);
    cout << h.employeeStatus()<<endl;


    BusinessLead i ("Business Leader Ria");
    cout << endl << "Employee ID: " << i.getEmployeeID() << endl;
    cout << "Name: " << i.getName() << endl;
    cout << i.addReport(&h,g)<<endl;
    cout << "Head count: " << i.hasHeadCount() << endl;
    cout << "Requesting for bonus... " << i.requestBonus(&a, 500.00) << endl;
    cout << "Bonus approved? " << i.approveBonus (&f1, 5000.00) << endl;


    return 0;

}