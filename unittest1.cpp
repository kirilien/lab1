#include "stdafx.h"
#include "CppUnitTest.h"
#include"../lab1/list_funcs.h"
#include"../lab1/Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(pushBackTest)
	{
	public:
		TEST_METHOD(pushBackInteger)
		{
			List <int> list;

			list.push_back(9);
			Assert::IsTrue((list.get_size() == 1) && !(list.isEmpty()) && (list.at(0) == 9));
		}

		TEST_METHOD(pushBackDouble)
		{
			List <double> list;

			list.push_back(2.2);
			list.push_back(3.3);
			list.push_back(1.1);
			Assert::IsTrue((list.get_size() == 3) && (list.at(0) == 2.2) && (list.at(1) == 3.3) && (list.at(2) == 1.1));
		}

		TEST_METHOD(pushBackPoint)
		{
			List <point> list;
			point pt;

			pt.id = 2;
			pt.x = 7.7;
			pt.y = 1.3;
			list.push_back(pt);
			Assert::IsTrue((list.get_size() == 1) && (list.at(0).id == 2) && (list.at(0).x == 7.7) && (list.at(0).y == 1.3));
		}
	};

	TEST_CLASS(pushFrontTest)
	{
	public:
		TEST_METHOD(pushFrontInteger)
		{
			List <int> list;

			list.push_front(2);
			list.push_front(3);
			list.push_front(1);
			Assert::IsTrue((list.get_size() == 3) && (list.at(0) == 1) && (list.at(1) == 3) && (list.at(2) == 2));
		}

		TEST_METHOD(pushFrontDouble)
		{
			List <double> list;

			list.push_front(9.99);
			Assert::IsTrue((list.get_size() == 1) && !(list.isEmpty()) && (list.at(0) == 9.99));
		}

		TEST_METHOD(pushFrontPoint)
		{
			List <point> list;
			point pt;

			pt.id = 2;
			pt.x = 7.7;
			pt.y = 1.3;
			list.push_front(pt);

			pt.id = 3;
			pt.x = 10;
			pt.y = 6.3;
			list.push_front(pt);

			pt.id = 5;
			pt.x = 12;
			pt.y = 3;
			list.push_front(pt);

			Assert::IsFalse((list.get_size() == 1) && (list.at(0).id == 2) && (list.at(0).x == 7.7) && (list.at(0).y == 1.3));
			
			Assert::IsTrue((list.get_size() == 3) && (list.at(0).id == 5) && (list.at(0).x == 12) && (list.at(0).y == 3));
		}
	};

	TEST_CLASS(popBackTest)
	{
	public:
		TEST_METHOD(popBackInteger)
		{
			List <int> list;

			list.push_back(9);
			list.push_back(10);
			list.pop_back();
			Assert::IsTrue(!(list.isEmpty()) && list.at(0)==9);
		}
		
		TEST_METHOD(popBackDouble)
		{
			List <double> list;

			list.push_back(-9.99);
			list.push_back(10.1);
			list.pop_back();
			Assert::IsTrue(!(list.isEmpty()) && (list.at(0) == -9.99) && (list.get_size() == 1));

			list.pop_back();
			Assert::IsTrue((list.isEmpty()) && (list.get_size() == 0));
		}

		TEST_METHOD(popBackPoint)
		{
			List <point> list;
			point pt;

			pt.id = 2;
			pt.x = 7.7;
			pt.y = 1.3;
			list.push_back(pt);
			list.pop_back();

			Assert::IsTrue(list.isEmpty());
		}
	};

	TEST_CLASS(popFrontTest)
	{
	public:
		TEST_METHOD(popFrontInteger)
		{
			List <int> list;

			list.push_back(9);
			list.pop_front();
			Assert::IsTrue(list.isEmpty());
		}
		
		TEST_METHOD(popFrontDouble)
		{
			List <double> list;

			list.push_back(9.87);
			list.push_back(10.01);
			list.pop_front();
			Assert::IsTrue(!(list.isEmpty()) && (list.at(0) == 10.01) && (list.get_size() == 1));

			list.pop_back();
			Assert::IsTrue((list.isEmpty()) && (list.get_size() == 0));
		}

		TEST_METHOD(popFrontPoint)
		{
			List <point> list;
			point pt;

			pt.id = 2;
			pt.x = 7.7;
			pt.y = 1.3;
			list.push_back(pt);
			list.pop_front();
			Assert::IsTrue(list.isEmpty());
		}
	};

	TEST_CLASS(insertTest)
	{
	public:
		TEST_METHOD(insertIntegerInMiddle)
		{
			List <int> list;

			list.push_back(9); 
			list.push_back(10);
			list.insert(1, -1);
			Assert::IsTrue((list.at(2) == 10) && (list.at(1) == -1) && (list.get_size() == 3));
		}

		TEST_METHOD(insertDoubleOnNonexistentPosition)
		{
			List <double> list;

			list.push_back(9);
			list.push_back(10.7);
			try
			{
				list.insert(10, -6.986);
			}
			catch (const std::out_of_range &e)
			{
				Assert::AreEqual("List::insert out of range", e.what());
			}
		}
		TEST_METHOD(insertDoubleOnLastPosition)
		{
			List <double> list;

			list.push_back(9);
			list.push_back(10.7);
			list.insert(2, -6.986);
			
			Assert::IsTrue((list.at(2) == -6.986) && (list.at(1) == 10.7) && (list.get_size() == 3));

		}
		TEST_METHOD(insertPointOnFirstPosition)
		{
			List <point> list;
			point pt;

			pt.id = 2;
			pt.x = 7.7;
			pt.y = 1.3;
			list.insert(0, pt);
			Assert::IsTrue((list.get_size() == 1) && (list.at(0).id == 2) && (list.at(0).x == 7.7) && (list.at(0).y == 1.3));
		}

	};

	TEST_CLASS(atTest)
	{
	public:
		TEST_METHOD(atIntegerEmptyList)
		{
			List <int> list;

			try
			{
				list.at(-10);
			}
			catch (const std::out_of_range &e)
			{
				Assert::AreEqual("List::at out of range", e.what());
			}
		}
		TEST_METHOD(atIntegerOneElement)
		{
			List <int> list;

				list.push_back(9);
	
				Assert::AreEqual((list.at(0)), 9);
			
		}
		TEST_METHOD(atDoubleSomeElements)
		{
			List <double> list;

			list.push_back(4.4);
			list.push_back(-5.5);
			list.push_back(9.3);
			
			Assert::AreEqual((list.at(1)), -5.5);
			Assert::AreEqual((list.at(2)), 9.3);
		}

		TEST_METHOD(atPointOneElement)
		{
			List <point> list;
			point pt;

			pt.id = 2;
			pt.x = 7.7;
			pt.y = 1.3;
			list.push_front(pt);
			Assert::IsTrue((list.at(0).id == 2) && (list.at(0).x == 7.7) && (list.at(0).y == 1.3));
			
		}
	};

	TEST_CLASS(removeTest)
	{
		TEST_METHOD(removeIntegerEmptyList)
		{
			List <int> list;

			try
			{
				list.remove(10);
			}
			catch (const std::out_of_range &e)
			{
				Assert::AreEqual("List::remove out of range", e.what());
			}
		}

		TEST_METHOD(removeDoubleFromMiddle)
		{
			List <double> list;

			list.push_back(1.5);
			list.push_back(2.42);
			list.push_back(3.14);
			list.push_back(4.18);
			list.remove(2);

			Assert::IsTrue(list.at(2) == 4.18);
		}
		TEST_METHOD(removeDoubleOneElement)
		{
			List <double> list;
			list.push_back(4.18);
			list.remove(0);

			Assert::IsTrue(list.get_size()==0);
		}
		TEST_METHOD(removePointLastElement)
		{
			List <point> list;
			point pt;

			pt.id = 2;
			pt.x = 7.7;
			pt.y = 1.3;
			list.push_back(pt);
			pt.id = 3;
			pt.x = 8;
			pt.y = 3.3;
			list.push_back(pt);
			pt.id = 8;
			pt.x = 1.3;
			pt.y = 1;
			list.push_back(pt);
			list.remove(2);
			Assert::IsTrue(((list.at(0).id) == 2));
		}
	};

	TEST_CLASS(getSizeTest)
	{
		TEST_METHOD(getSizeInteger)
		{
			List <int> list;
			list.push_back(2);
			Assert::IsTrue(list.get_size() == 1);
		}

		TEST_METHOD(getSizeDouble)
		{
			List <double> list;
			list.push_back(2);
			list.push_back(3.5);
			Assert::IsTrue(list.get_size() == 2);
		};

		TEST_METHOD(getSizePoint)
		{
			List <point> list;
			Assert::IsTrue(list.get_size() == 0);
		}
	};

	TEST_CLASS(clearTest)
	{
		TEST_METHOD(clearInteger)
		{
			List <int> list;
			for (int count = 0; count < 10; count++)
				list.push_back(count);
			list.clear();

			Assert::IsTrue(list.isEmpty());
		}

		TEST_METHOD(clearDouble)
		{
			List <double> list;
			list.push_back(48.88);
			list.clear();

			Assert::IsFalse(!(list.isEmpty()));
		}

		TEST_METHOD(clearPoint)
		{
			List <point> list;
			list.clear();

			Assert::IsTrue(list.isEmpty());
		}
	};

	TEST_CLASS(setTest)
	{
		TEST_METHOD(setIntegerLastElement)
		{
			List <int> list;
			list.insert(0, 5);
			list.push_back(2);
			list.set(1, 4);
			Assert::IsTrue((list.get_size() == 2) && (list.at(1) == 4));
		}

		TEST_METHOD(setDoubleNoElements)
		{
			List <double> list;
			try
			{
				list.set(-100, 2.345);
			}
			catch (const std::out_of_range &e)
			{
				Assert::AreEqual("List::set out of range", e.what());
			}
		}
		TEST_METHOD(setDoubleMiddle)
		{
			List <double> list;
			list.push_back(1.5);
			list.push_back(2.42);
			list.push_back(3.14);
			list.push_back(4.18);
			list.set(2, 4.8);
			Assert::IsTrue((list.get_size() == 4) && (list.at(2) == 4.8));
		}
		TEST_METHOD(setPointFirstElement)
		{
			List <point> list;
			point pt;

			pt.id = 2;
			pt.x = 7.7;
			pt.y = 1.3;
			list.push_back(pt);
			pt.id = 3;
			pt.x = 9;
			pt.y = 1;
			list.set(0, pt);
			Assert::IsTrue((list.at(0).id == 3) && (list.at(0).x == 9));
		}
	};

	TEST_CLASS(isEmptyTest)
	{
		TEST_METHOD(isEmptyInteger)
		{
			List <int> list;
			Assert::IsTrue(list.isEmpty());
		}

		TEST_METHOD(isEmptyDouble)
		{
			List <double> list;
			list.push_back(1.28);
			Assert::IsFalse(list.isEmpty());
		}

		TEST_METHOD(isEmptyPoint)
		{
			List <point> list;
			point pt;

			pt.id = 2;
			pt.x = 7.7;
			pt.y = 1.3;
			list.push_front(pt);
			list.push_front(pt);
			list.push_front(pt);
			list.clear();
			Assert::IsTrue(list.isEmpty());
		}
	};
}