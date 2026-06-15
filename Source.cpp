// Urban Ease console base software for Analysis and management of the Stores spread across the entire nation
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include<iomanip>
using namespace std;

//task 01 starts from here
// person class the base class
class person {
private:
	string name;
	string id;
	int age;

public:
	//constructor for this class
	person()
	{
		name = "";
		id = "";
		age = 0;
	}
	person(string n, string iD, int a)
	{
		name = n;
		id = iD;
		age = a;
	}
	//getters and setters for the class
	// name
	void setName(string n)
	{
		name = n;
	}
	string getName()
	{
		return name;
	}
	// id
	void setId(string iD)
	{
		id = iD;
	}
	string getId()
	{
		return id;
	}
	// age
	void setAge(int a)
	{
		age = a;
	}
	int getAge()
	{
		return age;
	}

	//dispaly function of the class to show the data
	void show()
	{
		cout << "Name : " << name << endl;
		cout << "ID : " << id << endl;
		cout << "Age : " << age << endl;
	}

	//destructor for this class
	~person()
	{
		// simple blank destructor
	}
};

//employee class derived from person
class employee : public person {
private:
	int salary;
	double workhrs;
public:
	// constructors 
	employee()
	{
		salary = 0;
		workhrs = 0;
	}
	employee(string n, string iD, int a, int s, double whrs) : person(n, iD, a)
	{
		salary = s;
		workhrs = whrs;
	}

	// copy constructor
	employee(const employee& emp) : person(emp)
	{
		salary = emp.salary;
		workhrs = emp.workhrs;
	}

	// getters and setters for the employee class
	//salary
	void setSalary(int s)
	{
		salary = s;
	}
	int getSalary()
	{
		return salary;
	}
	// wroking hours
	void setWorkinghours(double whrs)
	{
		workhrs = whrs;
	}
	double getWorkinghours()
	{
		return workhrs;
	}

	// display function for the employee class
	void show()
	{
		person::show();
		cout << "Salary : " << salary << endl;
		cout << "Working Hours : " << workhrs << endl;
	}

	//destructor
	~employee()
	{
		//leaving it blank :)))
	}

	//operator overloading
	employee& operator=(const employee& emp)
	{
		if (this != &emp)
		{
			person::operator=(emp);
			salary = emp.salary;
			workhrs = emp.workhrs;
		}
		return *this;
	}
};

//manager class derived from employee
class manager : public employee {
private:
	string department;
	int bonus;
public:
	//constructors
	manager()
	{
		department = "";
		bonus = 0;
	}
	manager(string n, string iD, int a, int s, double whrs, string depart, int b) : employee(n, iD, a, s, whrs)
	{
		department = depart;
		bonus = b;
	}

	// setters and getters for the manager class
	//departent
	void setDepartment(string depart)
	{
		department = depart;
	}
	string getDepartment() const
	{
		return department;
	}
	// bonus
	void setBonus(int b)
	{
		bonus = b;
	}
	int getBonus() const
	{
		return bonus;
	}

	//show function to show the information in the manager class
	void show()
	{
		//person::show();
		employee::show();
		cout << "Department : " << department << endl;
		cout << "Bonus : " << bonus << endl;
	}

	//destructor for the manager class
	~manager()
	{
		//just a destructor :))
	}
};

//coordinates class
class coordinates {
private:
	double longitude;
	double latitude;

public:

	//constructors
	coordinates()
	{
		latitude = 0.0;
		longitude = 0.0;
		
	}
	coordinates(double lat, double longi )
	{
		latitude = lat;
		longitude = longi;
		
	}

	// setters and getters for the coordinates class
	
	// latitude
	void setLat(double lat)
	{
		latitude = lat;
	}
	double getLat()
	{
		return latitude;
	}

	// longitude
	void setLong(double longi)
	{
		longitude = longi;
	}
	double getLong()
	{
		return longitude;
	}


	// display function to show the information in the class
	void show()
	{
		cout << "Longitude : " << longitude << endl;
		cout << "Latitude : " << latitude << endl;
		
	}

	//destructor
	~coordinates()
	{
		
	}
};

//analytics class
class analytics {
private:
	double* sales;		//monyhly
	double* costs;		//monthly
	int* customers;		//monthly
	int months;			//monthly

public:
	//constructor
	analytics(int month = 24)
	{
		months = month;
		sales = new double[months];
		costs = new double[months];
		customers = new int[months];

		for (int i = 0; i < months; i++)
		{
			sales[i] = 0.0;
			costs[i] = 0.0;
			customers[i] = 0;
		}
	}
	analytics(double* sale, double* cost, int* customer, int month)
	{
		months = month;
		sales = new double[months];
		costs = new double[months];
		customers = new int[months];

		for (int i = 0; i < months; i++)
		{
			sales[i] = sale[i];
			costs[i] = cost[i];
			customers[i] = customer[i];
		}
	}
	//deep copy of the data
	analytics(const analytics& als)
	{
		months = als.months;
		sales = new double[months];
		costs = new double[months];
		customers = new int[months];

		for (int i = 0; i < months; i++)
		{
			sales[i] = als.sales[i];
			costs[i] = als.costs[i];
			customers[i] = als.customers[i];
		}
	}

	//destructor
	~analytics()
	{
		delete[] sales;
		delete[] costs;
		delete[] customers;

		sales = nullptr;
		costs = nullptr;
		customers = nullptr;
	}


	//setters and getters for the analytics class
	// sales
	void setSales(int month, double sale)
	{
		if (month >= 0 && month < months)
		{
			sales[month] = sale;
		}
	}
	double getSales(int month) const
	{
		if (month >= 0 && month < months)
		{
			return sales[month];
		}
		else
		{
			return 0.0;
		}
	}

	//costs
	void setCosts(int month, double cost)
	{
		if (month >= 0 && month < months)
		{
			costs[month] = cost;
		}
	}
	double getCost(int month) const
	{
		if (month >= 0 && month < months)
		{
			return costs[month];
		}
		else
		{
			return 0.0;
		}
	}

	//customers
	void setCustomer(int month, int customer)
	{
		if (month >= 0 && month < months)
		{
			customers[month] = customer;
		}
	}
	int getCustomer(int month) const
	{
		if (month >= 0 && month < months)
		{
			return customers[month];
		}
		else
		{
			return 0;
		}
	}

	//total sales
	double getTotalSales() const
	{
		double total = 0.0;
		for (int i = 0; i < months; i++)
		{
			total += sales[i];
		}
		return total;
	}

	//total cost
	double getTotalCosts() const
	{
		double total = 0.0;
		for (int i = 0; i < months; i++)
		{
			total += costs[i];
		}
		return total;
	}

	//profits
	double getProfit() const
	{
		return 	getTotalSales() - getTotalCosts();
	}

	// growth over the year
	double getGrowth() const
	{
		double total = 0.0;
		int count = 0; 

		for (int i = 13; i < months ; i++)
		{
			double growth = sales[i] - sales[i - 1];
			total += growth;
			count++;
		}
		if (count == 0)
		{
			return 0;
		}

		return total / count;
	}

	//comparing the Stores using the operator overloading
	double compareStore()const
	{
		double totalsale = getTotalSales();
		double totalprofit = getProfit();
		double avgGrowth = getGrowth();

		return totalsale + totalprofit + avgGrowth;
	}


	// operator overloading
	// accessing the monthly sales with particular index of the requirement
	double& operator[] (int index)
	{
		if (index >= 0 && index < months)
		{
			return sales[index];
		}
		else
		{
			return sales[0];
		}
	}
	// combining the analytics of the number stores say Store A + Store B (analytics)
	analytics operator + (analytics& als)
	{
		analytics result(months);
		for (int i = 0; i < months; i++)
		{
			//adding the sales of 2 stores
			result.sales[i] = sales[i] + als.sales[i];

			//adding the number of customers of 2 stores
			result.customers[i] = customers[i] + als.customers[i];

			//ading the costs of 2 stores
			result.costs[i] = costs[i] + als.costs[i];
		}
		return result;
	}
	// comparison opertors
	bool operator > (const analytics& als) const
	{
		return compareStore() > als.compareStore();
	}
	bool operator < (const analytics& als) const
	{
		return compareStore() < als.compareStore();
	}
	bool operator == (const analytics& als)
	{
		return compareStore() == als.compareStore();
	}

	// cout operator
	friend ostream& operator << (ostream& out,const analytics &a)
	{
		out << endl;
		out << "Total Sales    : " << a.getTotalSales() << endl;
		out << "Total Cost     : " << a.getTotalCosts() << endl;
		out << "Total Profit   : " << a.getProfit() << endl;
		out << "Average Growth : " << a.getGrowth() << endl;

		return out;
	}

	analytics& operator=(const analytics& als)
	{
		
		if (this != &als)
		{
			
			delete[] sales;
			delete[] costs;
			delete[] customers;

			months = als.months;
			sales = new double[months];
			costs = new double[months];
			customers = new int[months];

			for (int i = 0; i < months; i++)
			{
				sales[i] = als.sales[i];
				costs[i] = als.costs[i];
				customers[i] = als.customers[i];
			}
		}
		return *this;
	}
};

//store class
class store {
private:	
	string Name;
	string Id;
	coordinates location;
	analytics analytic;
	manager man;
	employee** emp;
	int staff;

public:

	//constructor
	store()
	{
		Name = "";
		Id = "";
		location = coordinates();
		analytic = analytics();
		man = manager();
		staff = 0;
		emp = nullptr; 
	}
	store(string n, string id, coordinates loc, analytics a, manager mgr, int stf, employee** e)
	{
		Name = n;
		Id = id;
		location = loc; 
		analytic = a;
		man = mgr;
		staff = stf;
		emp = new employee * [staff];
		for (int i = 0; i < staff; i++)
		{
			emp[i] = new employee(*e[i]);
		}
	}
	//deep copy
	store(const store& st)
	{
		Name = st.Name;
		Id = st.Id;
		location = st.location;
		analytic = st.analytic;
		man = st.man;
		staff = st.staff;
		emp = new employee * [staff];
		for (int i = 0; i < staff; i++)
		{
			emp[i] = new employee(*st.emp[i]);
		}
	}
	//destructor
	~store()
	{
		for (int i = 0; i < staff; i++)
		{
			delete emp[i];
			emp[i] = nullptr;
		}
		delete[] emp;
		emp = nullptr;
	}

	//setters and getters for store class
	//name
	void setName(string name)
	{
		Name = name;
	}
	string getName()const
	{
		return Name;
	}

	//id
	void setId(string id)
	{
		Id = id;
	}
	string getId()const
	{
		return Id;
	}

	//coordinates
	void setLocation(coordinates loc)
	{
		location = loc;
	}
	coordinates getLocation()const
	{
		return location;
	}

	//manager
	void setManager(manager mgr)
	{
		man = mgr;
	}
	manager getManager()const
	{
		return man;
	}

	//staffcount
	void setStaffCount(int stf)
	{
		staff = stf;
	}
	int getStaffCount()const
	{
		return staff;
	}

	//employee staff
	void setStaff(int index, employee* e)
	{
		if (index >= 0 && index < staff)
		{
			if (emp[index] != nullptr)
			{
				delete emp[index];
				emp[index] = nullptr;
			}
			emp[index] = e;
		}
	}
	employee* getStaff(int index)const
	{
		if (index >= 0 && index < staff)
		{
			return emp[index];
		}
		else
		{
			return nullptr;
		}
	}

	//analytics
	void setAnalytics(analytics a)
	{
		analytic = a;
	}
	analytics getAnalytics()const
	{
		return analytic;
	}


	//operator overloading
	bool operator==(const store& s) const
	{
		return Id == s.Id;
	}

	store& operator=(const store& s) 
	{
		if (this != &s)
		{
			Name = s.Name;
			Id = s.Id;
			location = s.location;
			analytic = s.analytic;
			man = s.man;
			
			for (int i = 0; i < staff; i++)
			{
				delete emp[i];
			}
			delete[] emp;

			staff = s.staff;
			emp = new employee *[staff];
			for (int i = 0; i < staff; i++)
			{
				emp[i] = new employee(*s.emp[i]);
			}
		}
		return *this;
	}

	friend ostream& operator << (ostream& out, store s)
	{
		out << "Store ID    : " << s.Id << endl;
		out << "Store Name  : " << s.Name << endl;
		out << "Latitude    : " << s.location.getLat() << endl;
		out << "Longitude   : " << s.location.getLong() << endl;
		out << "Manager     : " << s.man.getName() << endl;
		out << "Staff Count : " << s.staff << endl;
		out << "Analytics   : " << s.analytic << endl;
		return out;
	}

	//function calling from analytics class for further usage in the code
	double getTotalRevenue() const
	{
		return analytic.getTotalSales();
	}

	double getTotalProfit() const
	{
		return analytic.getProfit();
	}

	double getComparison() const
	{
		return analytic.compareStore();
	}


	// Now the save and load file functions are being made which will be required in task 0 as well 
	// so these functions will store the data of each of the store as per the intended needs and requirements

	//save to file function
	void safeTofile(ofstream& output) 
	{
		output << Name << endl;
		output << Id << endl;
		
		output << location.getLat() << endl;
		output << location.getLong() << endl;
	

		for (int i = 0; i < 24; i++)
		{
			output << analytic.getSales(i) << " " << analytic.getCost(i) << " " << analytic.getCustomer(i) << endl;
		}

		output << man.getName() << endl;
		output << man.getId() << endl;
		output << man.getAge() << endl;
		output << man.getSalary() << endl;
		output << man.getDepartment() << endl;
		output << man.getBonus() << endl;
		
		output << staff << endl;

		for (int i = 0; i < staff; i++)
		{
			if (emp[i] != nullptr)
			{
				output << emp[i]->getName() << endl;
				output << emp[i]->getId() << endl;
				output << emp[i]->getAge() << endl;
				output << emp[i]->getSalary() << endl;
			}
		}
	}
	
	//load from file function which shows the data of the stores and thier analytics and stats etc
	void LoadFile(ifstream& input)
	{
			
			getline(input, Name);
			getline(input, Id);

			double lat, longi;
			string city;
			input >> lat >> longi;
			input.ignore();
			getline(input, city);
			location.setLat(lat);
			location.setLong(longi);
			

			for (int i = 0; i < 24; i++)
			{
				double sale, cost;
				int    customer;
				input >> sale >> cost >> customer;
				analytic.setSales(i, sale);
				analytic.setCosts(i, cost);
				analytic.setCustomer(i, customer);
			}
			input.ignore();

			string mgrName, mgrId, mgrDept;
			int    mgrAge, mgrHours;
			double mgrSalary, mgrBonus;

			getline(input, mgrName);
			getline(input, mgrId);
			input >> mgrAge >> mgrSalary;
			input.ignore();
			getline(input, mgrDept);
			input >> mgrBonus >> mgrHours;
			input.ignore();

			man = manager(mgrName, mgrId, mgrAge,
				mgrSalary, mgrHours,
				mgrDept, mgrBonus);

			for (int i = 0; i < staff; i++)
			{
				if (emp[i] != nullptr)
				{
					delete emp[i];
					emp[i] = nullptr;
				}
			}
			delete[] emp;
			emp = nullptr;

			input >> staff;
			input.ignore();

			emp = new employee * [staff];
			for (int i = 0; i < staff; i++)
			{
				string empName, empId;
				int    empAge, empHours;
				double empSalary;

				getline(input, empName);
				getline(input, empId);
				input >> empAge >> empSalary >> empHours;
				input.ignore();

				emp[i] = new employee(empName, empId,
					empAge,
					empSalary, empHours);
			}
		

	}
};


//task 0 starts from here
// showing the date that has been stored
ofstream& operator<<(ofstream& out, store& s) 
{
	s.safeTofile(out);
	return out;
}
// getting the data
ifstream& operator>>(ifstream& in, store& s) 
{
	s.LoadFile(in);
	return in;
}

store* loadExistingData(int& storeCount, const string& filename) 
{
	ifstream in(filename);
	in >> storeCount;
	in.ignore();

	store* stores = new store[storeCount];

	for (int i = 0; i < storeCount; i++) 
	{
		in >> stores[i];
	}

	in.close();
	cout << storeCount << " stores successfully loaded from " << filename << endl;
	return stores;
}

store* generateNewDataset(int& storeCount, const string& filename)
{
	cout << "Enter the total number of stores to generate (Minimum 100): ";
	storeCount = 0;

	while (storeCount < 100)
	{
		cin >> storeCount;
		if (storeCount < 100)
		{
			cout << "Error: Minimum 100 stores required. Please enter again: ";
		}
	}
	
	// for stores
	store* stores = new store[storeCount];

	for (int i = 0; i < storeCount; i++)
	{
		string sName = "UrbanEase : " + to_string(i + 1);
		string sId = "UE" + to_string(i + 1);

		double lat = 24.0 + (rand() % 1300) / 100.0;
		double longi = 61.0 + (rand() % 1500) / 100.0;

		coordinates loc(lat, longi);

		double* salesArr = new double[24];
		double* costsArr = new double[24];
		int* custArr = new int[24];

		for (int m = 0; m < 24; m++)
		{
			salesArr[m] = 10000.0 + (rand() % 40000);
			costsArr[m] = 5000.0 + (rand() % 20000);
			custArr[m] = 500 + (rand() % 1500);
		}

		analytics a(salesArr, costsArr, custArr, 24);

		delete[] salesArr;
		delete[] costsArr;
		delete[] custArr;

		// for the manager
		string mName = "Manager : " + to_string(i + 1);
		string mId = "M" + to_string(i + 1);
		int mAge = 30 + (rand() % 20);
		int mSalary = 50000 + (rand() % 30000);
		double mHours = 40.0 + (rand() % 10);
		int mBonus = 5000 + (rand() % 10000);

		manager mgr(mName, mId, mAge, mSalary, mHours, "Retail", mBonus);

		// generating staff members
		int staffSize = 5 + (rand() % 16);
		employee** empList = new employee * [staffSize];

		for (int j = 0; j < staffSize; j++)
		{
			string eName = "Emp : " + to_string(i + 1) + " : " + to_string(j + 1);
			string eId = "E" + to_string(i + 1) + " : " + to_string(j + 1);
			int eAge = 18 + (rand() % 15);
			int eSalary = 20000 + (rand() % 15000);
			double eHours = 35.0 + (rand() % 15);

			empList[j] = new employee(eName, eId, eAge, eSalary, eHours);
		}

		stores[i] = store(sName, sId, loc, a, mgr, staffSize, empList);

		for (int j = 0; j < staffSize; j++)
		{
			delete empList[j];
		}
		delete[] empList;
	}

	ofstream out(filename);
	out << storeCount << endl;

	for (int i = 0; i < storeCount; i++)
	{
		out << stores[i];
	}

	out.close();

	cout << storeCount << " stores successfully generated and saved to " << filename << endl;

	return stores;
}

store* startupMenu(int& storeCount) {
	int choice = 0;
	string filename = "stores.txt";

	cout << "=== UrbanEase Startup Menu ===" << endl;
	cout << "1. Load Existing Data" << endl;
	cout << "2. Generate New Dataset" << endl;
	cout << "Select an option: ";
	cin >> choice;

	if (choice == 1) 
	{
		ifstream checkFile(filename);
		if (checkFile.is_open()) 
		{
			checkFile.close();
			return loadExistingData(storeCount, filename);
		}
		else 
		{
			cout << "Warning: Data file not found. Falling back to Option 1 ..." << endl;
			return generateNewDataset(storeCount, filename);
		}
	}
	else 
	{
		return generateNewDataset(storeCount, filename);
	}
}

// task 03 starts form here
void displayMenu() {
	cout << endl;
	cout << "=== UrbanEase Management System ===" << endl;
	cout << "1. Display All Stores" << endl;
	cout << "2. Search Store by ID" << endl;
	cout << "3. Show Top Performing Store" << endl;
	cout << "4. Calculate Total Company Profit" << endl;
	cout << "5. Exit" << endl;
	cout << "Selection: ";
}
// does all of the sorting as required
void runManagementSystem(store* stores, int totalStores) {
	int choice = 0;
	while (true) {
		displayMenu();
		cin >> choice;

		if (choice == 5)
		{
			break;
		}

		// use switches to choose and show the options fully
		switch (choice) 
		{
		case 1:
			for (int i = 0; i < totalStores; i++) 
			{
				cout << stores[i] << endl;
			}
			break;
		case 2: 
		{
			string id;
			cout << "Enter Store ID: ";
			cin >> id;
			bool found = false;
			for (int i = 0; i < totalStores; i++) 
			{
				if (stores[i].getId() == id) {
					cout << stores[i] << endl;
					found = true;
					break;
				}
			}
			if (!found) cout << "Store not found." << endl;
			break;
		}
		case 3: 
		{
			int bestIndex = 0;

			for (int i = 1; i < totalStores; i++) 
			{
				if (stores[i].getAnalytics() > stores[bestIndex].getAnalytics()) 
				{
					bestIndex = i;
				}
			}
			cout << "Top Performing Store:\n" << stores[bestIndex] << endl;
			break;
		}
		case 4: 
		{
			double totalProfit = 0;
			for (int i = 0; i < totalStores; i++) 
			{
				totalProfit += stores[i].getTotalProfit();
			}
			cout << "Total Company Profit: $" << totalProfit << endl;
			break;
		}
		default:
			cout << "Invalid selection." << endl;
		}
	}
}

//main function of the code
int main() {
	srand(time(0));

	int totalStores = 0;
	store* urbanEaseStores = startupMenu(totalStores);

	cout << endl;
	cout << "Displaying data for the First Store :  " << endl;

	if (totalStores > 0) 
	{
		cout << urbanEaseStores[0] << endl;
		runManagementSystem(urbanEaseStores, totalStores);
	}

	delete[] urbanEaseStores;
	urbanEaseStores = nullptr;

	return 0;
}


