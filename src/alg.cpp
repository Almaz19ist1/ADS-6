#include  "bst.h"
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>

BST<std::string> makeTree(char* filename)
{	
  std::string str;
	std::ifstream f(filename);
	BST<std::string> *bst = new BST<std::string>;
	char str1 = "";
	while (!f.eof())
  {
 	while ( str1 < 65 && (!f.eof()) ) 
		{
			f.get(str1);
		}
    	while (  str1 >= 65  && (!f.eof()))
    {
	   if (str1 >= 65 && str1 <= 90)
	  {
		  str += str1;	
	  }
	  if (str1 >= 97 && str1 <= 122)
	  {
		  str += str1;
	  }
	  f.get(str);	
  }
	for (int i = 0; i < str.length(); i++)
	{
	if (str[i] >= 65 && str[i] <= 90)
	str[i] += 32;
	}
(*bst).add(str);
str = "";
close(f);
return *bst;
}
