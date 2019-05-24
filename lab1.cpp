// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include"list_funcs.h"
#include"Point.h"
#include <conio.h>
template <class T>
void menu(List<T> list);

int main() {
	List <point> list;
	menu(list);
	return 0;
}
template <class T>
void menu(List<T> list) {
	int choise;
	//List<point> list;

	std::cout << "Choose option:\n 0)exit\n 1)push_back\n 2)push_front\n 3)pop_back\n 4)pop_front\n 5)insert\n 6)at\n 7)remove\n 8)get_size\n 9)print_to_console\n 10)clear\n 11)set\n 12)isEmpty\n";
	do {
		std::cout << "Input index of option \n";
		std::cin >> choise;
		switch (choise)
		{
		case 1:
		{
			T new_item;

			std::cout << "Enter value \n";
			std::cin >> new_item;
			list.push_back(new_item);
			std::cout << "Updated list: ";
			list.print_to_console();
			std::cout << std::endl;
			break;
		}
		case 2:
		{
			T new_item;

			std::cout << "Enter value \n";
			std::cin >> new_item;
			list.push_front(new_item);
			std::cout << "Updated list: ";
			list.print_to_console();
			std::cout << std::endl;
			break;

		}
		case 3:
		{
			list.pop_back();

			std::cout << "Updated list: ";
			list.print_to_console();
			std::cout << std::endl;
			break;

		}
		case 4:
		{

			list.pop_front();
			std::cout << "Updated list: ";
			list.print_to_console();
			std::cout << std::endl;
			break;

		}
		case 5:
		{

			T new_item;
			size_t index;
			std::cout << "Enter value  \n";
			std::cin >> new_item;
			std::cout << "Enter number of position\n";
			std::cin >> index;
			try
			{
				list.insert(index, new_item);
			}
			catch (std::out_of_range)
			{
				std::cout << "There is no elements with this index\n";
				break;
			}


			std::cout << "Updated list: ";
			list.print_to_console();
			std::cout << std::endl;

			break;

		}
		case 6:
		{
			size_t index;
			std::cout << "Enter number of position\n";
			std::cin >> index;
			try
			{
				list.at(index);
			}
			catch (std::out_of_range)
			{
				std::cout << "There is no elements with this index\n";
				break;
			}
			std::cout << std::endl << list.at(index) << std::endl;
			break;

		}
		case 7:
		{
			size_t index;
			std::cout << "Enter number of position\n";
			std::cin >> index;
			try
			{
				list.remove(index);
			}
			catch (std::out_of_range)
			{
				std::cout << "There is no elements with this index\n";
				break;
			}


			std::cout << "Updated list: ";
			list.print_to_console();
			std::cout << std::endl;
			break;

		}
		case 8:
		{
			std::cout << "Size of list: ";
			std::cout << list.get_size() << std::endl;
			break;

		}
		case 9:
		{
			std::cout << "List: ";
			list.print_to_console();
			std::cout << std::endl;
			break;

		}
		case 10:
		{
			list.clear();
			std::cout << "List was cleared";
			std::cout << std::endl;
			break;

		}
		case 11:
		{

			T new_item;
			size_t index;
			std::cout << "Enter value  \n";
			std::cin >> new_item;
			std::cout << "Enter number of position\n";
			std::cin >> index;
			try
			{
				list.set(index, new_item);
			}
			catch (std::out_of_range)
			{
				std::cout << "There is no elements with this index\n";
				break;
			}

			std::cout << "Updated list: ";
			list.print_to_console();
			std::cout << std::endl;
			break;

		}
		case 12:
		{
			std::cout << "Is Empty: " << list.isEmpty() << std::endl;
			std::cout << std::endl;
			break;

		}
		case 0:
		{
			std::cout << "For closing press any key...";
			_getch();
			return;
		}
		}
	} while (1 == 1);
	
}
