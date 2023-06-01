#include "initdata.h"
#include "map.h"

#include <iostream>
#include <list>
#include <filesystem>
#include <fstream>
#include <map>
#include <stdio.h>
#include <cstring>
using json = nlohmann::json;

const char *getTable()
{
    const char *tableName = "/.filixlib/InitData.dat";

    std::string c = Util::get_current_dir() + tableName;
    const char *tableNameStoreLocation = c.c_str();
    return tableNameStoreLocation;
}
class InitDataTbl
{
private:
    int ST_ID;
    std::string PKG;
    std::string TOKEN;
    std::string PWD;

public:
    int GETST_ID()
    {
        return ST_ID;
    }
    void ReadDetails(std::map<std::string, std::string> data)
    {
        Map mapObj(data);
        std::cout << "Mapping initilization data...";

        ST_ID = 1;
        PKG = "ddd";
        TOKEN = "fffff";
        PWD = "rrrrrrr";
        // PKG = mapObj.get("pkg");
        // TOKEN = mapObj.get("token");
        // PWD = mapObj.get("pwd");
    }

    void ShowDetails()
    {
        std::cout << "\tID student : " << ST_ID << std::endl;
        std::cout << "\tStudent Name : " << PKG << std::endl;
        std::cout << "\tStudent SGPA : " << TOKEN << std::endl;
        std::cout << "\tStudent SGPA : " << PWD << std::endl;
    }

    void ADDRECORD(std::map<std::string, std::string> data)
    {
        std::fstream fin;

        const char *tableName = "/.filixlib/InitData.dat";

        std::string c = Util::get_current_dir() + tableName;
        const char *tableNameStoreLocation = c.c_str();

        json jsonData; // Create an empty JSON object

        Map mapObj(data);
        std::cout << "Mapping initilization data...";

        // Add jsonData to the JSON object
        jsonData["pkg"] = mapObj.get("pkg");
        jsonData["token"] = mapObj.get("token");
        jsonData["java_version"] = mapObj.get("java_version");
        jsonData["pwd"] = mapObj.get("pwd");

        // Convert JSON object to string and print
        std::cout << jsonData.dump(4) << std::endl;
        std::string input = jsonData.dump(4);
        std::string base64 = cppcodec::base64_rfc4648::encode(input);

        // testing end

        // Save JSON object to a file
        std::ofstream file(tableNameStoreLocation, std::ios::in | std::ios::binary | std::ios::app);
        file << base64;
        file.close();
    }

    // void SEARCH(int id)
    // {
    // 	InitDataTbl S;
    // 	int flag=0;
    // 	fstream fin;
    // 	fin.open("Student.dat",ios::in|ios::binary|ios::app) ;
    // 	while(fin.read((char*)&S,sizeof(S)))
    // 	{
    // 		if(id==S.GETST_ID())
    // 		{
    // 			if(flag == 0)
    // 			cout<<"\n\t**Data Found**\n";
    // 			S.ShowDetails();
    // 			cout<<endl;
    // 			flag=1;
    // 		}
    // 	}
    // 	fin.close();
    // 	if(flag!=1)
    // 		 cout<<"\t***No match Found***";
    // }

    // void DELETE()
    // {
    // 	int dID,choice3;
    // 	STUDENT S;
    // 	int ff=0;
    // 	label2:
    // 	cout<<"\tEnter The Student ID whose record is to be DELETED : ";
    // 	cin>>dID;
    // 	fstream fin2;
    // 	fin2.open("temp.dat",ios::out|ios::binary|ios::in|ios::app);
    // 	fstream fin;
    // 	fin.open("Student.dat",ios::in|ios::binary|ios::app);
    // 	while(fin.read((char*)&S,sizeof(S)))
    // 	{
    // 		if(dID==S.GETST_ID())
    // 		{
    // 			cout<<"\n\tDATA FOUND : "<<endl;
    // 			ff=1;
    // 			S.ShowDetails();
    // 		}
    // 		else
    // 			fin2.write((char*)&S,sizeof(S)) ;
    // 	}
    // 	if(ff==0)
    // 	{
    // 		cout<<"\n\tDATA NOT FOUND\n\n";
    // 	}
    // 	else
    // 	{
    // 		cout<<"\n\tDo You Want to continue (1 for YES and 0 for NO) : ";
    // 		cin>>choice3;
    // 		if(choice3==1)
    // 		{
    // 			fin2.close();
    // 			fin.close();
    // 			remove("Student.dat");
    // 			rename("temp.dat","Student.dat");
    // 			cout<<endl;
    // 		}
    // }
    // }

    // void MODIFY()
    // {
    // 	cout<<"\tEnter new details \n\n";
    // 	int NewID;
    // 	char Newname[50];
    // 	float Newmarks;
    // 	cout<<"\tEnter new Student ID : ";
    // 	cin>>NewID;
    // 	cout<<"\tEnter new Student's Name : ";
    // 	cin.ignore();
    // 	cin.getline(Newname,50);
    // 	cout<<"\tEnter new Student's SGPA : ";
    // 	cin>>Newmarks;
    // 	ST_ID=NewID;
    // 	strcpy(ST_Name,Newname);
    // 	ST_Marks=Newmarks;
    // 	cout<<"\n\tData Updated. Thank You.\n";
    // }
};

bool isDataExist(int isDataOrTable)
{
    bool status = false;
    std::ifstream file(getTable(), std::ios::in | std::ios::binary | std::ios::app);
    if (file.is_open())
    {
        if (isDataOrTable == 1)
        {
            try
            {
                std::string base64;
                file >> base64;

                std::string decoded = cppcodec::base64_rfc4648::decode<std::string>(base64);

                std::cout << "Decoded: " << decoded << std::endl;
                json jsonData = nlohmann::json::parse(decoded);
                std::string pkg = jsonData["pkg"];

                // // Print the data
                std::cout << "pkg: " << pkg << std::endl;

                file.close();
                status = true;
            }
            catch (...)
            {
                status = false;
            }
        }
        else if (isDataOrTable = 2)
        {
            status = true;
        }
        // json data;
    }
    else
    {
        status = false;
    }
    return status;
}
void ShowRecord()
{
    InitDataTbl S;
    std::fstream fin;
    int ff = 0;

    const char *tableName = "/.filixlib/InitData.dat";

    std::string c = Util::get_current_dir() + tableName;
    const char *tableNameStoreLocation = c.c_str();

    std::ifstream file(tableNameStoreLocation, std::ios::in | std::ios::binary | std::ios::app);
    if (file.is_open())
    {
        // json data;
        std::string base64;
        file >> base64;

        std::string decoded = cppcodec::base64_rfc4648::decode<std::string>(base64);

        std::cout << "Decoded: " << decoded << std::endl;
        json jsonData = nlohmann::json::parse(decoded);
        std::string pkg = jsonData["pkg"];

        // // Print the data
        std::cout << "pkg: " << pkg << std::endl;

        file.close();
    }
    else
    {
        std::cerr << "Failed to open the file." << std::endl;
    }
}

void InitData::Insert(std::map<std::string, std::string> data)
{
    // std::cout << "\t\t***InitData RECORD***\n";
    // std::cout << Util::get_current_dir();

    InitDataTbl myObj; // Create an object of MyClass
    if (isDataExist(2) == false)
    {
        myObj.ADDRECORD(data); // Call the method
    }
    // std::cout << "testing....";
    ShowRecord();
    // InitDataTbl S = new InitDataTbl();

    // S::ADDRECORD();
}
