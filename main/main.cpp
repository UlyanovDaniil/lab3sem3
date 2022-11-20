#include <iostream>
#include "Functions.h"

int main()
{
  TString s1 = "12+3-7";
  TString s2 = "a+b-c";
  TString s3 = "12-(34+999)";
  TString s4 = "regeg+rver*erbrb-(rwge*rvv-wrh)";
  TString s5 = "0.1*4-5*6^1.5";

  std::cout << PlshRcrd(s1) << "\n";
  std::cout << PlshRcrd(s2) << "\n";
  std::cout << PlshRcrd(s3) << "\n";
  std::cout << PlshRcrd(s4) << "\n";
  std::cout << PlshRcrd(s5) << "\n";

  TString ps1 = "s";
  TString ps2 = "12 11.2 44 / + 11 7 8 4.4 44.3 * + * - -";
  TString ps3 = "12 33.3 * 7 - 8 9 + /";

  std::cout << Postfix(ps1) << "\n";
  std::cout << Postfix(ps2) << "\n";
  std::cout << Postfix(ps3) << "\n";

  std::cout << Postfix(PlshRcrd("12+3*1-(23.4^(3-0.34))"));

  return 0;
}