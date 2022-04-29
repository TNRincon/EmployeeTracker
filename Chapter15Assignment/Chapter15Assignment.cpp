// Tanis Rincon
// April 24, 2022 ©
// Chapter 15 Programming Challenges 1, 2, & 3

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Employee
{
private:
	string name;		// Employee name
	string number;		// Employee number
	string hireDate;	// Hire date

public:
	// Default constructor
	Employee()
	{
		name = ""; number = ""; hireDate = "";
	}

	// Constructor
	Employee(string aName, string aNumber, string aDate)
	{
		name = aName; number = aNumber; hireDate = aDate;
	}

	// Mutators
	void setName(string n)
	{
		name = n;
	}

	void setNumber(string num)
	{
		number = num;
	}

	void setHireDate(string date)
	{
		hireDate = date;
	}

	// Accessors
	string getName() const
	{
		return name;
	}

	string getNumber() const
	{
		return number;
	}

	string getHireDate() const
	{
		return hireDate;
	}
};


// Specification for the ProductionWorker Class

#include <string>
using namespace std;

class ProductionWorker : public Employee
{
private:
	int shift;	// The worker's shift
	double payRate;	// The worker's hourly pay rate

public:
	// Default constructor
	ProductionWorker() : Employee()
	{
		shift = 0; payRate = 0.0;
	}

	// Constructor
	ProductionWorker(string aName, string aNumber, string aDate,
		int aShift, double aPayRate) : Employee(aName, aNumber, aDate)
	{
		shift = aShift;
		payRate = aPayRate;
	}

	// Mutators
	void setShift(int s)
	{
		shift = s;
	}

	void setPayRate(double r)
	{
		payRate = r;
	}

	// Accessors
	int getShiftNumber() const
	{
		return shift;
	}

	string getShiftName() const
	{
		if (shift == 1)
			return "Day";
		else if (shift == 2)
			return "Night";
		else
			return "Invalid";
	}
	double getPayRate() const
	{
		return payRate;
	}
};

const double TRAIN_BONUS = 500.0;
const double TRAIN_GOAL = 30.0;

class TeamLeader : public ProductionWorker
{
private:
	double monthlyBonus; // team leader's monthly bonus
	double trainingHrs; // team leader's training hours
public:
	// Default constructor
	TeamLeader() : ProductionWorker()
	{
		monthlyBonus = 0.0;
		trainingHrs = 0.0;
	}

	// Constructor
	TeamLeader(string aName, string aNumber, string aDate, int aShift, double aPayRate,
		double bonus, double training) : ProductionWorker(aName, aNumber, aDate, aShift, aPayRate)
	{
		monthlyBonus = bonus;
		trainingHrs = training;
	}

	// mutators
	void setMonthlyBonus(double b)
	{
		monthlyBonus = b;
	}
	void setTraining(double t)
	{
		trainingHrs = t;
	}

	// accessors
	double getMonthlyBonus() const
	{
		return monthlyBonus;
	}
	double getTraining() const
	{
		return trainingHrs;
	}
};

const double PROD_GOAL = 50000.0;
const double GOAL_BONUS = 2000.0;


class ShiftSupervisor : public Employee
{
private:
	double baseSalary;
	double yearlyBonus;

public:
	// Default Constructor
	ShiftSupervisor() : Employee()
	{
		baseSalary = 0.0;
		yearlyBonus = 0.0;
	}

	// Constructor
	ShiftSupervisor(string name, string number, string hireDate,
		double salary, double bonus) : Employee(name, number, hireDate)
	{
		baseSalary = salary;
		yearlyBonus = bonus;
	}

	// Mutators
	void setBaseSalary(double salary)
	{
		baseSalary = salary;
	}

	void setYearlyBonus(double bonus)
	{
		yearlyBonus = bonus;
	}

	void setTotalPayout()
	{
		yearlyBonus + baseSalary;
	}

	// Accessors
	double getBaseSalary() const
	{
		return baseSalary;
	}

	double getYearlyBonus() const
	{

		return yearlyBonus;
	}

	double getTotalPayout() const
	{
		return baseSalary + yearlyBonus;
	}
};

// Function prototypes
void displayWorker(ProductionWorker);
bool isProductionMet(const int& goal);
void displaySupervisor(ShiftSupervisor& s, double goal);
bool isTrainingMet(const int& train);
void displayTeamLeader(TeamLeader& t, double train);

int main()
{
	double goal;
	double train;
	cout << "Production goal is $50,000.\nTeam Leader training hours goal: 30.\n";
	cout << "Please enter production total then training hours attended: ";
	cin >> goal >> train;
	cin.ignore();
	cout << endl;

	ProductionWorker pw("John Jones", "123", "10/12/2010", 2, 18.00);
	displayWorker(pw);

	ShiftSupervisor ss("Samantha Smith", "447", "02/28/2009", 50000, GOAL_BONUS);
	displaySupervisor(ss, goal);

	TeamLeader tl("Zachary Phillips", "234", "05/01/2004", 1, 25.00, TRAIN_BONUS, train);
	displayTeamLeader(tl, train);


	return 0;
}

//Displays info for the ProductionWorker class
void displayWorker(ProductionWorker w)
{
	cout << setprecision(2) << fixed << showpoint;
	cout << "Name: "
		<< w.getName() << endl;
	cout << "Employee number: "
		<< w.getNumber() << endl;
	cout << "Hire date: "
		<< w.getHireDate() << endl;
	cout << "Shift: "
		<< w.getShiftName() << endl;
	cout << "Shift number: "
		<< w.getShiftNumber() << endl;
	cout << "Pay rate: "
		<< w.getPayRate() << endl << endl;
}
bool isProductionMet(const int& goal)
{
	bool proMet = false;
	if (goal >= PROD_GOAL)
	{
		proMet = true;
	}
	return proMet;
}

void displaySupervisor(ShiftSupervisor& s, double goal)
{

	if (isProductionMet(goal) == true)
	{
		s.setYearlyBonus(GOAL_BONUS);
		s.setTotalPayout();
	}
	else
	{
		s.setYearlyBonus(0.0);
	}

	cout << setprecision(2) << fixed << showpoint;
	cout << "Name: "
		<< s.getName() << endl;
	cout << "Employee number: "
		<< s.getNumber() << endl;
	cout << "Hire date: "
		<< s.getHireDate() << endl;
	cout << "Base Salary: "
		<< s.getBaseSalary() << endl;
	cout << "Yearly Bonus: "
		<< s.getYearlyBonus() << endl;
	cout << "Total Payout: "
		<< s.getTotalPayout() << endl << endl;
}

bool isTrainingMet(const int& train)
{
	bool trainMet = false;
	if (train >= TRAIN_GOAL)
	{
		trainMet = true;
	}
	return trainMet;
}

void displayTeamLeader(TeamLeader& t, double train)
{
	if (isTrainingMet(train) == true)
	{
		t.setMonthlyBonus(TRAIN_BONUS);
	}
	else
	{
		t.setMonthlyBonus(0.0);
	}

	cout << setprecision(2) << fixed << showpoint;
	cout << "Name: "
		<< t.getName() << endl;
	cout << "Employee number: "
		<< t.getNumber() << endl;
	cout << "Hire date: "
		<< t.getHireDate() << endl;
	cout << "Shift: "
		<< t.getShiftName() << endl;
	cout << "Shift number: "
		<< t.getShiftNumber() << endl;
	cout << "Pay rate: "
		<< t.getPayRate() << endl;
	cout << "This Month's Bonus: "
		<< t.getMonthlyBonus() << endl;
	cout << "Training Hours attended: "
		<< t.getTraining() << endl << endl;
}