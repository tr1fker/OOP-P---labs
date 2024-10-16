#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>
#include <iomanip>

using namespace std;

static const int LEN = 25;

int press_any_character() {
	cout << "Press any key to continue..." << endl;
	int key = _getche();
	return 0;
}

int input_integer(string condition, int min_limit, int max_limit) {
	int number;
	system("cls");
	cout << condition;
	cin >> number;
	flush(cout);
	if (cin.good()) {
		cin.clear();
		if (min_limit <= number && max_limit >= number)
			return number;
	}
	else if (cin.eof()) {
		cout << "End of file reached.\n";
		press_any_character();
		return 0;
	}
	else if (cin.fail()) {
		cout << "Input error. Please try again.\n";
		cin.clear();
		cin.ignore(100, '\n');
		press_any_character();
		return -1;
	}
	else if (cin.bad()) {
		cout << "Critical error. Program completed.\n";
		press_any_character();
		exit(1);
	}
	cin.clear();
	cin.ignore(100, '\n');
	return -1;
}

string input_string(string condition) {
	string line;
	system("cls");
	cout << condition;
	cin >> line;
	if (cin.good()) {
		cin.clear();
		return line;
	}

	return "NULL";
}

int input_integer(string condition, int min_limit) {
	return input_integer(condition, min_limit, MAXINT32);
}

int input_integer(string condition) {
	return input_integer(condition, MININT32, MAXINT32);
}

class Employee {
	string surname, name, patronymic, type;
	int age, experience;
public:
	Employee();
	void Employee2(int);
	Employee(string surname, string name, string patronymic, string type, int age, int experience);
	virtual int viewing() const;
	virtual int editing();
	const string getSurname() const;
	const string getName() const;
	const string getPatronymic() const;
	const string getType() const;
	const int getAge() const;
	const int getExperience() const;
	int setSurname(string new_surname);
	int setName(string new_name);
	int setPatronymic(string new_patronymic);
	int setType(string new_type);
	int setAge(int new_age);
	int setExperience(int new_experience);
};

Employee::Employee() :
	surname("No surname"), name("No name"), patronymic("No patronymic"),
	age(0), experience(0), type("Employee") {}

void Employee::Employee2(int) {
	while ((this->surname = input_string("Enter surname:")) == "NULL") {
		cout << "Incorrect value!" << endl;
		press_any_character();
	}
	while ((this->name = input_string("Enter name:")) == "NULL") {
		cout << "Incorrect value!" << endl;
		press_any_character();
	}
	while ((this->patronymic = input_string("Enter patronymic:")) == "NULL") {
		cout << "Incorrect value!" << endl;
		press_any_character();
	}
	while ((this->age = input_integer("Enter age:", 1)) == -1) {
		cout << "Incorrect value!" << endl;
		press_any_character();
	}
	while ((this->experience = input_integer("Enter experience:", 0)) == -1) {
		cout << "Incorrect value!" << endl;
		press_any_character();
	}
}

Employee::Employee(string surname, string name, string patronymic, string type, int age, int experience) :
	surname(surname), name(name), patronymic(patronymic), type(type), age(age), experience(experience) {}

int Employee::viewing() const {
	cout.setf(ios::left | ios::fixed);
	cout << setw(LEN) << setfill(' ') << "Surname:" << this->surname << endl
		<< setw(LEN) << setfill(' ') << "Name:" << this->name << endl
		<< setw(LEN) << setfill(' ') << "Patronymic:" << this->patronymic << endl
		<< setw(LEN) << setfill(' ') << "Age:" << this->age << endl
		<< setw(LEN) << setfill(' ') << "Experience:" << this->experience << endl;
	cout.unsetf(ios::left | ios::fixed);
	return 0;
}

static const string CONDITION_PERSONAL_EMPLOYEE = "\
+----------------------+\n\
|         Edit         |\n\
+----------------------+\n\
|  Personal properties |\n\
|    of a employee     |\n\
+----------------------+\n\
|1. Surname            |\n\
|2. Name               |\n\
|3. Patronymic         |\n\
|4. Age                |\n\
|5. Experience         |\n\
+----------------------+\n\
|6. Exit               |\n\
+----------------------+\n\
Enter value:";

int Employee::editing() {
	bool editing = true;
	while (editing) {
		int choice = input_integer(CONDITION_PERSONAL_EMPLOYEE, 1, 6);
		if (choice == -1) {
			editing = false;
			break;
		}
		switch (choice) {
		case 1:
			while ((this->surname = input_string("Enter surname:")) == "NULL") {
				cout << "Incorrect value!" << endl;
				press_any_character();
			}
			break;
		case 2:
			while ((this->name = input_string("Enter name:")) == "NULL") {
				cout << "Incorrect value!" << endl;
				press_any_character();
			}
			break;
		case 3:
			while ((this->patronymic = input_string("Enter patronymic:")) == "NULL") {
				cout << "Incorrect value!" << endl;
				press_any_character();
			}
			break;
		case 4:
			while ((this->age = input_integer("Enter age:", 1)) == -1) {
				cout << "Incorrect value!" << endl;
				press_any_character();
			}
			break;
		case 5:
			while ((this->experience = input_integer("Enter experience:", 1)) == -1) {
				cout << "Incorrect value!" << endl;
				press_any_character();
			}
			break;
		case 6:
			editing = false;
			cout << "Successful exit!" << endl;
			press_any_character();
			break;
		}
	}
	return 0;
}

const string Employee::getSurname() const {
	return this->surname;
}

const string Employee::getName() const {
	return this->name;
}

const string Employee::getPatronymic() const {
	return this->patronymic;
}

const string Employee::getType() const {
	return this->type;
}

const int Employee::getAge() const {
	return this->age;
}

const int Employee::getExperience() const {
	return this->experience;
}

int Employee::setSurname(string new_surname) {
	this->surname = new_surname;
	return 0;
}

int Employee::setName(string new_name) {
	this->name = new_name;
	return 0;
}

int Employee::setPatronymic(string new_patronymic) {
	this->patronymic = new_patronymic;
	return 0;
}

int Employee::setType(string new_type) {
	this->type = new_type;
	return 0;
}

int Employee::setAge(int new_age) {
	this->age = new_age;
	return 0;
}

int Employee::setExperience(int new_experience) {
	this->experience = new_experience;
	return 0;
}

class Musician : public Employee {
	int number_perfomances;
public:
	Musician();
	Musician(float);
	Musician(int number_perfomances);
	virtual int viewing() const;
	virtual int editing();
};

Musician::Musician() :
	number_perfomances(0) {}

Musician::Musician(float) {
	Musician::Employee2(0);
	Musician::Employee::setType("Musician");
	while ((this->number_perfomances = input_integer("Enter number of perfomances:", 0)) == -1) {
		cout << "Incorrect value!" << endl;
		press_any_character();
	}
}

Musician::Musician(int number_perfomances) :
	number_perfomances(number_perfomances) {}

int Musician::viewing() const {
	cout.setf(ios::left | ios::fixed);
	cout << setw(LEN) << setfill(' ') << "Number of perfomances:" << this->number_perfomances << endl;
	cout.unsetf(ios::left | ios::fixed);
	return Musician::Employee::viewing();
}

static const string CONDITION_PERSONAL_MUSICIAN = "\
+------------------------+\n\
|          Edit          |\n\
+------------------------+\n\
|   Personal properties  |\n\
|      of a musician     |\n\
+------------------------+\n\
|1. Number of perfomances|\n\
+------------------------+\n\
|2. General properties   |\n\
+------------------------+\n\
|3. Exit                 |\n\
+------------------------+\n\
Enter value:";

int Musician::editing() {
	bool editing = true;
	while (editing) {
		int choice = input_integer(CONDITION_PERSONAL_MUSICIAN, 1, 3);
		if (choice == -1) {
			editing = false;
			break;
		}
		switch (choice) {
		case 1:
			while ((this->number_perfomances = input_integer("Enter number of perfomances:", 0)) == -1) {
				cout << "Incorrect value!" << endl;
				press_any_character();
			}
			break;
		case 2:
			Musician::Employee::editing();
			break;
		case 3:
			editing = false;
			cout << "Successful exit!" << endl;
			press_any_character();
			break;
		}
	}
	return 0;
}

class Administrator : public Employee {
	string position;
public:
	Administrator();
	Administrator(int);
	Administrator(string position);
	virtual int viewing() const;
	virtual int editing();
};

Administrator::Administrator() :
	position("No position") {}

Administrator::Administrator(int) {
	Administrator::Employee2(0);
	Administrator::Employee::setType("Administrator");
	while ((this->position = input_string("Enter position:")) == "NULL") {
		cout << "Incorrect value!" << endl;
		press_any_character();
	}
}

Administrator::Administrator(string position) : 
	position(position) {}

int Administrator::viewing() const {
	cout.setf(ios::left | ios::fixed);
	cout << setw(LEN) << setfill(' ') << "Position:" << this->position << endl;
	cout.unsetf(ios::left | ios::fixed);
	return Administrator::Employee::viewing();
}

static const string CONDITION_PERSONAL_ADMINISTRATOR = "\
+----------------------+\n\
|         Edit         |\n\
+----------------------+\n\
|  Personal properties |\n\
|  of a administrator  |\n\
+----------------------+\n\
|1. Position           |\n\
+----------------------+\n\
|2. General properties |\n\
+----------------------+\n\
|3. Exit               |\n\
+----------------------+\n\
Enter value:";

int Administrator::editing() {
	bool editing = true;
	while (editing) {
		int choice = input_integer(CONDITION_PERSONAL_ADMINISTRATOR, 1, 3);
		if (choice == -1) {
			editing = false;
			break;
		}
		switch (choice) {
		case 1:
			while ((this->position = input_string("Enter position:")) == "NULL") {
				cout << "Incorrect value!" << endl;
				press_any_character();
			}
			break;
		case 2:
			Administrator::Employee::editing();
			break;
		case 3:
			editing = false;
			cout << "Successful exit!" << endl;
			press_any_character();
			break;
		}
	}
	return 0;
}

class Vocalist : public Musician {
	string genre, //rock, pop, opera
		voice_genre; //soprano, alt, tenor, bariton
public:
	Vocalist();
	Vocalist(int);
	Vocalist(string genre, string voice_genre);
	virtual int viewing() const;
	virtual int editing();
};

Vocalist::Vocalist() :
	genre("No genre"), voice_genre("No voice genre") {}

Vocalist::Vocalist(int) {
	Vocalist::Employee2(0);
	Vocalist::Employee::setType("Vocalist");
	while ((this->genre = input_string("Enter genre:")) == "NULL") {
		cout << "Incorrect value!" << endl;
		press_any_character();
	}
	while ((this->voice_genre = input_string("Enter voice genre:")) == "NULL") {
		cout << "Incorrect value!" << endl;
		press_any_character();
	}
}

Vocalist::Vocalist(string genre, string voice_genre) :
	genre(genre), voice_genre(voice_genre) {}

int Vocalist::viewing() const {
	cout.setf(ios::left | ios::fixed);
	cout << setw(LEN) << setfill(' ') << "Genre:" << this->genre << endl
		<< setw(LEN) << setfill(' ') << "Voice genre:" << this->voice_genre << endl;
	cout.unsetf(ios::left | ios::fixed);
	return Vocalist::Employee::viewing();
}

static const string CONDITION_PERSONAL_VOCALIST = "\
+---------------------+\n\
|         Edit        |\n\
+---------------------+\n\
| Personal properties |\n\
|    of a vocalist    |\n\
+---------------------+\n\
|1. Genre             |\n\
|2. Voice genre       |\n\
+---------------------+\n\
|3. General properties|\n\
+---------------------+\n\
|4. Exit              |\n\
+---------------------+\n\
Enter value:";

int Vocalist::editing() {
	bool editing = true;
	while (editing) {
		int choice = input_integer(CONDITION_PERSONAL_VOCALIST, 1, 4);
		if (choice == -1) {
			editing = false;
			break;
		}
		switch (choice) {
		case 1:
			while ((this->genre = input_string("Enter genre:")) == "NULL") {
				cout << "Incorrect value!" << endl;
				press_any_character();
			}
			break;
		case 2:
			while ((this->voice_genre = input_string("Enter voice genre:")) == "NULL") {
				cout << "Incorrect value!" << endl;
				press_any_character();
			}
			break;
		case 3:
			Vocalist::Employee::editing();
			break;
		case 4:
			editing = false;
			cout << "Successful exit!" << endl;
			press_any_character();
			break;
		}
	}
	return 0;
}

class Instrumentalist : public Musician {
	string type_instrument;
public:
	Instrumentalist();
	Instrumentalist(int);
	Instrumentalist(string type_instrument);
	virtual int viewing() const;
	virtual int editing();
};

Instrumentalist::Instrumentalist() :
	type_instrument("No type instrument") {}

Instrumentalist::Instrumentalist(int) {
	Instrumentalist::Employee2(0);
	Instrumentalist::Employee::setType("Instrumentalist");
	while ((this->type_instrument = input_string("Enter type of instrument:")) == "NULL") {
		cout << "Incorrect value!" << endl;
		press_any_character();
	}
}

Instrumentalist::Instrumentalist(string type_instrument) :
	type_instrument(type_instrument) {}

int Instrumentalist::viewing() const {
	cout.setf(ios::left | ios::fixed);
	cout << setw(LEN) << setfill(' ') << "Type of instrument:" << this->type_instrument << endl;
	cout.unsetf(ios::left | ios::fixed);
	return Instrumentalist::Employee::viewing();
}

static const string CONDITION_PERSONAL_INSTRUMENTALIST = "\
+----------------------+\n\
|         Edit         |\n\
+----------------------+\n\
|  Personal properties |\n\
| of a instrumentalist |\n\
+----------------------+\n\
|1. Type of instrument |\n\
+----------------------+\n\
|2. General properties |\n\
+----------------------+\n\
|3. Exit               |\n\
+----------------------+\n\
Enter value:";

int Instrumentalist::editing() {
	bool editing = true;
	while (editing) {
		int choice = input_integer(CONDITION_PERSONAL_INSTRUMENTALIST, 1, 3);
		if (choice == -1) {
			editing = false;
			break;
		}
		switch (choice) {
		case 1:
			while ((this->type_instrument = input_string("Enter type of instrument:")) == "NULL") {
				cout << "Incorrect value!" << endl;
				press_any_character();
			}
			break;
		case 2:
			Instrumentalist::Employee::editing();
			break;
		case 3:
			editing = false;
			cout << "Successful exit!" << endl;
			press_any_character();
			break;
		}
	}
	return 0;
}

class Orchestra {
	int count_employees;
	vector<Employee*> employees;
public:
	Orchestra();
	int viewing() const;
	int addition();
	int removal();
	int editing();
	int sorting();
	int search_by_parameters() const;
};


Orchestra::Orchestra() :
	count_employees(0) {}

int Orchestra::viewing() const {
	system("cls");
	if (!this->count_employees) {
		cout << "The list is empty!" << endl;
		press_any_character();
		return 0;
	}
	for (int _empl = 0; _empl < this->count_employees; _empl++) {
		cout << endl << "Employee #" << _empl + 1 << endl
			<< this->employees[_empl]->getType() << endl;
		if (this->employees[_empl]->viewing() == -1) {
			return -1;
		}
	}
	cout << endl << "Employees successfully shown!" << endl;
	press_any_character();
	return 0;
}

int Orchestra::removal() {
	system("cls");
	if (!this->count_employees) {
		cout << "The list is empty!" << endl;
		press_any_character();
		return 0;
	}
	int _empl = input_integer("Enter employee number | '0' - exit:", 0, this->count_employees);
	if (_empl > this->count_employees || _empl == -1) {
		cout << "Error deleting employee!" << endl;
		press_any_character();
		return 0;
	}
	else if (_empl > 0) {
		this->employees.erase(this->employees.begin() + _empl - 1);
		this->count_employees--;
		cout << "The employee was successfully removed!" << endl;
		press_any_character();
		return _empl;
	}
	else if (!_empl) {
		cout << "Successful exit!" << endl;
		press_any_character();
		return 0;
	}
	return -1;
}

int Orchestra::editing() {
	system("cls");
	if (!this->count_employees) {
		cout << "The list is empty!" << endl;
		press_any_character();
		return 0;
	}
	int _empl = input_integer("Enter employee number | '0' - exit:", 0, this->count_employees);
	if (_empl > this->count_employees) {
		cout << "This employee does not exist!" << endl;
		press_any_character();
		return 0;
	}
	else if (_empl > 0) {
		this->employees[_empl - 1]->editing();
		cout << "The employee was successfully edited!" << endl;
		press_any_character();
		return _empl;
	}
	else if (!_empl) {
		cout << "Successful exit!" << endl;
		press_any_character();
		return 0;
	}
	return -1;
}

const static string CONDITION_ADDITION = "\
+---------------------------------------------+\n\
|Enter the number of employees you want to add|\n\
+---------------------------------------------+\n\
Enter value:";

const static string CONDITION_OPTION_EMPLOYEE = "\
+------------------+\n\
|1. Musician       |\n\
|2. Administrator  |\n\
|3. Vocalist       |\n\
|4. Instrumentalist|\n\
+------------------+\n\
|5. Exit           |\n\
+------------------+\n\
Enter value:";

int Orchestra::addition() {
	int number = input_integer(CONDITION_ADDITION, 0);
	if (number > 0) {
		int buf_number = number, option;
		while (buf_number--) {
			if ((option = input_integer(CONDITION_OPTION_EMPLOYEE, 1, 5)) == -1) {
				cout << "Incorrect value!" << endl;
				press_any_character();
				buf_number++;
			}
			Employee* new_Employee = nullptr;
			switch (option) {
			case 1:
				new_Employee = new Musician(0.0f);
				break;
			case 2:
				new_Employee = new Administrator(0);
				break;
			case 3:
				new_Employee = new Vocalist(0);
				break;
			case 4:
				new_Employee = new Instrumentalist(0);
				break;
			case 5:
				buf_number = -1;
				break;
			}
			if (buf_number == -1) {
				cout << "Successful exit!" << endl;
				press_any_character();
				return number - (buf_number + 1);
			}
			if (new_Employee == nullptr) {
				cout << "Error in creating a new employee!" << endl;
				press_any_character();
			}
			else {
				this->employees.push_back(new_Employee);
				this->count_employees++;
			}
		}
		if (option != -1) {
			cout << (string)"Employee" + (number == 1 ? "" : "s") + " added successfully!" << endl;
			press_any_character();
			return number;
		}
		return -1;
	}
	else if (number == 0) {
		cout << "Employees were't added successfully!" << endl;
		press_any_character();
		return 0;
	}
	cout << "There was an error adding an employee!" << endl;
	press_any_character();
	return -1;
}

static const string CONDITION_OPTION_SORT = "\
+----------------+\n\
|      Sort      |\n\
+----------------+\n\
|1. By surname   |\n\
|2. By name      |\n\
|3. By patronymic|\n\
|4. By type      |\n\
|5. By age       |\n\
|6. By experience|\n\
+----------------+\n\
|7. Exit         |\n\
+----------------+\n\
Enter value:";

int Orchestra::sorting() {
	system("cls");
	if (!this->count_employees) {
		cout << "The list is empty!" << endl;
		press_any_character();
		return 0;
	}
	else if (this->count_employees == 1) {
		cout << "There is only one employee on the list!" << endl;
		press_any_character();
		return 0;
	}
	bool sorting = true;
	while (sorting) {
		int choice = input_integer(CONDITION_OPTION_SORT, 1, 7);
		if (choice == -1) {
			return -1;
		}
		if (choice == 7) {
			sorting = false;
		}
		else {
			for (int _step = 0; _step < this->count_employees - 1; _step++) {
				for (int _emp = 0; _emp < this->count_employees - 1 - _step; _emp++) {
					Employee* first = this->employees[_emp], * second = this->employees[_emp + 1];
					bool swap = false;
					switch (choice) {
					case 1:
						if (first->getSurname().compare(second->getSurname()) > 0) {
							swap = true;
						}
						break;
					case 2:
						if (first->getName().compare(second->getName()) > 0) {
							swap = true;
						}
						break;
					case 3:
						if (first->getPatronymic().compare(second->getPatronymic()) > 0) {
							swap = true;
						}
						break;
					case 4:
						if (first->getType().compare(second->getType()) > 0) {
							swap = true;
						}
						break;
					case 5:
						if (first->getAge() > second->getAge()) {
							swap = true;
						}
						break;
					case 6:
						if (first->getExperience() > second->getExperience()) {
							swap = true;
						}
						break;
					case 7:
						sorting = false;
						break;
					}
					if (swap) {
						Employee* buffer = this->employees[_emp];
						this->employees[_emp] = this->employees[_emp + 1];
						this->employees[_emp + 1] = buffer;
					}
				}
			}
			cout << "Successful sorting!" << endl;
			press_any_character();
		}
	}
	cout << "Successful exit!" << endl;
	press_any_character();
	return 0;
}

const static string CONDITION_OPTION_SEARCH = "\
+----------------+\n\
|     Search     |\n\
+----------------+\n\
|1. By surname   |\n\
|2. By name      |\n\
|3. By patronymic|\n\
|4. By type      |\n\
|5. By age       |\n\
|6. By experience|\n\
+----------------+\n\
|7. Exit         |\n\
+----------------+\n\
Enter value:";

int Orchestra::search_by_parameters() const {
	system("cls");
	if (!this->count_employees) {
		cout << "The list is empty!" << endl;
		press_any_character();
		return 0;
	}
	bool searching = true;
	while (searching) {
		int choice = input_integer(CONDITION_OPTION_SORT, 1, 7);
		if (choice == -1) {
			return -1;
		}
		if (choice == 7) {
			searching = false;
		}
		else {
			bool finded = false;
			switch (choice) {
			case 1: {
				string surname = "";
				while ((surname = input_string("Enter surname:")) == "NULL") {
					cout << "Incorrect value!" << endl;
					press_any_character();
				}
				for (int _empl = 0; _empl < this->count_employees; _empl++) {
					Employee* cur = this->employees[_empl];
					if (surname.compare(cur->getSurname()) == 0) {
						cout << setw(LEN) << setfill('_') << "Employee #" << _empl + 1 << endl;
						cur->viewing();
						finded = true;
					}
				}
			}
				  break;
			case 2:
			{
				string name = "";
				while ((name = input_string("Enter name:")) == "NULL") {
					cout << "Incorrect value!" << endl;
					press_any_character();
				}
				for (int _empl = 0; _empl < this->count_employees; _empl++) {
					Employee* cur = this->employees[_empl];
					if (name.compare(cur->getName()) == 0) {
						cout << setw(LEN) << setfill('_') << "Employee #" << _empl + 1 << endl;
						cur->viewing();
						finded = true;
					}
				}
			}
			break;
			case 3:
			{
				string patronymic = "";
				while ((patronymic = input_string("Enter patronymic:")) == "NULL") {
					cout << "Incorrect value!" << endl;
					press_any_character();
				}
				for (int _empl = 0; _empl < this->count_employees; _empl++) {
					Employee* cur = this->employees[_empl];
					if (patronymic.compare(cur->getPatronymic()) == 0) {
						cout << setw(LEN) << setfill('_') << "Employee #" << _empl + 1 << endl;
						cur->viewing();
						finded = true;
					}
				}
			}
			break;
			case 4:
			{
				string type = "";
				while ((type = input_string("Enter type:")) == "NULL") {
					cout << "Incorrect value!" << endl;
					press_any_character();
				}
				for (int _empl = 0; _empl < this->count_employees; _empl++) {
					Employee* cur = this->employees[_empl];
					if (type.compare(cur->getType()) == 0) {
						cout << setw(LEN) << setfill('_') << "Employee #" << _empl + 1 << endl;
						cur->viewing();
						finded = true;
					}
				}
			}
			break;
			case 5:
			{
				int age;
				while ((age = input_integer("Enter age:", 1)) == -1) {
					cout << "Incorrect value!" << endl;
					press_any_character();
				}
				for (int _empl = 0; _empl < this->count_employees; _empl++) {
					Employee* cur = this->employees[_empl];
					if (age == cur->getAge()) {
						cout << setw(LEN) << setfill('_') << "Employee #" << _empl + 1 << endl;
						cur->viewing();
						finded = true;
					}
				}
			}
			break;
			case 6:
			{
				int experience;
				while ((experience = input_integer("Enter experience:", 0)) == -1) {
					cout << "Incorrect value!" << endl;
					press_any_character();
				}
				for (int _empl = 0; _empl < this->count_employees; _empl++) {
					Employee* cur = this->employees[_empl];
					if (experience == cur->getExperience()) {
						cout << setw(LEN) << setfill('_') << "Employee #" << _empl + 1 << endl;
						cur->viewing();
						finded = true;
					}
				}
			}
			break;
			case 7:
				searching = false;
				break;
			}
			if (finded) {
				cout << "Successful searched!" << endl;
			}
			else {
				cout << "The list is empty!" << endl;
			}
			press_any_character();
		}
	}
	cout << "Successful exit!" << endl;
	press_any_character();
	return 0;
}

const static string MENU = "\
+-----------------------+\n\
|         MENU          |\n\
+-----------------------+\n\
|1. Viewing             |\n\
|2. Addition            |\n\
|3. Removal             |\n\
|4. Editing             |\n\
|5. Sorting             |\n\
|6. Search by parameters|\n\
+-----------------------+\n\
|7. Exit                |\n\
+-----------------------+\n\
Enter value:";

int main(void) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout.setf(ios::basefield | ios::adjustfield | ios::floatfield);
	bool program_is_work = true;
	Orchestra orchestra;
	while (program_is_work) {
		int choice = input_integer(MENU, 1, 7);
		switch (choice) {
		case -1:
			cout << "Incorrect value!" << endl;
			press_any_character();
			break;
		case 1:
			orchestra.viewing();
			break;
		case 2:
			orchestra.addition();
			break;
		case 3:
			orchestra.removal();
			break;
		case 4:
			orchestra.editing();
			break;
		case 5:
			orchestra.sorting();
			break;
		case 6:
			orchestra.search_by_parameters();
			break;
		case 7:
			program_is_work = false;
			break;
		}
	}
	return 0;
}