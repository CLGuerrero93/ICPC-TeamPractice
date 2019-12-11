//Solution to Tongues
//Regionals 2012 Pacific Northwest

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ifstream inf;
  ofstream outf;
  string file, input, output; //input filename, line from file, line to be output

  string vowels = "aiyeou";
  string VOWELS = "AIYEOU";
  string consonants = "bkxznhdcwgpvjqtsrlmf";
  string CONSONANTS = "BKXZNHDCWGPVJQTSRLMF";
  size_t counter = -1; //to make a circular list

  cout<<"Filename: ";
  cin>>file;

  inf.open(file.c_str());
  outf.open("tonguesoutput.txt");

  if(inf.is_open() && outf.is_open())
    {
      while(!inf.eof())
	     {
	       getline(inf, input);
	       output = " ";

	       for(int i = 0; i<input.length(); i++) //for each char in input string
	        {
	          counter = -1; //-1 means the char was not found
	          counter = vowels.find(input[i]);//is it a lowercase vowel
	          if(counter >= 0 && counter < 6)
		          {
		            counter += 3;
		            if(counter > 5)
		              counter = counter % 6;
		            output += vowels[counter];
		          }

	          else
    		      {
		            counter = VOWELS.find(input[i]);
		            if(counter >= 0 && counter < 6)//is it an uppercase vowel
		              {
		                counter += 3;
		                if(counter > 5)
			                counter = counter % 6;
		                output += VOWELS[counter];
		              }

		            else
		              {
		                counter = consonants.find(input[i]);//lowercase consonant
		                if(counter >= 0 && counter < 20)
			                {
			                  counter += 10;
			                  if(counter > 19)
			                    counter = counter % 20;
			                  output += consonants[counter];
			                }

		                else
			                {
			                  counter = CONSONANTS.find(input[i]);//capital consonant
			                  if(counter>=0 && counter < 20)
			                    {
			                      counter += 10;
			                      if(counter > 19)
				                      counter = counter % 20;
			                      output += CONSONANTS[counter];
			                    }

			                  else //space or punctuation
			                    output += input[i];
			                 }
		              }
		          }
	       }

	     outf<<output<<endl;
	   }
  }

  return 0;
}
