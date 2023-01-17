#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Fullname {
public:
    string firstName;
    string lastName;
    string midName;

    void setFirstName(string firstName){
        this->firstName = firstName;
    }

    void setLastName(string lastName){
        this->lastName = lastName;
    }

    void setMidName(string midName){
        this->midName = midName;
    }

    string getFirstName(){
        return firstName;
    }

    string getLastName(){
        return lastName;
    }

    string getMidName(){
        return midName;
    }

    string getFullName(){
        return firstName + " " + lastName + " " + midName;
    }
};

class Address{
public:
    string roadName;
    string number;
    string alley;
    string ward;
    string district;
    string city;
    string nation;

    string getFullAddress();
};

string Address::getFullAddress(){
    return number + ", " + alley + ", " + roadName + ward + 
           ", " + district + ", " + city + ", " + nation;
}

class Person {
public:
    string id;
    Fullname fullName;
    Address address;
    string dateOfBirth;
    string email;
    string phoneNumber;
    string occ;
    string gender;
    //action
    void sleep();
    void eat();
    void work();
    void relax();
};

void Person::sleep(){
    cout << fullName.getFullName() << " is sleeping.\n";
}

void Person::eat(){
    cout << fullName.getFullName() << " is eating lunch.\n";
}

void Person::work(){
    cout << fullName.getFullName() << " is working in the garden.\n";
}

void Person::relax(){
    cout << fullName.getFullName() << " is relaxing by playing the piano.\n";
}

// nguyên mẫu hàm
void addPersonInfo(Person &person);
void showPersonInfo(Person person);

int main(){
    Person friends[100];
    int size = 0;
    int choice;
    do{
        cout << "======================= MENU =======================\n";
		cout << "1. Them moi thong tin nguoi.\n2. Hien thi danh sach.\n";
		cout << "0. Thoat.\nXin moi chon: ";
        cin >> choice;
        cin.ignore();
        switch(choice){
            case 0:
            {
                cout << "<== XIN CHAO VA HEN GAP LAI ==>\n";
			    break;
            }
            case 1:
            {
                addPersonInfo(friends[size++]);
                break;
            }
            case 2:
            {
                cout << "================ DANH SACH NHAN SU ================\n";
                cout << left << setw(20) << "CMND/CC/HC" << setw(27) << "Ho va ten" 
                    << setw(12) << "Ngay sinh" << setw(25) << "Email" << setw(15) 
                    << "Dia chi" << setw(15) << "So dien thoai" << setw(20)
                    << "Nghe nghiep" << setw(12) << "Gioi tinh" << endl;
                for (int i = 0; i < size; i++)
                {
                    showPersonInfo(friends[i]);
                }
                break;
            }
            default:
            {
                cout << "Wrong function. Please try again!\n";
                break;
            }
        }
    }while(choice != 0);

    return 0;
}

void addPersonInfo(Person &person){
    cout << "=================== GET PERSONAL INFORMATION ===================\n";
    cout << "Enter national ID: ";
    getline(cin, person.id);
    cout << "Enter last name: ";
    getline(cin, person.fullName.lastName);
    cout << "Enter mid name: ";
    getline(cin, person.fullName.midName);
    cout << "Enter first name: ";
    getline(cin, person.fullName.firstName);
    cout << "Enter date of birth: ";
    getline(cin, person.dateOfBirth);
    cout << "Enter email: ";
    getline(cin, person.email);
    cout << "Enter city name: ";
    getline(cin, person.address.city);
    cout << "Enter country name: ";
    getline(cin, person.address.nation);
    cout << "Enter phone number: ";
    getline(cin, person.phoneNumber);
    cout << "Enter occupation: ";
    getline(cin, person.occ);
    cout << "Gender: ";
    getline(cin, person.gender);
}

void showPersonInfo(Person person){
    cout << left << setw(20) << person.id << setw(27) << person.fullName.getFullName()
		<< setw(12) << person.dateOfBirth << setw(25) << person.email << setw(15)
		<< person.address.city << setw(15) << person.phoneNumber << setw(20)
		<< person.occ << setw(12) << person.gender << endl;
}