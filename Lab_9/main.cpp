// ���������� STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

//#include "stdafx.h"
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>

#include <iostream>
#include <algorithm>
#include <functional>
#include "libs.h"


using namespace std;

#define stop

int main(int argc, char* argv[])
{


	//�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
	//�������� �������� �� ��, ��� ���������� ������������� ������ ������ ��� 
	//��������� ��������

	{
		std::stack<int> s;
		std::queue<int> q;
		std::priority_queue<int> pq;
		for (int i = 0; i < 3; i++) {
			q.push(i);
			pq.push(i);
			s.push(i);
		}

		stPrint(s);
		stPrint(q);
		stPrint(pq);
		// return 0;
	}



	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//�������� ���� ����� �������, �����
	//�) �������� ����� ����� ������� ��������� �������
	//�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ���������� 
	{
		std::cout << "=======================" << std::endl;
		std::vector<int> sv{ 1,2,3,4 };
		std::reverse(sv.begin(), sv.end());
		std::stack<int> ss({ sv.rbegin(), sv.rend() });

		stPrint(sv);
		stPrint(ss);
		//return 0;

	}


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//�������� �������, ������� �������� ��������� �� ������� ���� Point,
	//��� ���� ���� ������� ������� ���������.
	//�������� �������� ������� � ���������� ��������� ����������� front() � back()
	//���������, ��� ��������� ������� ��� ����������� ����� �������?

	{
		std::queue<Point*, std::deque<Point*>> ppq;
		ppq.push(nullptr);
		ppq.push(nullptr);

		ppq.front() = new Point(1, 2);
		ppq.back() = new Point(1, 2);

		stPrint(ppq);

		while (!ppq.empty()) {
			Point *pf = ppq.front();
			ppq.pop();
			if (pf) {
				delete pf;
			}
		}

	}




	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*
	//�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
	//�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
	//		��� ������������ ��� �������?




	{

		const char* ar[3] = { "abc", "mjv", "xwz" };
		std::priority_queue<const char*> pqc({ ar, ar + 3 });
		stPrint(pqc);
	}




	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ����������
	//		� ������ Point (� ����� �������)
	//�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������
	//�) ���������� �������� ����� ��������...
	//�) �������� ��� ���������, ������� ����� ��������� ���������� ��������
	//		���� int, �� ���������� � ������ �������
	//�) �������� � ����� ��������� �������� ��������� �� ������ �������
	//	����������, ��������, ��������� �������	(��� ����������, ���� � ������� ������� �����?)


	{

		//� point ���������� ���������� operator<
		std::set<Point> sp;
		sp.insert(Point(1, 2));
		sp.insert(Point(1, 2));
		sp.insert(Point(10, 10));
		std::cout << sp.size() << std::endl;
		itPrint(sp);

		//(*sp.begin()).setXY(2,2);    //������ ��� ��� �������� ���������

		std::set<int> si1{ 1,2,3 };
		std::set<int> si2{ 3,1,2 };
		int ai[] = { 2,3,4 };

		si2.insert(ai, ai + 3);
		itPrint(si2); //��������� ������ ������ ���������� ��������
	}








	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,
	//	��� ���� ������ �������� ���������� ����������
	//�) ��������� ��������� ���������� ����������� operator[] � insert()
	//�) ������������ ����������

	//�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")

	stop
	{
		std::map<const char*, int> mf;
		mf.insert(std::pair<const char*, int>("������", 1000000));
		mf["������"] = 999999;
		mf["�������"] = 2000000;

		itPrint(mf);


		auto val = mf.find("�������");
		if (val != mf.end()) {
			mf["�������"] = (*val).second;
			mf.erase(val);
		}

		itPrint(mf);
	}



		//�) ����������� ����� �������� ������ � ���������� ���� string.
		//�������� (� ������������ ��� ��������) map<string, int>, ������� �����
		//��������� ������������� �� �������� ������ �
		//���������� ���������� ������ ������ � �������

	{
		std::vector<std::string> vs = { "xyz", "Test 1", "Abc", "xyz", "My str", "test", "Abc", "Some", "Kate" };
		itPrint(vs);

		std::map<std::string, int> ms;

		for (auto s : vs) {
			auto it = ms.find(s);
			if (it != ms.end()) {
				(*it).second += 1;
			}
			else {
				ms[s] = 1;
			}
		}

		std::vector<std::pair<std::string, int>> vs1(ms.begin(), ms.end());
		std::sort(vs1.begin(), vs1.end(),
			[](const std::pair<std::string, int>& l, const std::pair<std::string, int>& r) {
			return (r.first.compare(l.first) < 0); });


		itPrint(ms);
		itPrint(vs1);
		return 0;
	}



	//�) 
	//����� ������:
	//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
	//�������� map, � ������� ������ ����� ����� ��������������� ������������ 
	//��������������� ������������� ����, ������������ � ���� �����.
	//���������: �� ����� ������� ����� ����� � ��� �� ������

	//'A' -  "Abba" "Alfa"
	//'B' -  "Beauty" "Beta"  ...
	//...

	{
		const char* words[] = { "Abba", "Alfa", "Beta", "Beauty", "test", "tor" };
		std::map<int, std::vector<int>> sm;
		char ch;
		for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
			ch = words[i][0];
			auto it = sm.find(ch);
			if (it == sm.end()) {
				std::vector<int> tmp{ i };
				sm[ch] = tmp;
			}
			else {
				sm[ch].push_back(i);
			}
		}

		std::cout << "=======================" << std::endl;
		//itPrint(sm);
		auto it = sm.begin();
		while (it != sm.end()) {

			std::cout << "Char : " << static_cast<char>((*it).first) << " -";
			auto second = (*it).second;
			auto it2 = second.begin();

			while (it2 != second.end()) {
				std::cout << " \"" << words[*it2] << "\"";
				it2++;
			}

			std::cout << std::endl;


			it++;
		}

	}

	//�)
	//�������� ��������� ������, ������� ����� ������� ���������� � ������������ �������.
	//��� ������ ������ ������ �������� ������� ��������� (�� ��������). ��� ���� 
	//������� ����� �������������
	//���� ������ ���� ������ ���� ����������� �� ������
	//
	//������ 
	{
		std::map<std::string, std::vector<std::string>> students{

					{"234", {"������", "�������","������", "�������", "�������"}},
					{"123", {"�����", "��������", "��������"}}
		};


		auto it = students.begin();
		while (it != students.end()) {
			std::vector<std::string> *tmp = &(*it).second;
			std::sort(tmp->begin(), tmp->end(),
				[](std::string const &a, std::string const &b)->bool { return a.compare(b) < 0; });
			it++;
		}

		itPrint(students);
	}



	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//�) �������� "�����-�������" �������, ��� ������ � ���� �� ����� ����� ���������������
	//		��������� ������� �������� - pair<string,string>, ��������: strange: �����, ��������...
	//�) ��������� ������� ������ � ������� ������ insert ��� ������������������ � ������� 
	//		���������������� ������� ���� (���� ����� �������������� ��� ��������� � ������� ������� make_pair)
	//�) �������� ��� ���������� ������� �� �����
	//�) �������� �� ����� ������ �������� "���������" ��� ��������� �����. ���������: ��� ���������� ���������
	//		���������� ����� ������������ ������ lower_bound() � upper_bound()

	{
		std::multimap<std::string, std::string> mp;
		mp.insert(
			std::make_pair<std::string, std::string>("hello", "������")
		);
		mp.insert(
			std::make_pair<std::string, std::string>("strange", "�����")
		);

		mp.insert(
			std::make_pair<std::string, std::string>("developer", "�����������")
		);
		mp.insert(
			std::make_pair<std::string, std::string>("developer", "����������")
		);
		mp.insert(
			std::make_pair<std::string, std::string>("developer", "����������")
		);
		mp.insert(
			std::make_pair<std::string, std::string>("strange", "��������")
		);


		itPrint(mp);

		std::string findValue = "developer";
		auto low = mp.lower_bound(findValue);
		auto upp = mp.upper_bound(findValue);

		std::cout << "=============== strange ================" << std::endl;

		while (low != upp) {
			std::cout << "Val: " << (*low).second << std::endl;
			low++;
		}

	}

	stop

		return 0;
}

