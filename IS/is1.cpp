#include<iostream>
#include<string.h>
using namespace std;

int main(){
    
    int n,ch;
    do{
    string msg,emsg;
    cout << "\n********************\n1. Encrypt Message:";
    cout << "\n2. Decrypt Message:";
    cout << "\npress any other key to EXIT.\n********************";
    cout << "\nEnter your choice:";
    cin >> ch;
	switch(ch)
	{
	case(1):
		cout<< "\n\t\t\tEnter the Message:"<<endl;
		//cin >> msg;
		cin.ignore();
		getline(cin,msg);
		cout << "\t\t\tEnter the Key:";
		cin >> n;
		for(int i=0; i<msg.length(); i++)
		{
		    if(msg[i]>='a' && msg[i]<='z' || msg[i]>='A' && msg[i]<='Z'|| msg[i]==' ')
		    {
		        int tmp = int(msg[i]);
		        if(tmp == 32){emsg+=(char)tmp;}
		        if(tmp > 64 && tmp < 91)
		        {
		            tmp+=n;
		            if(tmp > 90)
		            {
		                tmp = 64 + (tmp-90);
		            }
		            emsg+=(char)tmp;                
		        }
		        else if(tmp > 96 && tmp < 123)
		        {
		            tmp+=n;
		            if(tmp>122)
		            {
		                tmp = 96 + (tmp-122);
		            }
		            emsg+=(char)tmp;
		        }                                                                                                                                  
		    }
		    else
		    cout << "\t\t\tEnter valid input";
		} 
		cout << "\n\t\t\tEncrypted Message: " << emsg<<endl<<endl;
		msg=emsg="";
		break;
	case(2):
		cout<< "\n\t\t\tEnter the Encrypted Message:";
		//cin >> emsg;
		cin.ignore();
		getline(cin,emsg);
		cout << "\t\t\tEnter the Key:";
		cin >> n;
		for(int i=0; i<emsg.length(); i++)
		{
		    if(emsg[i]>='a' && emsg[i]<='z' || emsg[i]>='A' && emsg[i]<='Z' || emsg[i]==' ')
		    {
		        int tmp = int(emsg[i]);
		        if(tmp == 32){msg+=(char)tmp;}
		        if(tmp > 64 && tmp < 91)
		        {
		            tmp-=n;
		            if(tmp < 65)
		            {
		                tmp = 91 - (65-tmp);
		            }
		            msg+=(char)tmp;                
		        }
		        else if(tmp > 96 && tmp < 123)
		        {
		            tmp-=n;
		            if(tmp<97)
		            {
		                tmp = 123 - (97-tmp);
		            }
		            msg+=(char)tmp;
		        }                                                                                                                                  
		    }
		    else
		    cout << "\t\t\tEnter valid input";
		}
		cout << "\n\t\t\tDecrypted message: "<< msg<<endl<<endl;
		msg=emsg="";
		break;
	default:
		break;	
	}	

	}while(ch==1 || ch== 2);
    
}
