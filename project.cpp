#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>

using namespace std;

//Global Variables//
string adminName = "admin";
string adminPassword = "123";
string userName;
string userPassword;
string newPassword;
bool isAdminLogin = false;
string productName [1000];
string sortedProductName [1000];
int productNumber [1000];
int sortedProductNumber[1000];
float productPrice [1000];
float copyProductPrice [1000];
float sortedProductPrice [1000];
string salePersonName [1000];
string salePersonPassword [1000];
int salePersonCounter = 0;
int productCounter = 0;
int customerBillCounter = 0;
float totalBill = 0;
string purchasedProductName [1000];
string purchaseItemName;




//Function headers//
int getFirstOption ();
int getAdminOption ();
int getCustomerOption ();
bool isLoginUI ();
void Login ( string uName, string uPassword );
void pressKey ();
void getProductDetailUI ();
void getProductDetail ( int pNumber, string pName, float pPrice );
void demoData ();
void displayAllProduct ();
void updateProduct ();
void deleteProduct ();
void addSalesPersonUI ();
void addSalesPerson ( string spName, string spPassword );
void viewSalesPerson ();
void totalSale ();
void changePasswordUI ();
void changePassword ( string nPassword );
void placeOrderUI ();
void placeOrder ( string pItemName );
void viewProductMenu ();
void sortProduct ();
void seeInvoice ();
//File System//
void saveProductData ();
void loadProductData ();
string getField ( string record, int position );
void saveSalesPersonData ();
void loadSalesPersonData ();


//Main Method//
int main(){

    loadProductData ();
    loadSalesPersonData ();

    int mainOption = -1;

    while ( mainOption != 3 ){

        system ( "CLS" );
        mainOption = getFirstOption();

        if ( mainOption == 1 ){

            isLoginUI ();
            pressKey ();

            if ( isAdminLogin == true ){

                int adminOption = -1;

                while ( adminOption != 9 ){

                    adminOption = getAdminOption ();

                    if ( adminOption == 1 ){

                        getProductDetailUI ();
                        pressKey ();

                    }

                    if ( adminOption == 2 ){

                        displayAllProduct ();
                        pressKey ();

                    }

                    if ( adminOption == 3 ){

                        updateProduct ();
                        pressKey ();

                    }

                    if ( adminOption == 4 ){

                        deleteProduct ();
                        pressKey ();

                    }

                    if ( adminOption == 5 ){

                        addSalesPersonUI ();
                        pressKey ();

                    }

                    if ( adminOption == 6 ){

                        viewSalesPerson ();
                        pressKey ();

                    }

                    if ( adminOption == 7 ){

                        totalSale ();
                        pressKey ();

                    }

                    if ( adminOption == 8 ){

                        changePasswordUI ();
                        pressKey ();

                    }
                    
                }
                
            }

            

        }

        if ( mainOption == 2 ){

            int customerOption = -1;

            while ( customerOption != 5 ){

                customerOption = getCustomerOption ();

                if ( customerOption == 1 ){

                    placeOrderUI ();
                    pressKey ();

                }

                if ( customerOption == 2 ){

                    viewProductMenu ();
                    pressKey ();

                }

                if ( customerOption == 3 ){

                    sortProduct ();
                    pressKey ();

                }

                if ( customerOption == 4 ){

                    seeInvoice ();
                    pressKey ();

                }


            }
        }

    }


}

//FUNCTION CODES//

//Function for Viewing the Main Options//
int getFirstOption(){

    int mainOption = -1;

    cout << "***********************************************************" << endl;
    cout << "                    Grocery Shop System                    " << endl;
    cout << "***********************************************************" << endl;
    cout << "1. Admin" << endl;
    cout << "2. Customer" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter Your Option..";

    cin >> mainOption;

    return mainOption;

}

//Function for Viewing Admin Options//
int getAdminOption (){

    int adminOption = -1;
    system ( "CLS" );

    cout << "*****************************************************" << endl;
    cout << "                    Welcome, Admin                    " << endl;
    cout << "*****************************************************" << endl;
    cout << "1. Create Product" << endl;
    cout << "2. Display All Products" << endl;
    cout << "3. Update Product" << endl;
    cout << "4. Delete Product" << endl;
    cout << "5. Add Sale-Person" << endl;
    cout << "6. View Sale-Person" << endl;
    cout << "7. Total Sale of the Day" << endl;
    cout << "8. Change Password" << endl;
    cout << "9. Logout" << endl;
    cout << "Enter Your Option..";

    cin >> adminOption;

    return adminOption;

}

//Function for Getting Character to Terminate a Program//
void pressKey (){

    cout << "Press Any Key to Continue ...";
    getch ();
    cout << endl;

}

//Funtion for Checking if User is Admin or Not//
bool isLoginUI (){

    string uName, uPassword;

    cout << "Enter User Name ...";
    cin >> uName;

    cout << "Enter Password ...";
    cin >> uPassword;

    Login ( uName, uPassword );

    if (( uName == adminName) && ( uPassword == adminPassword )){ //Condition for checking the username and password to be correct//

        isAdminLogin = true;
        cout << "*Login Successful*" << endl;

    }

    else{

        cout << "*Invalid Login*" << endl;
        isAdminLogin = false;

    }

    return isAdminLogin;
}

void Login ( string uName, string uPassword ){

    userName = uName;
    userPassword = uPassword;

}

//Funtion for Adding Products (First Admin Option)//
void getProductDetailUI (){

    int pNumber;
    string pName;
    float pPrice;

    cout << "Enter the Product Number ...";
    cin >> pNumber;

    cout << "Enter the Product Name ...";
    cin >> pName;

    cout << "Enter the Product Price ...";
    cin >> pPrice;

    getProductDetail ( pNumber, pName, pPrice );
    saveProductData ();

    cout << "* Product Has Been Added in the System *" << endl;

}


void getProductDetail ( int pNumber, string pName, float pPrice ){

    productNumber[productCounter] = pNumber;
    productName[productCounter] = pName;
    productPrice[productCounter] = pPrice;

    productCounter++;

}

void demoData (){

    //Demo Data for storing products in the system//
    getProductDetail ( 1, "Nutella", 950 );
    getProductDetail ( 2, "Gillete", 3999 );
    getProductDetail ( 3, "Trident", 220 );

    //Demo Data for storing salesperson in the system//
    addSalesPerson ( "Suhaib", "sobi" );
    addSalesPerson ( "Aroob", "fish" );
    addSalesPerson ( "Saad", "saad");

}

//Function for Displaying the Products Existing in the System (Second Admin Option)//
void displayAllProduct (){

    cout << "Num. \t Name \t\t Price" << endl;

    for ( int idx = 0; idx < productCounter; idx ++){ //Displaying existing product in the system//

        cout << productNumber[idx] << " \t " << productName[idx] << " \t " << productPrice[idx] << endl;

    }
}

//Function for Updating a Certain Product Existing in the System (Third Admin Option)//
void updateProduct (){

    cout << "Num. \t Name \t\t Price" << endl;

    for ( int idx = 0; idx < productCounter; idx ++){ //Displaying existing products in the system//

        cout << productNumber[idx] << " \t " << productName[idx] << " \t " << productPrice[idx] << endl;

    }

    string check;

    cout << "Enter Product Name You Want to Update ...";
    cin >> check;

    for ( int idx =0; idx < productCounter; idx++ ){ //Loop for matching the index of the product user want to update//

        if ( check == productName[idx] ){ //Condition for checking the index with existing products//

            cout << "Enter New Product Name ...";
            cin >> productName[idx];

            cout << "Enter New Product Price ...";
            cin >> productPrice[idx];

            cout << "* Product Has Been Updated *" << endl;

        }
    }
    
}

//Function for Deleting a Certain Product Existing in the System (Fourth Admin Option)//
void deleteProduct (){

    bool flag = false;
    string check; //Variable for entering name of desired product

    cout << "Num. \t Name \t\t Price" << endl;

    for ( int idx = 0; idx < productCounter; idx ++){ //Displaying existing products in the system//

        cout << productNumber[idx] << " \t " << productName[idx] << " \t " << productPrice[idx] << endl;

    }

    cout << "Enter Product Name You Want to Delete ...";
    cin >> check;
    
    for ( int idx = 0; idx < productCounter; idx++ ){ //Loop for matching the index of the product user want to delete//

        if ( check == productName[idx] ){ //Conditional statement for checking if the entered name matches the existing product name//

            productName[idx] = productName[productCounter-1];
            productNumber[idx] = productNumber[productCounter-1];
            productPrice[idx] = productPrice[productCounter-1];

            productCounter--;

            flag = true;

            cout << "* Product Has Been Deleted *" << endl;

        }
    }

    if ( flag == false ){

        cout << "* Product Not Found *" << endl;

    } 
}

//Function for Adding Salesperson's Account Details (Fifth Admin Option)//
void addSalesPersonUI (){

    string spName;
    string spPassword;

    cout << "Enter Salesperson's Username ...";
    cin >> spName;

    cout << "Enter Salesperson's Password ...";
    cin >> spPassword;

    addSalesPerson ( spName, spPassword );
    saveSalesPersonData ();

    cout << "* Salesperson Has Been Added *" << endl;
}

void addSalesPerson ( string spName, string spPassword ){

    salePersonName[salePersonCounter] = spName;
    salePersonPassword[salePersonCounter] = spPassword;

    salePersonCounter++; //Counter for adding total salespersons//

}

//Function for Viewing Salesperson's Account Details (Sixth Admin Option)//
void viewSalesPerson (){

    cout << "Num. \t Username\tPassword" << endl;

    for ( int idx = 0; idx < salePersonCounter; idx++ ){ //Lopp for displaying existing sale person details in the system//

        cout << idx + 1 << "\t" << salePersonName[idx] << "\t\t" << salePersonPassword[idx] << endl; 

    }
}

//Function for Calculating Total Sale of the Day (Seventh Admin Option)//
void totalSale (){

    cout << "Total Sale of the Day is ->" << totalBill << endl;

}

//Function for Changing Password of the Admin (Eigth Admin Option)//
void changePasswordUI (){
    
    string nPassword;
    string check = "";

    cout << "Enter Old Password ...";
    cin >> check;

    if ( check == adminPassword ){ //Condition for checking admin password//

        cout << "Enter New Password ...";
        cin >> nPassword;

        changePassword ( nPassword );

        adminPassword = nPassword; //Changing the password//

        cout << "* Your Password Have Been Changed *" << endl;

    }
}

void changePassword ( string nPassword ){

    newPassword = nPassword;

}

//Function for Viewing Customers Option//
int getCustomerOption (){

    int customerOption = -1;
    system ( "CLS" );

    cout << "*********************************************************" << endl;
    cout << "                    Welcome, Customer                    " << endl;
    cout << "*********************************************************" << endl;
    cout << endl;
    cout << "Choose from the following options:-" << endl;
    cout << "1. Place Order" << endl;
    cout << "2. View Product Menu" << endl;
    cout << "3. Sort Product According to Price" << endl;
    cout << "4. See Invoice" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter Your Option ...";

    cin >> customerOption;

    return customerOption;

}

//Function for Placing Order of Products (First Customer Option)//
void placeOrderUI (){

    string pItemName;

    cout << "Num. \t Name \t\t Price" << endl;

    for ( int idx = 0; idx < productCounter; idx ++){ //Displaying existing products in the system//

        cout << productNumber[idx] << " \t " << productName[idx] << " \t " << productPrice[idx] << endl;

    }

    cout << "Enter the Product Name You Want to Purchase ...";
    cin >> pItemName;

    placeOrder ( pItemName );

    for ( int idx = 0; idx < productCounter; idx++ ){ //Loop for matching the index of the product user want to purchase//

        if ( purchaseItemName == productName[idx] ){ //Conditional statement for matching the product as of searched product//

            purchasedProductName[customerBillCounter] = purchaseItemName;
            
            cout << "* " << purchaseItemName << " Added to the Cart *" << endl;

            customerBillCounter++; //Total purchased items counter//

            break;
        }
        
    }
    
}

void placeOrder ( string pItemName ){

    purchaseItemName = pItemName;

}

//Function for Display All the Products Existing in the System (Second Customer Option)//
void viewProductMenu (){

    if ( productCounter != 0 ){ //Conditional statement for checking if products exists in the system//

        cout << "* The Available Products Are *"<<endl;
        cout << endl;

        cout << "Num. \t Name \t\t Price" << endl;

        for ( int idx = 0; idx < productCounter; idx ++){ //Displaying existing products in the system//

            cout << productNumber[idx] << " \t " << productName[idx] << " \t " << productPrice[idx] << endl;

        }
    }

    else {

        cout << "* No Products Are Available *" << endl;

    }
}

//Function for Sorting Product According to the Prices (Third Customer Option)//
void sortProduct (){

    int sortedIdx = 0;

    for ( int idx = 0; idx < productCounter; idx++ ){ //Loop for copying array

        copyProductPrice[idx] = productPrice[idx];

    }

    for ( int newIdx = 0; newIdx < productCounter; newIdx++ ){ //Loop for storing the products in descending order//

        int largest = copyProductPrice[0];
        int largestIdx = 0;

        for ( int idx = 1; idx < productCounter; idx++ ){ //Loop for finding the product with largest price//

            if ( copyProductPrice[idx] > largest ){ //Condition for comparing largest number//

                largest = copyProductPrice[idx];
                largestIdx = idx;

            }
            
            
            
        }

        copyProductPrice[largestIdx] = -1;
        sortedProductPrice[newIdx] = largest;
        sortedProductName[newIdx] = productName[largestIdx];
        sortedProductNumber[newIdx] = productNumber[largestIdx];
    }

    for ( int idx = 0; idx < productCounter; idx++ ){ // Loop for displaying sorted products//

        cout << sortedProductNumber[idx] << " \t " << sortedProductName[idx] << " \t " << sortedProductPrice[idx] << endl;

    }
}

//Function for Viewing the Total Bill (Fourth Customer Option)// 
void seeInvoice (){

    if ( customerBillCounter != 0 ){ //Conditional statement for checking if user has purchased anything//

        cout << "* You Purchased These Items *" << endl;

        for ( int idx = 0; idx < customerBillCounter; idx++ ){ //Loop for displaying purchased products//

            cout << idx + 1 << "\t" << purchasedProductName[idx] << "\t" << productPrice[idx] << endl;
            totalBill = totalBill + productPrice[idx];

        }
        
        cout << "Your Total Bill is -> " << totalBill << endl;
    }

    else{

        cout << "* You Did Not Purchase Anything *" << endl; 

    }
}

void saveProductData (){
    
    fstream file;
    file.open("products.txt",ios::out);
    string record = "";

    for ( int idx = 0; idx < productCounter; idx++ ){

        record = "";
        record = record + to_string(productNumber[idx]);
        record = record + "," + productName[idx];
        record = record + "," + to_string(productPrice[idx]);
        record = record + "\n";
        file << (record);
    }
    file.close();
}

void loadProductData (){

    fstream file;
    file.open ( "products.txt",ios::in );
    string record = "";

    while ( getline ( file,record ) ) {

        int productNumber = stof ( getField(record,0) );
        string productName = getField ( record,1 );
        float productPrice = stof ( getField ( record,2 ) );

        void getProductDetail ( int pNumber, string pName, float pPrice );
        
    }
    
    file.close();
}

string getField (string record,int position){

    int commasFound = 0;
    string field = "";
    int idx = 0;
    
    while ( commasFound < position+1 && idx < record.length() ){\

        char c = record[idx];

        if (c == ','){

            commasFound = commasFound + 1;
        }

        else if ( commasFound == position ){

            field = field + c;
        }
        idx++;
    }
    return field;
}

void saveSalesPersonData (){

    fstream file;
    file.open("salesperson.txt",ios::out);
    string record="";

    for ( int idx = 0; idx < salePersonCounter; idx++ ){

        record = "";
        record = record+salePersonName[idx];
        record = record+","+salePersonPassword[idx];
        record = record+"\n";

        file << (record);
    }
    file.close();
}

void loadSalesPersonData (){

    fstream file;
    file.open("products.txt",ios::in);
    string record="";

    while ( getline ( file,record ) ) {

        int productNumber = stof(getField(record,0));
        string productName = getField(record,1);
        float productPrice = stof(getField(record,2));

        void addSalesPerson ( string spName, string spPassword );
        
    }
    file.close();
}