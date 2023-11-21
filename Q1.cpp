#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
class RegisterdVehicles{

    public:
    string VehicleNum;
    string FirstName;
    string LastName;
    int Age;
    string Gender;
    string Address;


};
class TrafficDepartment{
    private:
    static const int TotalVehicles=1000;
    RegisterdVehicles VehiclesInfo[TotalVehicles];
    int NumberOfVehicles;

    public:
    TrafficDepartment(): NumberOfVehicles(0){}

    void ReadCSV(const string& filename)
    {
    ifstream file(filename);
    if(!file.is_open())
    {
        cerr<<"There is an error reading the file"<<endl;
    }
    bool firstrow=false;
    string line;
    while(getline(file,line))
    {
        if(NumberOfVehicles>=TotalVehicles)
        {
            cout<<"You have reached end of the file, there is no more data"<<endl;
            break;
        }
        istringstream ss(line);
        string token;
        //skippin the row containing labels
        if(!firstrow)
        {
            firstrow=true;
            getline(ss,token,',');
            continue;
        }
        getline(ss,token,',');
        VehiclesInfo[NumberOfVehicles].VehicleNum=token;
        getline(ss,token,',');
        VehiclesInfo[NumberOfVehicles].VehicleNum+=token;
        getline(ss,token,',');
        VehiclesInfo[NumberOfVehicles].FirstName=token;
        getline(ss,token,',');
        VehiclesInfo[NumberOfVehicles].LastName=token;
        getline(ss,token,',');
        VehiclesInfo[NumberOfVehicles].Age=atoi(token.c_str());
        getline(ss,token,',');
        VehiclesInfo[NumberOfVehicles].Gender=token;
        getline(ss,token,',');
        VehiclesInfo[NumberOfVehicles].Address=token;

        ++NumberOfVehicles;
        
    }
    file.close();
    }

    void printInformation()
    {
        for (int i=0;i<NumberOfVehicles;i++)
        {
        cout<<"Vehicle Number: "<<VehiclesInfo[i].VehicleNum<<endl;
        cout<<"Owner Firstname: "<<VehiclesInfo[i].FirstName<<endl;
        cout<<"Owner lastname: "<<VehiclesInfo[i].LastName<<endl;
        cout<<"Owner Age: "<<VehiclesInfo[i].Age<<endl;
        cout<<"Owner Gender: "<<VehiclesInfo[i].Gender<<endl;
        cout<<"Owner Address: "<<VehiclesInfo[i].Address<<endl;

        }
    }

};
int main()
{
   TrafficDepartment trafficDep;
   trafficDep.ReadCSV("/home/pratik_s/Downloads/OOPDA4/A4-Q1.csv");
   trafficDep.printInformation();


}