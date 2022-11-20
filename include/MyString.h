#pragma once
#include <iostream>
#include <string>

class TString
{
protected:
	char* str;
	int len;
public:
	TString();
	TString(const char* s);
	TString(int n, char c = 0);
	TString(const TString& s);
	~TString();

	int GetLen() const;

	TString operator+(const TString& s);
	TString& operator=(const TString& s);
	TString& operator+=(const TString& s);
	TString operator+(const char* s);
	TString& operator=(const char* s);
	TString& operator+=(const char* s);
	bool operator==(TString& s) const;
	bool operator==(const char* s) const;
	bool operator!=(TString& s) const;
	bool operator!=(const char* s) const;
	bool operator<(TString& s);
	bool operator>(TString& s);
	char& operator[](int i) const;

	friend std::ostream& operator<<(std::ostream& a, TString& b);
	//friend std::istream& operator>>(std::istream& a, TString& b);

	int find(char c);
	int find(TString& s);
	TString* split(char c, int& m);
	TString copyNTimes(int n);
	int* masIndex(TString& s, int& k);
	char& frequentElem();
	TString subStr(int b, int e) const;
	double srtToValue();
};

inline TString::TString()
{
	len = 0;
	str = new char[len + 1];
	str[len] = 0;
}

inline TString::TString(const char* s)
{
	int i = 0;
	if (s == 0)
	{
		throw "!";
	}
	while (s[i] != 0)
	{
		i = i + 1;
	}
	len = i;
	str = new char[len + 1];
	for (i = 0; i < len + 1; i++)
	{
		str[i] = s[i];
	}
}

inline TString::TString(int n, char c)
{
	if (n <= 0)
	{
		throw "!";
	}
	len = n;
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = c;
	}
	str[len] = 0;
}

inline TString::TString(const TString& s)
{
	len = s.len;
	str = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
	{
		str[i] = s.str[i];
	}
}

inline TString::~TString()
{
	if (str != nullptr)
	{
		delete[] str;
		str = 0;
	}
}

inline int TString::GetLen() const
{
	return len;
}

inline TString TString::operator+(const TString& s)
{
	TString res(len + s.len);
	for (int i = 0; i < len; i++)
	{
		res.str[i] = str[i];
	}
	for (int i = len; i < len + s.len + 1; i++)
	{
		res.str[i] = s.str[i - len];
	}
	return res;
}

inline TString& TString::operator=(const TString& s)
{
	if (this == &s)
	{
		return *this;
	}
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
	{
		str[i] = s.str[i];
	}
	return *this;
}

inline TString& TString::operator+=(const TString& s)
{
	int l = len + s.len;
	char* res = new char[l + 1];
	for (int i = 0; i < len; i++)
	{
		res[i] = str[i];
	}
	for (int i = len; i < l + 1; i++)
	{
		res[i] = s.str[i - len];
	}
	delete[] str;
	len = l;
	str = res;
	return *this;
}

inline TString TString::operator+(const char* s)
{
	int i = 0;
	if (s == 0)
	{
		throw "!";
	}
	while (s[i] != 0)
	{
		i = i + 1;
	}
	int l = i;
	TString res(len + l);
	for (int i = 0; i < len; i++)
	{
		res[i] = str[i];
	}
	for (int i = len; i < len + l; i++)
	{
		res[i] = s[i - len];
	}
	return res;
}

inline TString& TString::operator=(const char* s)
{
	int i = 0;
	if (s == 0)
	{
		throw "!";
	}
	while (s[i] != 0)
	{
		i = i + 1;
	}
	len = i;
	delete[] str;
	str = new char[len + 1];
	for (i = 0; i < len + 1; i++)
	{
		str[i] = s[i];
	}
	return *this;
}

inline TString& TString::operator+=(const char* s)
{
	int i = 0;
	if (s == 0)
	{
		throw "!";
	}
	while (s[i] != 0)
	{
		i = i + 1;
	}
	int l = len + i;
	char* res = new char[l + 1];
	for (int i = 0; i < len; i++)
	{
		res[i] = str[i];
	}
	for (int i = len; i < l + 1; i++)
	{
		res[i] = s[i - len];
	}
	delete[] str;
	len = l;
	str = res;
	return *this;
}

inline bool TString::operator==(TString& s) const
{
	if (len != s.len)
	{
		return false;
	}
	for (int i = 0; i <= len; i++)
	{
		if (str[i] != s.str[i])
		{
			return false;
		}
	}
	return true;
}

inline bool TString::operator==(const char* s) const
{
	int i = 0;
	while (s[i] != 0)
	{
		i = i + 1;
	}
	if (len != i)
	{
		return false;
	}
	for (int i = 0; i <= len; i++)
	{
		if (str[i] != s[i])
		{
			return false;
		}
	}
	return true;
}

inline bool TString::operator!=(TString& s) const
{
	if (len != s.len)
	{
		return true;
	}
	for (int i = 0; i <= len; i++)
	{
		if (str[i] != s.str[i])
		{
			return true;
		}
	}
	return false;
}

inline bool TString::operator!=(const char* s) const
{
	int i = 0;
	while (s[i] != 0)
	{
		i = i + 1;
	}
	if (len != i)
	{
		return true;
	}
	for (int i = 0; i <= len; i++)
	{
		if (str[i] != s[i])
		{
			return true;
		}
	}
	return false;
}

inline bool TString::operator<(TString& s)
{
	int l = len > s.len ? s.len : len;
	for (int i = 0; i < l; i++)
	{
		if (str[i] < s.str[i])
		{
			return true;
		}
		else if (str[i] > s.str[i])
		{
			return false;
		}
	}
	if (len > s.len)
	{
		return false;
	}
	else
	{
		return true;
	}
}

inline bool TString::operator>(TString& s)
{
	int l = len > s.len ? s.len : len;
	for (int i = 0; i < l; i++)
	{
		if (str[i] < s.str[i])
		{
			return false;
		}
		else if (str[i] > s.str[i])
		{
			return true;
		}
	}
	if (len > s.len)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline char& TString::operator[](int i) const
{
	if (str == 0)
	{
		throw "!";
	}
	if (i < 0 && i > len)
	{
		throw "!";
	}
	while (i <= 0)
	{
		i = i + len;
	}
	i = i % len;
	return str[i];
}

inline std::ostream& operator<<(std::ostream& a, TString& b)
{
	for (int i = 0; i < b.GetLen(); i++)
	{
		a << b[i];
	}
	return a;
}

//inline std::istream& operator>>(std::istream& a, TString& b)
//{
//	char s[100];
//	int i = 0;
//	a >> s;
//	while (s[i] != 0)
//	{
//		i = i + 1;
//	}
//	b.len = i;
//	delete[] b.str;
//	b.str = new char[b.len + 1];
//	for (i = 0; i < b.len; i++)
//	{
//		b.str[i] = s[i];
//	}
//	b.str[b.len] = 0;
//	return a;
//}

inline int TString::find(char c)
{
	for (int i = 0; i < len; i++)
	{
		if (str[i] == c)
		{
			return i;
		}
	}
	return -1;
}

inline int TString::find(TString& s)
{
	for (int i = 0; i < len - s.len + 1; i++)
	{
		bool f = true;
		for (int j = 0; j < s.len; j++)
		{
			if (str[i + j] != s.str[j])
			{
				f = false;
				break;
			}
		}
		if (f == true)
		{
			return i;
		}
	}
	return -1;
}

inline TString* TString::split(char c, int& m)
{
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == c)
		{
			k = k + 1;
		}
	}
	if (k == 0)
	{
		return 0;
	}
	k = k + 1;
	m = k;

	TString* mas = new TString[k];
	int j = 0;
	int start = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == c)
		{
			mas[j].len = i - start;
			delete[] mas[j].str;
			mas[j].str = new char[mas[j].len + 1];
			for (int p = 0; p < mas[j].len; p++)
				mas[j].str[p] = str[p + start];
			mas[j].str[mas[j].len] = 0;
			j = j + 1;
			start = i + 1;
		}
	}
	mas[j].len = len - start;
	delete[] mas[j].str;
	mas[j].str = new char[mas[j].len + 1];
	for (int i = 0; i < mas[j].len + 1; i++)
	{
		mas[j].str[i] = str[i + start];
	}
	return mas;
}

inline TString TString::copyNTimes(int n)
{
	TString res;
	for (int i = 0; i < n; i++)
	{
		res += str;
	}
	return res;
}

inline int* TString::masIndex(TString& s, int& x)
{
	int k = 0;
	for (int i = 0; i < len - s.len + 1; i++)
	{
		bool f = true;
		for (int j = 0; j < s.len; j++)
		{
			if (str[i + j] != s.str[j])
			{
				f = false;
				break;
			}
		}
		if (f == true)
		{
			k = k + 1;
		}
	}
	if (k == 0)
	{
		return 0;
	}
	x = k;

	int* mas = new int[k + 1];
	int t = 0;
	for (int i = 0; i < len; i++)
	{
		bool f = true;
		for (int j = 0; j < s.len; j++)
		{
			if (str[i + j] != s.str[j])
			{
				f = false;
				break;
			}
		}
		if (f == true)
		{
			mas[t] = i;
			t = t + 1;
		}
	}
	return mas;
}

inline char& TString::frequentElem()
{
	char symbols[256] = { 0 };
	int count[256] = { 0 }, max = 0, max_id = 0;
	for (int i = 0; i < 256; i++)
	{
		symbols[i] = (char)i;
	}
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			if (str[i] == symbols[j])
			{
				count[j]++;
			}
			if (count[j] > max)
			{
				max = count[j];
				max_id = j;
			}
		}
	}
	return symbols[max_id];
}

inline TString TString::subStr(int b, int l) const
{
	TString res(l, 0);
	for (int i = 0; i < l; i++)
	{
		res[i] = str[i + b];
	}
	return res;
}

inline double TString::srtToValue()
{
	double res = 0;
	try
	{
		res = std::stod(str);
	}
	catch (const std::exception&)
	{
		//...
	}
	return res;
}
