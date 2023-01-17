#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Smartphone{
public:
    int id;
    string brand;
    string name;
    float price;
    int ram;
    int externalMem;
    string dateOfManufacture;

    void createInfo();
    
    void showInfo();

    float compareByPrice(Smartphone& other);

    int compareByName(Smartphone& other);

    int getId(){
        return id;
    }

    void setId(int id){
        this->id = id;
    }

    string getBrand(){
        return brand;
    }

    string getName(){
        return name;
    }

    void setBrand(string brand){
        this->brand = brand;
    }

    void setName(string name){
        this->name = name;
    }

    float getPrice(){
        return price;
    }
    
    void setPrice(float price){
        this->price = price;
    }

    int getRam(){
        return ram;
    }

    void setRam(int ram){
        this->ram = ram;
    }

    int getExternalMem(){
        return externalMem;
    }

    void setExternalMem(int externalMem){
        this->externalMem = externalMem;
    }

    string getDOM(){
        return dateOfManufacture;
    }

    void setDOM(string dom){
        this->dateOfManufacture = dom;
    }
};

void Smartphone::createInfo(){
    cout << "ID: ";
    cin >> id;
    cin.ignore();
    cout << "Name of product: ";
    getline(cin, name);
    cout << "Name of brand: ";
    getline(cin, brand);
    cout << "RAM: ";
    cin >> ram;
    cout << "External memory: ";
    cin >> externalMem;
    cin.ignore();
    cout << "Date of manufacture: ";
    getline(cin, dateOfManufacture);
    cout << "Price: ";
    cin >> price;
    cin.ignore();
}

void Smartphone::showInfo(){
    cout << left << setw(10) << id << setw(20) << name 
		<< setw(20) << brand << setw(15) << price
		<< setw(15) << ram << setw(15) << externalMem 
		<< setw(20) << dateOfManufacture << endl;
}

int Smartphone::compareByName(Smartphone& other){
    return name.compare(other.name);
}

float Smartphone::compareByPrice(Smartphone& other){
    return price - other.price;
}

int main(){
    int choice;
    Smartphone products[100];
    int n = 0;
    do{
        cout << "==================== MENU ====================\n";
        cout << "1. Add a new smartphone.\n";
        cout << "2. Fix the selling price by product code\n";
        cout << "3. Delete products by code.\n";
        cout << "4. Display the list to the srceen.\n";
        cout << "5. Sort product list by ascending code.\n";
        cout << "6. Sort product list by descending price.\n";
        cout << "0. Exit program!\n";
        cout << "Your choice? ";
        cin >> choice;
        cin.ignore();
        switch(choice)
        {
            case 0:
            {
                cout << "Program ended. Goodbye and see you again!\n";
                break;
            }
            case 1:
            {
                Smartphone s;
                s.createInfo();
                products[n++] = s;
                break;
            }
            case 2:
            {
                if(n == 0){
                    cout << "Product list is empty.\n";
                    
                }
                else{
                    cout << "Enter ID: ";
                    int id;
                    cin >> id;
                    float price;
                    bool fixed = false;
                    for (int i = 0; i < n; i++)
                    {
                        if(products[i].getId() == id){
                            cout << "Enter new price for product: ";
                            cin >> price;
                            cin.ignore();
                            products[i].setPrice(price);
                            cout << "Successful price modification!\n";
                            fixed = true;
                            break;
                        }
                    }
                    if(!fixed){
                        cout << "ID is not found.\n";
                    }
                }
                break;
            }
            case 3:
            {
                if(n == 0){
                    cout << "Product list is empty.\n";
                }
                else{
                    cout << "Enter ID: ";
                    int id;
                    cin >> id;
                    bool removed = false;
                    for (int i = 0; i < n; i++)
                    {
                        if(products[i].getId() == id){
                            for (int j = i; j < n; j++)
                            {
                                products[j] = products[j + 1];
                            }
                            --n;
                            cout << "Remove successfully!\n";
                            removed = true;
                            break;
                        }
                    }
                    if(!removed){
                        cout << "ID is not found.\n";
                    }
                }
                break;
            }
            case 4:
            {
                if(n == 0){
                    cout << "Product list is empty.\n";
                }
                else{
                    cout << "Available products.\n";
                    cout << left << setw(10) << "Ma SP" << setw(20) << "Ten san pham"
					<< setw(20) << "Hang san xuat" << setw(15) << "Gia ban" << setw(15) << "RAM"
					<< setw(15) << "Bo nho ngoai" << setw(20) << "Ngay san xuat" << endl;
                    for (int i = 0; i < n; i++)
                    {
                        products[i].showInfo();
                    }
                }
                break;
            }
            case 5:
            {
                if(n > 0){
                    for (int i = 0; i < n - 1; i++)
                    {
                        for (int j = n- 1; j > i; j--)
                        {
                            if(products[j - 1].getId() > products[j].getId()){
                                swap(products[j], products[j - 1]);
                            }
                        }
                    }
                }
                else{
                    cout << "Product list is empty.\n";
                }
                break;
            }
            case 6:
            {
                if(n > 0){
                    for (int i = 0; i < n - 1; i++)
                    {
                        for (int j = n- 1; j > i; j--)
                        {
                            if(products[j - 1].compareByPrice(products[j]) < 0){
                                swap(products[j], products[j - 1]);
                            }
                        }
                    }
                }
                else{
                    cout << "Product list is empty.\n";
                }
                break;
            }
            default:
            {
                cout << "Wrong function. Please choose again!\n";
                break;
            }
        }
    }while(choice != 0);

    return 0;
}