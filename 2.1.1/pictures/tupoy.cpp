#include <iostream>
#include <string>
using namespace std;

class Employee 
{
    string     organization;
    string     position;
    double     experience;
    string     name;
    char       gender;
    int        age;
    double     salary;
    static int count;

public:
    string Get_organization(); 
    string Get_position(); 
    double Get_experience();
    double Get_salary(); 
    void   Set_position(string);
    void   Set_salary(double); 
    void   Show_personalData() const;
    void   Show_all_data() const; 

    Employee() 
    {
        this->name = "";
        this->gender = '0';
        this->age = 0;
        this->experience = 0;
        this->organization = "";
        this->position = "";
        this->salary = 0;
        count++;
    }


    Employee(const Employee& other) 
    {
        this->name         = other.name;
        this->gender       = other.gender;
        this->age          = other.age;
        this->experience   = other.experience;
        this->organization = other.organization;
        this->position     = other.position;
        this->salary       = other.salary;
        count++;
        
    }

    Employee(string name, char gender, int age, double experience, string organization, string position, double salary) 
    {
        this->name         = name;
        this->gender       = gender;
        this->age          = age;
        this->experience   = experience;
        this->organization = organization;
        this->position     = position;
        this->salary       = salary;
        count++;
    }

    ~Employee() 
    {
        count--;
    }

    Employee& operator = (const Employee& other)
    {
        this->name         = other.name;
        this->gender       = other.gender;
        this->age          = other.age;
        this->experience   = other.experience;
        this->organization = other.organization;
        this->position     = other.position;
        this->salary       = other.salary;
        return *this;
    }

    bool operator == (const Employee& other) 
    {
        return this->name         == other.name
            && this->gender       == other.gender
            && this->age          == other.age
            && this->experience   == other.experience
            && this->organization == other.organization
            && this->position     == other.position
            && this->salary       == other.salary;
    }

    bool operator != (const Employee& other) {
        return !(this->name == other.name
            && this->gender == other.gender
            && this->age == other.age
            && this->experience == other.experience
            && this->organization == other.organization
            && this->position == other.position
            && this->salary == other.salary);
    }

    //Получение количества сотрудников
    static void ShowCount() {
        cout << "Number of employees is " << count << endl;
    }
};

    string Employee::GetOrganization() {
        return this->organization;
    }

    string Employee::GetPosition() {
        return this->position;
    }

    double Employee::GetExperience() {
        return this->experience;
    }

    double Employee::GetSalary() {
        return this->salary;
    }

    void Employee::SetPosition(string newPosition) {
        this->position = newPosition;
    }

    void Employee::SetSalary(double salary) {
        this->salary = salary;
    }

    void Employee::ShowPersonalData() const {
        cout << "Name: " << this->name << endl;
        cout << "Gender: " << this->gender << endl;
        cout << "Age: " << this->age << endl;
    }

    void Employee::ShowAllData() const {
        this->ShowPersonalData();
        cout << "Experience: " << this->experience << endl;
        cout << "Organization: " << this->organization << endl;
        cout << "Position: " << this->position << endl;
        cout << "Salary: " << this->salary << endl;
        cout << endl;
    }

int Employee::count = 0;


int main() {
    const int NUMBER_OF_EMPLOYEES = 4;
    Employee employees[NUMBER_OF_EMPLOYEES] {
        Employee("Vasiliy", 'm', 32, 4.1, "Krest", "manager", 65000),
        Employee("Maria", 'f', 25, 3.5, "Krest", "secretary", 35000),
        Employee("Artyom", 'm', 34, 4.8, "Krest", "top manager", 98000),
        Employee("Alexandra", 'f', 28, 4.5, "Krest", "deputy top manager", 85000)
    };
    

    for (auto employee : employees) {
        employee.ShowAllData();
    }

    Employee::ShowCount(); //4
    Employee* empl1 = new Employee(); 
    Employee::ShowCount(); //5
    delete empl1;
    empl1 = nullptr;
    Employee::ShowCount(); //4

    cout << employees[2].GetExperience() << endl;
    cout << employees[2].GetOrganization() << endl;
    employees[0].SetPosition("top manager");
    cout << employees[0].GetPosition() << endl;
    employees[0].SetSalary(60000);
    cout << employees[0].GetSalary() << endl;
    employees[2].ShowPersonalData();

    employees[1] == employees[2] ? cout << "true" << endl : cout << "false" << endl;
    employees[1] != employees[2] ? cout << "true" << endl : cout << "false" << endl;
    employees[1] = employees[2];
    employees[1] == employees[2] ? cout << "true" << endl : cout << "false" << endl;
    employees[1] != employees[2] ? cout << "true" << endl : cout << "false" << endl;
    return 0;
}
