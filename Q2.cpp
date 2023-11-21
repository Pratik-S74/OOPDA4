#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
class ViolationINFO
{
    public:
    string VehicleNumber;
    string ReportType;
    string ReportLocation;
};
class Traffic{
    private:
    int NumOfVehicles;
    static const int TotalVehicles=500;
    ViolationINFO info[TotalVehicles];

    public:
    Traffic(): NumOfVehicles(0){}

    void removeQuotes(string& str) {
    str.erase(remove(str.begin(), str.end(), '\"'), str.end());
    }
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
        if(NumOfVehicles>=TotalVehicles)
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
        removeQuotes(token);
        info[NumOfVehicles].VehicleNumber=token;
        getline(ss,token,',');
        removeQuotes(token);
        info[NumOfVehicles].VehicleNumber+=token;
        getline(ss,token,',');
        removeQuotes(token);
        info[NumOfVehicles].ReportType=token;
        getline(ss,token,',');
        removeQuotes(token);
        info[NumOfVehicles].ReportLocation=token;
        ++NumOfVehicles;
        
    }
    file.close();
    }

    void printInformation()
    {
        for (int i=0;i<NumOfVehicles;i++)
        {
        cout<< "City code: "<<info[i].VehicleNumber<<endl;
        cout<<"Vehicle Number: "<<info[i].ReportType<<endl;
        cout<<"Owner Firstname: "<<info[i].ReportLocation<<endl;
        }
    }

};


int main()
{
    Traffic object;
    object.ReadCSV("A4-Q2.csv");
    object.printInformation();
}