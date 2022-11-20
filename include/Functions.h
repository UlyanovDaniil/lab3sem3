#pragma once
#include <iostream>
#include "Stack.h"
#include "Elem.h"

TElem* masElem(const TString& s, int& k)
{
	int i = 0, j = 0, kos = 0, kcs = 0, ko = 0, kv = 0;
	TElem* fres = new TElem[s.GetLen()];
	k = 0;

	while (i < s.GetLen())
	{
		if (s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
		{
			fres[k].setOperstion(s.subStr(i, 1));
			k++;
		}
		else if (s[i] != ' ')
		{
			j = i;
			while (s[j] != '(' && s[j] != ')' && s[j] != '+' && s[j] != '-' && s[j] != '*' && s[j] != '/' && s[j] != '^' && s[j] != ' ' && j < s.GetLen())
			{
				j++;
			}
			fres[k].setStrVal(s.subStr(i, j - i));
			k++;
			i = j - 1;
		}
		i++;
	}

	TElem* res = new TElem[k];
	for (int i = 0; i < k; i++)
	{
		res[i] = fres[i];
	}
	delete[] fres;

	for (int i = 0; i < k; i++)
	{
		if (res[i].isOperation())
		{
			if (res[i].getOperation() == "(")
			{
				kos++;
			}
			else if (res[i].getOperation() == ")")
			{
				kcs++;
			}
			else
			{
				ko++;
			}
		}
		if (res[i].isValue() || res[i].isStrVal())
		{
			kv++;
		}
	}
	if (kos != kcs || ko + 1 != kv)
	{
		throw "str enter fail";
	}

	return res;
}

int Priority(const TString& s)
{
	if (s == "^")
	{
		return 4;
	}
	if (s == "*" || s == "/")
	{
		return 3;
	}
	if (s == "+" || s == "-")
	{
		return 2;
	}
	if (s == "(")
	{
		return 1;
	}
	return 0;
}

TString PlshRcrd(const TString& s)
{
	TString res;
	int k = 0;
	TElem* mas = masElem(s, k);
	TStack<TElem> opSt(k);
	TElem tmp;

	for (int i = 0; i < k; i++)
	{
		if (mas[i].isValue() || mas[i].isStrVal())
		{
			res += mas[i].getStrVal() + " ";
		}
		if (mas[i].isOperation())
		{
			if (mas[i].getOperation() == "(")
			{
				opSt.Push(mas[i]);
			}
			else if (mas[i].getOperation() == ")")
			{
				tmp = opSt.Pop();
				while (tmp.getOperation() != "(")
				{
					res += tmp.getOperation() + " ";
					tmp = opSt.Pop();
				}
			}
			else
			{
				if (!opSt.isEmpty())
				{
					tmp = opSt.Pop();
				}
				if (Priority(tmp.getOperation()) < Priority(mas[i].getOperation()))
				{
					opSt.Push(tmp);
					opSt.Push(mas[i]);
				}
				else
				{
					while (!opSt.isEmpty() && Priority(tmp.getOperation()) >= Priority(mas[i].getOperation()))
					{
						res += tmp.getOperation() + " ";
						tmp = opSt.Pop();
					}
					opSt.Push(tmp);
					opSt.Push(mas[i]);
				}
			}
		}
	}
	while (!opSt.isEmpty())
	{
		res += opSt.Pop().getOperation() + " ";
	}

	return res;
}

double Postfix(const TString& s)
{
	double res = 0;
	int k = 0;
	TElem* mas = masElem(s, k);
	TStack<TElem> opSt(k);

	for (int i = 0; i < k; i++)
	{
		if (mas[i].isStrVal())
		{
			mas[i].tryStrValToValue();
			if (mas[i].isValue())
			{
				opSt.Push(mas[i]);
			}
			else
			{
				throw "string_value";
			}
		}
		else if (mas[i].isOperation())
		{
			TString op = (mas[i].getOperation());
			double c = opSt.Pop().getValue();
			if (op == "*")
			{
				double b = opSt.Pop().getValue();
				TElem e(b * c);
				opSt.Push(e);
			}
			else if (op == "/")
			{
				double b = opSt.Pop().getValue();
				TElem e(b / c);
				opSt.Push(e);
			}
			else if (op == "^")
			{
				double b = opSt.Pop().getValue();
				TElem e(std::pow(b, c));
				opSt.Push(e);
			}
			else if (op == "+")
			{
				double b = opSt.Pop().getValue();
				TElem e(b + c);
				opSt.Push(e);
			}
			else if (op == "-")
			{
				double b = opSt.Pop().getValue();
				TElem e(b - c);
				opSt.Push(e);
			}
		}
	}

	res = opSt.Pop().getValue();

	return res;
}