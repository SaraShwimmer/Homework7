// Homework7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
//Задание 1

/*Создайте класс Date с полями день, месяц, год и методами доступа к этим полям. 
Перегрузите оператор вывода для данного класса. Создайте два "умных" указателя today и date. 
Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности методы доступа 
к полям класса Date, а также выведите на экран данные всего объекта с помощью перегруженного 
оператора вывода. Затем переместите ресурс, которым владеет указатель today в указатель date. 
Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.*/
class Date
{
private:
	int m_day;
	int m_month;
	int m_year;
public:
	Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {}

	const int& getDay() const
	{
		return m_day;
	}

	const int& getMonth() const
	{
		return m_month;
	}

	const int& getYear() const
	{
		return m_year;
	}

	friend ostream& operator<<(ostream& os, const Date& d)
	{
		os << d.m_day << '.' << d.m_month << '.' << d.m_year;

		return os;
	}
};

template <class T>
class _ptr
{
private:
	T* m_ptr;
public:
	_ptr(T* ptr = nullptr) : m_ptr(ptr) {}
	~_ptr() { delete m_ptr; }

	_ptr(_ptr& p)
	{
		m_ptr = p.m_ptr;
		p.m_ptr = nullptr;
	}

	_ptr& operator=(_ptr& p)
	{
		if (&p == this)
			return *this;

		delete m_ptr;
		m_ptr = p.m_ptr;
		p.m_ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }

	bool isNull() const { return m_ptr == nullptr; }
};

const _ptr<Date>& compares_dates(const _ptr<Date>&, const _ptr<Date>&);

void Task1()
{
	_ptr<Date> today(new Date(10, 07, 2021));

	cout << "Day: " << today->getDay() << endl;
	cout << "Month: " << today->getMonth() << endl;
	cout << "Year: " << today->getYear() << endl;
	std::cout << "today: " << *today << endl;

	_ptr<Date> date;

	cout << "today is " << (today.isNull() ? "null\n" : "not null\n");
	cout << "date is " << (date.isNull() ? "null\n" : "not null\n");

	date = today;

	cout << "today is " << (today.isNull() ? "null\n" : "not null\n");
	cout << "date is " << (date.isNull() ? "null\n" : "not null\n");

	cout << "date: " << *date << std::endl;
}

const _ptr<Date>& compares_dates(const _ptr<Date>& a, const _ptr<Date>& b)
{
	if (a->getYear() > b->getYear())
		return a;
	else if (a->getYear() < b->getYear())
		return b;
	else
	{
		if (a->getMonth() > b->getMonth())
			return a;
		else if (a->getMonth() < b->getMonth())
			return b;
		else
		{
			if (a->getDay() > b->getDay())
				return a;
			else
				return b;
		}
	}
}

void swap_dates(_ptr<Date>& a, _ptr<Date>& b)
{
	_ptr<Date> temp(a);
	a = b;
	b = temp;
}

//Задание 2
  
/*По условию предыдущей задачи создайте два умных указателя date1 и date2. 
Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date 
и сравнивает их между собой (сравнение происходит по датам). Функция должна вернуть 
более позднюю дату. Создайте функцию, которая обменивает ресурсами (датами) два умных 
указателя, переданных в функцию в качестве параметров. Примечание: обратите внимание, 
что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.*/

void Task2()
{
	_ptr<Date> date1(new Date(9, 07, 2022));
	_ptr<Date> date2(new Date(10, 07, 2022));
	_ptr<Date> date3(new Date(11, 07, 2022));

	cout << *compares_dates(date1, date2) << endl;
	swap_dates(date2, date3);
	cout << *compares_dates(date1, date2) << endl;
}

int main()
{
	Task1();
	Task2();
	

}

