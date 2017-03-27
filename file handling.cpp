#include <iostream>
#include <fstream>
#include <string> 
using namespace std;
char data[200],prog[40];
int x;
	char ch;
    ifstream x1,x2,x3;
    ofstream o1,o2,o3;
int main () 
{
	cout<<" result.txt";
	 	x1.open ("infile.txt",ios::in); 
		o1.open ("result.txt",ios::trunc|xos::out);
		cout<<"\nenter file(f/m/r/s):";
		cin>>ch;		
		
		while(!x1.eof())
		{		
			x1.getline(data,200);
			
			if(data[9]==ch)
		{

				o1<<data<<endl;
			}				
		}
  		x1.close();
		o1.close();
	

	cout<<"cleared.txt";
		x2.open("result.txt",ios::in);
		o2.open("cleared.txt",ios::trunc|ios::out);
		while(!i2.eof())
		{     
			i2.getline(data,200);
			for(x=13;x<200;x++)
			{
			o2<<data[x];
		    }
		    o2<<endl;
					 
	   }
		
		x2.close();
		o2.close();
	
	cout<<"final.bat\n";
		x3.open ("cleared.txt",ios::in); 
		o3.open ("final.bat",ios::trunc|ios::out);
		cout<<"program wanted to associate\n";
		cin>>prog;
		while(!x3.eof())
		{
		    x3.getline(data,200);
			o3<<prog<<data<<endl;
			
		}
		
		x3.close();
		o3.close();
return 0;
}
	
