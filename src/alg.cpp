#include  "bst.h"
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>

BST<std::string> makeTree(char* filename)
{
  ifstream f;
  f.open(filename);
  std::string str;
  BST<std::string> bst;
  std::string str1 = '';
  
  while(getline(f, str))
  {
    for(int i = 0; i <strlen(str); i++)
    {
      if(str[i + 1] != 32)
      {
        str1 += str[i]; 
      }
      else
      {
        bst.add(str1); 
      }
    }
    str1 = '';
  }
  
  f.close(filename);
}
