#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
//#include <array>

struct dateData //lower camel case
{
	int  Day = 1;
	int  Month = 1;
	int  Year = 2000;
	std::string Note = "no data";
};
struct personData
{
	std::string Name = "not yet";
	dateData birth_day = { 12,04,1983 }; //including object of type dateData structure into personData structure
	std::string Gender;
	std::string Job;
	int Salary;
};
struct perSon_coinKeeper
{
	std::string Name = "no name";
	int Age;
	int coins_ammount=0;
	int* coins_array = nullptr;
};

// Service functions prototypes ------------------------------------
int Get_Int_SA();			// String-analysis вариант фильтра INTEGER
int Get_Int_Positive();		// String-Analysis вариант проверки ввода INTEGER_POSITIVE		
int Get_Int_PG();			// peek&get вариант проверки ввода INTEGER	
double Get_Dbl_SA();		// String-analysis вариант фильтра DOUBLE.
double Get_Dbl_Positive();	// String-analysis вариант фильтра DOUBLE_POSITIVE
double Get_Dbl_PG();		// peek&get вариант проверки ввода DOUBLE	
int Get_Random(int Range_min, int Range_max);
double Get_Random(double Range_min, double Range_max);
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max);
template <typename ANY> void Array_Console_Out(ANY arr[], int Size);

// Class Work 04.04.2023 -------------------------------------------	

//Структура - описание множевства, состоящего из 1-ой или более переменных, возможно разных типов, объединенных под одним именем. Является производным пользовательским типом данных. Используется для создания объектов

//Structure - a description of a set consisting of 1 or more variables, possibly of different types, united under one name. It is user-defined data type. Used to create objects


//Task 1 Structure. Intro. Syntax.
void Task_1()
{
	struct Person // creating new structure
	{
		//Состав структуры
		std::string Name;
		int Age;
		std::string Gender;
		std::string Job;
		int Salary;
		//creating an object of structure with imnmediatly initialisation
	} Person_1, Person_2{ "Bill Gates", 72, "male", "Microsoft owner", 999000 };

	Person_1.Name = "Steve Jobs";
	Person_1.Age = 26;
	Person_1.Gender = "male";
	Person_1.Job = "Coder jun";
	Person_1.Salary = 99000.0;

	std::cout << "\nPerson_1.Name: " << Person_1.Name;
	std::cout << "\nPerson_1.Age: " << Person_1.Age;
	std::cout << "\nPerson_1.Gender: " << Person_1.Gender;
	std::cout << "\nPerson_1.Job: " << Person_1.Job;
	std::cout << "\nPerson_1.Salary : " << Person_1.Salary;

	std::cout << "\n\nPerson_2.Name: " << Person_2.Name;
	std::cout << "\nPerson_2.Age: " << Person_2.Age;
	std::cout << "\nPerson_2.Gender: " << Person_2.Gender;
	std::cout << "\nPerson_2.Job: " << Person_2.Job;
	std::cout << "\nPerson_2.Salary : " << Person_2.Salary;


	Person Person_3{ "Ilon Musk", 46, "male", "Tesla owner", 1999000 };
	Person Person_4 = Person_3; //прямое присваивание полей объекта Person_3 полям объекта Person_4;

	std::cout << "\n\nPerson_4.Name: " << Person_4.Name;
	std::cout << "\nPerson_4.Age: " << Person_4.Age;
	std::cout << "\nPerson_4.Gender: " << Person_4.Gender;
	std::cout << "\nPerson_4.Job: " << Person_4.Job;
	std::cout << "\nPerson_4.Salary : " << Person_4.Salary;

}
//Task 2
void Task_2()
{
	struct Date
	{
		int unsigned Day = 1;
		int unsigned Month = 1;
		int unsigned Year = 2000;
		std::string Note = "no data"; //default value
	} BirthDay{ 12,4,1983, "my birthday"};


	std::cout << "BirthDay " << BirthDay.Day << "/" << BirthDay.Month << "/" << BirthDay.Year << ": " << BirthDay.Note;
}

//Task_3
void show_person(const personData& personData_for_func)
{
	std::cout << "\nPerson.Name: " << personData_for_func.Name;
	std::cout << "\nPerson.birth_day: " << personData_for_func.birth_day.Day << "/" << personData_for_func.birth_day.Month << "/" << personData_for_func.birth_day.Year;
	std::cout << "\nPerson.Gender: " << personData_for_func.Gender;
	std::cout << "\nPerson.Job: " << personData_for_func.Job;
	std::cout << "\nPerson.Salary : " << personData_for_func.Salary;
}
personData Create_person()
{
	personData tmp;
	std::cout << "\n\n" << "Enter a name ";
	getline(std::cin, tmp.Name);
	std::cout << "\n" << "Enter a day of birth ";
	tmp.birth_day.Day=Get_Int_SA();
	std::cout << "\n" << "Enter a month of birth ";
	tmp.birth_day.Month= Get_Int_SA();
	std::cout << "\n" << "Enter a year of birth ";
	tmp.birth_day.Year = Get_Int_SA();
	std::cout << "\n" << "Enter job place ";
	getline(std::cin, tmp.Job);
	std::cout << "\n" << "Enter salary ";
	tmp.Salary=Get_Int_SA();
	
	return tmp;	
}
void Task_3()
{
/* Moved in global area
	struct dateData //lower camel case
	{
		int  Day = 1;
		int  Month = 1;
		int  Year = 2000;
		std::string Note = "no data";
	};

	struct personData
	{
		std::string Name = "not yet";
		dateData birth_day = {12,04,1983}; //including object of type dateData structure into personData structure
		std::string Gender;
		std::string Job;
		int Salary;
	};
	*/

	personData Person_5
	{	"Cho Chin", 
		{1,10,2010}, 
		"male",
		"tennis coach",
		85000
	};

	/* Moved to function
	std::cout << "\nPerson_5.Name: " << Person_5.Name;
	std::cout << "\nPerson_5.birth_day: " << Person_5.birth_day.Day<< "/" << Person_5.birth_day.Month << "/" << Person_5.birth_day.Year;
	std::cout << "\nPerson_5.Gender: " << Person_5.Gender;
	std::cout << "\nPerson_5.Job: " << Person_5.Job;
	std::cout << "\nPerson_5.Salary : " << Person_5.Salary;
	*/
	show_person(Person_5);

	std::cout << "\n\n";

	personData* _pointer_personData = &Person_5;
	std::cout << _pointer_personData->Name << "\n"; // First way to access field .Name
	//std::cout << *(_pointer_personData).Name; // Second way
	std::cout << _pointer_personData->birth_day.Year;

	personData Person_6 = Create_person();
	show_person(Person_6);

}

//Task_4
void Show_perSon_coinKeeper(const perSon_coinKeeper& pcK)
{
	std::cout << "\n\ncoinKeeper.Name: " << pcK.Name;
	std::cout << "\ncoinKeeper.Age: " << pcK.Age;

	int* coins_array = nullptr;

	std::cout << "\ncoinKeeper.coins_ammount: " << pcK.coins_ammount;
	std::cout << "\ncoinKeeper.coins_array: ";
	for (int i=0;i< pcK.coins_ammount;i++)
	std::cout << "" << pcK.coins_array[i] << ", ";
	std::cout << "\b\b \n";


}
inline int Year_of_Birth_coinKeeper(const perSon_coinKeeper& pcK, int current_year)
{
	return (current_year - pcK.Age);
}
inline int cash_coinKeeper(const perSon_coinKeeper& pcK)
{
	int Summ = 0;
	for (int i = 0; i < pcK.coins_ammount; i++)
		Summ += pcK.coins_array[i];
		return Summ;
}

void Task_4()
{
	perSon_coinKeeper Keeper_1
	{
		"Peter",
		10,
		7,
		new int[7] {1,2,5,10,10,5,1}
	};
	Show_perSon_coinKeeper(Keeper_1);
	std::cout << "\nYear_of_Birth_coinKeeper: " << Year_of_Birth_coinKeeper(Keeper_1, 2023);
	std::cout << "\nCash summary: " << cash_coinKeeper(Keeper_1);
		
	delete[] Keeper_1.coins_array;
}



// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
srand(time(NULL));
		
//Task_1();

//Task_2();

//Task_3();

Task_4();





std::cout << "\n\n";
system("pause");	
}

// Service functions -----------------------------------------
int Get_Int_SA() {
	std::string a;
	std::cin.sync(); 
	std::cin.clear(); 
	getline(std::cin, a);
	if (a != "")
	{

		if ((a.find_first_not_of("-0123456789") == -1))
		{
			for (int i = 1; i < a.size(); i++) // определяем есть ли минусы кроме первого символа
			{
				if (a[i] == '-') 
				{
					std::cout << "Input Error: Minus misstanding. [INTEGER] expected.\n";
					return Get_Int_SA();
				}
			}
			try
			{
				return stoi(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. [INTEGER] expected.\n";
				return Get_Int_SA();
			}


		}
		else
		{
			std::cout << "Input Error: Incorrect symbol. [INTEGER] expected.\n";
			return Get_Int_SA();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. [INTEGER] expected.\n";
		return Get_Int_SA();
	}
}
int Get_Int_Positive()
{
	std::string a;
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "") 
	{

		if ((a.find_first_not_of("0123456789") == -1))
		{
			try{
				return stoi(a);
			}
			catch (std::out_of_range){
				std::cout << "Input Error: overflow. Positive [INTEGER] expected.\n";
			}
		}
		else
		{
			std::cout << "Input Error: Positive [INTEGER] expected.\n";
			return Get_Int_Positive();
		}		
	}
	else
		std::cout << "Input Error: NULL input. Positive [INTEGER] expected.\n";
	return Get_Int_Positive();
}
int Get_Int_PG()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! [INTEGER] expected. Repeat please...\n";
	}
	return a;
}
double Get_Dbl_SA(){
	std::string a;
	std::cin.sync();
	getline(std::cin, a);
	if (a == "") { std::cout << "\nInput Error : NULL input\n"; return Get_Dbl_SA(); }
	if ((a.find_first_not_of("-.0123456789") == -1))
	{
		for (int i = 1; i < a.size(); i++) // Проверяем отсутсвие лишних минусов
		{
			if (a[i] == '-')
			{
				std::cout << "\nInput Error: Minus misstanding. [DOUBLE] expected.\n";
				return Get_Dbl_SA();
			}

		}
		bool Dot_Flag = 0;
		for (int i = 0; i < a.size(); i++) // проверяем отсутсвие лишних точек
		{
			if (a[i] == '.')
			{
				if (Dot_Flag == 1)
				{
					std::cout << "\nInput Error: Dot misstandig. [DOUBLE] expected.\n";
					return Get_Dbl_SA();
				}
				Dot_Flag = 1;
			}

		}		 	
				try{
					return stod(a);
				}
				catch (std::out_of_range) {
					std::cout << "Input Error: overflow. [DOUBLE] expected.\n";
					return Get_Dbl_SA();					
				}						
	}
	else {		
		std::cout << "Incorrect symbols: [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
		return Get_Dbl_SA();
	}
}
double Get_Dbl_Positive(){
	std::string a, dot = ".";
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "")
	{
		if ((a.find_first_not_of(".0123456789") == -1))
		{
			bool One_Dot_already = false;
			for (int i = 0; i < a.size(); i++)
			{				
				if (a[i] == dot[0] && One_Dot_already == true) //проверяем количество разделителей
				{
					std::cout << "Input Error: Dot misstandig. Positive [DOUBLE] expected.\n";
					return Get_Dbl_Positive();
				}
				if (a[i] == dot[0])	One_Dot_already = true;
			}
			try
			{				
				return stod(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. Positive [DOUBLE] expected.\n";
				return Get_Dbl_Positive();
			}
		}
		else
		{
			//std::cout << "Incorrect symbols: positive REAL expected.\nUse coma instead of dot. Example 50,64\n"; // да точно говорю вот даже сообщение такое было, а теперь наоборот wtf*2?!
			std::cout << "Incorrect symbols: Positive [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
			return Get_Dbl_Positive();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. Positive [DOUBLE] expected.\n";
		return Get_Dbl_Positive();
	}
	return Get_Dbl_Positive();
}
double Get_Dbl_PG()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! [DOUBLE] expected. Repeat please...\n";
	}
	return a;
}
int Get_Random(int Range_min=-999, int Range_max=999)
{
	if (Range_min > Range_max) 
	{ 
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	//return (Range_min + rand() % (Range_max - Range_min + 1));
	double K_random = double((rand() % RAND_MAX)) / RAND_MAX;
	int random = Range_min + ((Range_max - Range_min) * K_random);
	//return Range_min + (Range_max - Range_min) * (rand() % RAND_MAX) / RAND_MAX;
	return random;
}
double Get_Random(double Range_min=-9999.0, double Range_max=9999.0)
{
	if (Range_min > Range_max)
	{
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	return 	Range_min + (Range_max - Range_min) * double(rand() % RAND_MAX) / RAND_MAX;	
}
template <typename ANY> void Array_Console_Out(ANY arr[], int Size)
{
	std::cout << "\n[";
	for (int i = 0; i < Size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max)
{
	for (int i = 0; i < Size; i++)
	{
		arr[i] = Get_Random(Range_min, Range_max);		
	}
}
