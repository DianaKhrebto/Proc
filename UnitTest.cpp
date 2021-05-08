#include "pch.h"
#include "CppUnitTest.h"

#include "../4lab/Header.h"
#include "../4lab/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(In_Tree_Test) //Тест проверки ввода информации о дереве
		{
			//Создаем и заполняем предполагаемые данные
			Tree T_exp;

			T_exp.Age = 418;

			ifstream ifst("../4lab/in_tree.txt");

			Tree T_act;

			In_Tree(T_act, ifst);

			Assert::AreEqual(T_exp.Age, T_act.Age);
		}
		TEST_METHOD(In_Shrub_Test) //Тест проверки ввода информации о кустарнике
		{
			//Создаем и заполняем предполагаемые данные
			Shrub S_exp;

			S_exp.M = S_exp.JENUARY;

			ifstream ifst("../4lab/in_shrub.txt");

			Shrub S_act;

			In_Shrub(S_act, ifst);

			Assert::AreEqual((int)S_exp.M, (int)S_act.M);
		}
		TEST_METHOD(In_Flower_Test) //Тест проверки ввода информации о цветке
		{
			//Создаем и заполняем предполагаемые данные
			Flower F_exp;

			F_exp.T = F_exp.WILD;

			ifstream ifst("../4lab/in_flower.txt");

			Flower F_act;

			In_Flower(F_act, ifst);

			Assert::AreEqual((int)F_exp.T, (int)F_act.T);
		}
		TEST_METHOD(In_Plant_Test) //Тест проверки ввода растения на примере дерева
		{
			//Создаем и заполняем предполагаемые данные
			Tree T_exp;

			T_exp.Age = 418;

			Plant* P_exp = new Plant;

			P_exp->Name = "Oak";
			P_exp->K = TREE;
			P_exp->T = T_exp;
			P_exp->H = TAIGA;

			ifstream ifst("../4lab/in_plant.txt");

			Plant* P_act = new Plant;

			P_act = In_Plant(ifst);

			Assert::AreEqual(P_exp->Name, P_act->Name);
			Assert::AreEqual((int)P_exp->K, (int)P_act->K);
			Assert::AreEqual((int)P_exp->H, (int)P_act->H);

			Assert::AreEqual(T_exp.Age, P_act->T.Age);
		}
		TEST_METHOD(Out_Tree_Test)
		{
			//Описываем фактическую информацию
			Tree T_act;

			T_act.Age = 4391;

			ofstream ofst("../4lab/out_tree_act.txt");

			Out_Tree("Baobab", STEPPE, T_act, ofst);

			ifstream ifst_exp("../4lab/out_tree_exp.txt");
			ifstream ifst_act("../4lab/out_tree_act.txt");

			//Считываем то, что вывели, а также то, что предполагали увидеть при выводе
			string Expected;
			getline(ifst_exp, Expected, '\0');
			string Actual;
			getline(ifst_act, Actual, '\0');

			//Сравниваем
			Assert::AreEqual(Expected, Actual);
		}
		TEST_METHOD(Out_Shrub_Test)
		{
			//Описываем фактическую информацию
			Shrub S_act;

			S_act.M = S_act.MAY;

			ofstream ofst("../4lab/out_shrub_act.txt");

			Out_Shrub("Syringa", STEPPE, S_act, ofst);

			ifstream ifst_exp("../4lab/out_shrub_exp.txt");
			ifstream ifst_act("../4lab/out_shrub_act.txt");

			//Считываем то, что вывели, а также то, что предполагали увидеть при выводе
			string Expected;
			getline(ifst_exp, Expected, '\0');
			string Actual;
			getline(ifst_act, Actual, '\0');

			//Сравниваем
			Assert::AreEqual(Expected, Actual);
		}
		TEST_METHOD(Out_Flower_Test)
		{
			//Описываем фактическую информацию
			Flower F_act;

			F_act.T = F_act.WILD;

			ofstream ofst("../4lab/out_flower_act.txt");

			Out_Flower("Chamomile", TAIGA, F_act, ofst);

			ifstream ifst_exp("../4lab/out_flower_exp.txt");
			ifstream ifst_act("../4lab/out_flower_act.txt");

			//Считываем то, что вывели, а также то, что предполагали увидеть при выводе
			string Expected;
			getline(ifst_exp, Expected, '\0');
			string Actual;
			getline(ifst_act, Actual, '\0');

			//Сравниваем
			Assert::AreEqual(Expected, Actual);
		}
		TEST_METHOD(Out_Plant_Test) //Тест вывода растения на примере дерева
		{
			//Описываем фактическую информацию
			Tree T_act;

			T_act.Age = 4391;

			Plant* P_act = new Plant;

			P_act->Name = "Baobab";
			P_act->K = TREE;
			P_act->H = STEPPE;
			P_act->T = T_act;

			ofstream ofst("../4lab/out_plant_act.txt");

			Out_Plant(P_act, ofst);

			ifstream ifst_exp("../4lab/out_plant_exp.txt");
			ifstream ifst_act("../4lab/out_plant_act.txt");

			//Считываем то, что вывели, а также то, что предполагали увидеть при выводе
			string Expected;
			getline(ifst_exp, Expected, '\0');
			string Actual;
			getline(ifst_act, Actual, '\0');

			//Сравниваем
			Assert::AreEqual(Expected, Actual);
		}
		TEST_METHOD(Consonant_letters_Test)
		{
			Plant* P = new Plant;

			P->K = TREE;
			P->Name = "Oak";

			int Consonant_letters_Exp = 1;
			int Consonant_letters_Act = Plant_consonant_letters(P);

			Assert::AreEqual(Consonant_letters_Exp, Consonant_letters_Act);
		}
		TEST_METHOD(Compare_Test)
		{
			Plant* P_First = new Plant;

			P_First->K = TREE;
			P_First->Name = "Oak";

			Plant* P_Second = new Plant;

			P_Second->K = TREE;
			P_Second->Name = "Baobab";

			bool Act = Compare(P_First, P_Second);
			bool Exp = false;

			Assert::AreEqual(Exp, Act);
		}
		TEST_METHOD(Sort_Test)
		{
			//Введем информацию из файла
			ifstream ifst("../4lab/input.txt");

			Container* Head = new Container();

			Init_Container(Head);

			In_Container(Head, ifst);

			ofstream ofst("../4lab/sort_act.txt");

			Sort(Head);

			//Выведем отсортированный контейнер
			Out_Container(Head, ofst);

			//Считаем то, что вывели ранее, и то, что должно было получиться при сортировке 
			ifstream ifst_exp("../4lab/sort_exp.txt");
			ifstream ifst_act("../4lab/sort_act.txt");

			//Сравниваем
			string Exp;
			getline(ifst_exp, Exp, '\0');
			string Act;
			getline(ifst_act, Act, '\0');

			Assert::AreEqual(Exp, Act);
		}
	};
}
