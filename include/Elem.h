#pragma once
#include "MyString.h"

class TElem
{
protected:
  TString op;
  double vl;
  TString strvl;
public:
  TElem();
  TElem(TString _op);
  TElem(double _vl);
  TElem(const TElem& e);

  void setOperstion(TString _op);
  void setValue(double _vl);
  void setStrVal(TString _strvl);
  TString& getOperation();
  double& getValue();
  TString& getStrVal();

  TElem& operator=(const TElem& e);

  bool isEmpty();
  bool isValue();
  bool isOperation();
  bool isStrVal();
  void tryStrValToValue();
};

inline TElem::TElem()
{
  op = "";
  vl = 0;
  strvl = "";
}

inline TElem::TElem(TString s)
{
  vl = 0;
  if (s[0] == '(' || s[0] == ')' || s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/' || s[0] == '^')
  {
    op = s;
  }
  else
  {
    strvl = s;
  }
}

inline TElem::TElem(double _vl)
{
  vl = _vl;
}

inline TElem::TElem(const TElem& e)
{
  op = e.op;
  vl = e.vl;
  strvl = e.strvl;
}

inline void TElem::setOperstion(TString _op)
{
  op = _op;
  vl = 0;
  strvl = "";
}

inline void TElem::setValue(double _vl)
{
  op = "";
  vl = _vl;
}

inline void TElem::setStrVal(TString _strvl)
{
  op = "";
  vl = 0;
  strvl = _strvl;
}

inline TString& TElem::getOperation()
{
  return op;
}

inline double& TElem::getValue()
{
  return vl;
}

inline TString& TElem::getStrVal()
{
  return strvl;
}

inline TElem& TElem::operator=(const TElem& e)
{
  if (this == &e)
  {
    return *this;
  }
  op = e.op;
  vl = e.vl;
  strvl = e.strvl;
  return *this;
}

inline bool TElem::isEmpty()
{
  if (op == "" && vl == 0 && strvl == "")
  {
    return true;
  }
  else
  {
    return false;
  }
}

inline bool TElem::isValue()
{
  try
  {
    if (op == "" && strvl.srtToValue() == vl)
    {
      return true;
    }
  }
  catch (const std::exception&)
  {
    return false;
  }
}

inline bool TElem::isOperation()
{
  if (op != "" && vl == 0 && strvl == "")
  {
    return true;
  }
  else
  {
    return false;
  }
}

inline bool TElem::isStrVal()
{
  if (op == "" && vl == 0 && strvl != "")
  {
    return true;
  }
  else
  {
    return false;
  }
}

inline void TElem::tryStrValToValue()
{
  try
  {
    vl = strvl.srtToValue();
  }
  catch (const std::exception&)
  {
    //¯\_(ツ)_/¯
  }
}