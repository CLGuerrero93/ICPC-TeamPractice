#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ifstream ifs;
  ofstream ofs;

  ifs.open("roman.input");
  ofs.open("roman.output");

  //  if(ifs.is_open() && ofs.is_open())
    
      while(!ifs.eof())
	{
	  string line, roman;
	  size_t position = 0;
	  size_t p = 0;
	  int numeral[10];
	  getline(ifs, line);
	  while(p!=string::npos)
	    {
	      p = line.find_first_of(" ", position);
	      cout<<p<<endl;	      
	      roman = line.substr(position, p);
	      position = p;
	      for (int i = 0; i<roman.length(); i++)
		{
		  if(roman[i] == 'I')
		    numeral[i] = 1;
		  else if(roman[i] == 'V')
		    numeral[i]=5;
		  else if(roman[i] == 'X')
		    numeral[i]=10;
		  else if(roman[i] == 'L')
		    numeral[i]=50;
		  else if(roman[i] == 'C')
		    numeral[i]=100;
		}
	      int number;
	      for(int i = 0; i<roman.length(); i++)
		number += numeral[i];
	      if (numeral[0]<numeral[1])
		number--;
	      ofs<<number<<endl;
	    }
	}
    }

