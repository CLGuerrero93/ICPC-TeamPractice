#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream ifs;
	ofstream ofs;
	
	ifs.open ("easyscriptin.txt");
	ofs.open ("easyscriptout.txt");
	
	if (ifs.is_open() && ofs.is_open())
	{
		while(!ifs.eof())
		{
			string L = " ";
			getline(cin, L);
			int paragraph = 1;
			bool pchange = false;
			if (L == "/n" && pchange == false)
			{
				ofs<<"/n";
				paragraph++;
				pchange = true;
			}
			else
			{
		//		getline (cin, L);
				int numwords = 0;
				size_t p = 0;
				size_t position = 0;
				
				while (p != -1)
				{
					p = L.find(" ");
					position = p;
					numwords++;
				}
				
				string arrayL[numwords];
				
				for (int i = 0; i < numwords; i++)
				{
					size_t position = 0;
					size_t p = L.find(" ");
					string str = (position, p);
					arrayL[i] = str;
				}
				
				if (pchange == true)
				{
					for (i = 0; i<numwords; i++)
						ofs<<arrayL[i];
				}
				
				else
				{
					for (i = numwords -1; i >= 0; i--)
						ofs<<arrayL[i];
				}
			}
		}
	else
		cout<<"Error opening file."<<endl;
	}
	
	return 0;
}

	