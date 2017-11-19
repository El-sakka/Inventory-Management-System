#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;
typedef map<string, string> mss;
typedef map<char, int> MC;
typedef set<int> S;
typedef long long ll;

#define mp make_pair
#define pb push_back
#define all(c)	c.begin(),c.end()
#define For(i,n) for(int i=0;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define tr(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)


int userType;
int  adminID = 123, adminPassword = 123, cashierID = 987,
		cashierPassword = 987;

int profit = 0 ;

struct product{
	int productId;
	int itemsOfProduct;
	int costPerItem;
};

vector<product> products;

int Login(){
	int username,password;
	cout<<"Enter your username : ";
	cin>>username;
	cout<<"\nEnter your password : ";
	cin>>password;

	if(username == adminID && password == adminPassword)
		return 1;
	else if (username == cashierID && password == cashierPassword){
		return 2;
	}
	else
		return 3;
}

void insertProduct(){
	int productId,itemsOfProduct,costPerItem;
	product pro;

	//product one
	//---------------------------------------------
	cout<<"Pleas enter product one name : ";
	cin>>productId;
	cout<<"\nPlease enter how many items of product "<<productId<<" exist : ";
	cin>>itemsOfProduct;
	cout<<"\nPlease enter the cost of each item of product "<<productId<<" : ";
	cin>>costPerItem;
	pro.productId = productId;
	pro.itemsOfProduct = itemsOfProduct;
	pro.costPerItem = costPerItem;
	products.push_back(pro);

	// product two
	//--------------------------------------
	cout<<"Pleas enter product two name : ";
	cin>>productId;
	cout<<"\nPlease enter how many items of product "<<productId<<" exist : ";
	cin>>itemsOfProduct;
	cout<<"\nPlease enter the cost of each item of product "<<productId<<" : ";
	cin>>costPerItem;
	pro.productId = productId;
	pro.itemsOfProduct = itemsOfProduct;
	pro.costPerItem = costPerItem;
	products.push_back(pro);
}

void displayItems(){
	cout<<"Product : " << products[0].productId <<" : "<<products[0].itemsOfProduct<<endl;
	cout<<"Product : " << products[1].productId <<" : "<<products[1].itemsOfProduct<<endl;
}

void displayProfit(){
	cout<<"Profit : "<<profit<<endl;
}

int LoginAgain(){
	int option;
	cout<<"lease select an action:";
    cout<<"\n1-Login.";
    cout<<"\n2-Terminate the program.";
    cin>>option;
    switch (option) {
		case 1:
			return 1;
			break;
		case 2:
			exit(0);
			break;
		default:
			break;
	}
    return 0;
}

int adminInstruction(){
	int option;
	cout<<"Please select an action\n";
	cout<<"1-Insert products’ details.\n";
	cout<<"2-Display how many items of each product are remaining.\n";
	cout<<"3-Display profit.\n";
	cout<<"4-Log out.\n";
	cin>>option;
	return option;
}

void adminAction(){
	int option = adminInstruction();
	while(option){
	if(option == 1){
		insertProduct();
	}
	if(option == 2){
		displayItems();
	}
	if(option == 3){
		displayProfit();
	}
	if(option == 4){
		LoginAgain();
		break;
	}
	option = adminInstruction();
}
}

void checkOutItems(){
	int amount;

	// product one
	cout<<"Please enter how many items of product "<<products[0].productId<<" would you like to check out\n";
	cin>>amount;
	if(amount <= products[0].itemsOfProduct){
		products[0].itemsOfProduct -= amount;
		profit += (amount *products[0].costPerItem);
	}
	else{
		cout<<"Sorry, we don’t have enough items of product"<<products[0].productId<<" to check out.\n";
	}

	// product two
	cout<<"Please enter how many items of product "<<products[1].productId<<" would you like to check out\n";
	cin>>amount;
	if(amount <= products[1].itemsOfProduct){
		products[1].itemsOfProduct -= amount;
		profit += (amount *products[1].costPerItem);
	}
	else{
		cout<<"Sorry, we don’t have enough items of product"<<products[1].productId<<" to check out.\n";
	}
}

int cashierInstruction(){
	int option;
	cout<<"Please select an action:\n";
	cout<< "1-Check out items.\n";
	cout<<" 4-Log out.\n";
	cin>>option;
	return option;
}

void cashierAction(){
	int option = cashierInstruction();
	while(option){
		if(option == 1){
			checkOutItems();
		}
		if(option == 4){
			LoginAgain();
			break;
		}
		option = cashierInstruction();
	}
}

int main() {

	userType = Login();
	while(true){

	if(userType ==1 ){
		adminAction();
	}
	if(userType==2){
		cashierAction();
	}
	if(userType ==3){
		cout<<"Invaild Username or Password\n";
		return 0;
	}
	userType = Login();
}

}
