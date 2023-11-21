#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class VehiclesInfoQ1{
    public:
    string VehicleNum;
    string OwnerFirstName;
    string OwnerLastName;
    int Age;
    string OwnerAddress;
};

class TrafficDepartmentQ1{
    private:
    static const int TotalVehicles=1000;
    VehiclesInfoQ1 VehiclesInfo[TotalVehicles];
    int NumberOfVehicles;

    public:
    TrafficDepartmentQ1(): NumberOfVehicles(0){}

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
            VehiclesInfo[NumberOfVehicles].OwnerFirstName=token;
            getline(ss,token,',');
            VehiclesInfo[NumberOfVehicles].OwnerLastName=token;
            getline(ss,token,',');
            // VehiclesInfo[NumberOfVehicles].Age=atoi(token.c_str());
            getline(ss,token,',');
            // VehiclesInfo[NumberOfVehicles].Gender=token;
            getline(ss,token,',');
            VehiclesInfo[NumberOfVehicles].OwnerAddress=token;

            ++NumberOfVehicles;
            
        }
        file.close();
    }

    void printInformation()
    {
        for (int i=0;i<NumberOfVehicles;i++)
        {
            cout<<"Vehicle Number: "<<VehiclesInfo[i].VehicleNum<<endl;
            cout<<"Owner Firstname: "<<VehiclesInfo[i].OwnerFirstName<<endl;
            cout<<"Owner lastname: "<<VehiclesInfo[i].OwnerLastName<<endl;
            cout<<"Owner Address: "<<VehiclesInfo[i].OwnerAddress<<endl;

        }
    }

    const VehiclesInfoQ1* GetInfo() const{
        return VehiclesInfo;
    }
    int GetNumberOfVehicles() const{
        return NumberOfVehicles;
    }
};
//for Q2 CSV file
class ViolationRelated{
    public:
    string ViolationVehicleNumber;
    string ReportType;
    string ReportLocation; 
};

class ViolationDatabase{
    private:
    int NumberOfVehicles;
    static const int TotalVehicles=500;
    ViolationRelated ViolationVehicleInfo[TotalVehicles];

    public:
    ViolationDatabase(): NumberOfVehicles(0){}

    void removeQuotes(string& str){
    str.erase(remove(str.begin(), str.end(), '\"'), str.end());
    }
    void ReadCSV(const string& filename){
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
            removeQuotes(token);
            ViolationVehicleInfo[NumberOfVehicles].ViolationVehicleNumber=token;
            getline(ss,token,',');
            removeQuotes(token);
            ViolationVehicleInfo[NumberOfVehicles].ViolationVehicleNumber+=token;
            getline(ss,token,',');
            removeQuotes(token);
            ViolationVehicleInfo[NumberOfVehicles].ReportType=token;
            getline(ss,token,',');
            removeQuotes(token);
            ViolationVehicleInfo[NumberOfVehicles].ReportLocation=token;
            ++NumberOfVehicles;

        
        }
        file.close();
    }

    const ViolationRelated* GetInfo() const{
        return ViolationVehicleInfo;
    }

    int GetNumberOfVehicle() const{
        return NumberOfVehicles;
    }
};
//for Q3 CsV file
class UpdatedINFO
{
    public:
    string FirstName;
    string LastName;
    string UpdateAddress;
};
class TrafficDatabaseQ3{
    private:
    int NumberOfVehicles;
    static const int TotalUpdates=500;
    UpdatedINFO info[TotalUpdates];

    public:
    TrafficDatabaseQ3(): NumberOfVehicles(0){}
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
        if(NumberOfVehicles>=TotalUpdates)
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
        info[NumberOfVehicles].FirstName=token;
        getline(ss,token,',');
        info[NumberOfVehicles].LastName+=token;
        getline(ss,token,',');
        getline(ss,token,',');
        getline(ss,token,',');
        info[NumberOfVehicles].UpdateAddress=token;
        ++NumberOfVehicles;
        
    }
    file.close();
    }

    void printInformation()
    {
        for (int i=0;i<NumberOfVehicles;i++)
        {
        cout<< "Owner First Name is: "<<info[i].FirstName<<endl;
        cout<<"Owner Last Name is: "<<info[i].LastName<<endl;
        cout<<"Owner Updated Address is: "<<info[i].UpdateAddress<<endl;
        }
    }

    // void identifyProbableAddresses(const TrafficDepartmentQ1& pointerToQ1Info,const ViolationDatabase& pointerToQ2Info)
    // {

    //     for (int i=0;i<pointerToQ1Info.GetNumberOfVehicles();i++){
    //         for(int j=0;j<NumberOfVehicles;j++){
    //             if(info[j].FirstName==pointerToQ1Info.GetInfo()[i].OwnerFirstName && info[j].LastName==pointerToQ1Info.GetInfo()[i].OwnerLastName)
    //             {
    //                 cout<<"The address of "<<info[j].FirstName<<" "<<info[j].LastName<<" Has changed"<<endl;
    //                 cout<<"The old address of the Vehicle owner is: "<<pointerToQ1Info.GetInfo()[j].OwnerAddress<<" And the new address is:  "<<info[j].UpdateAddress<<endl;
    //             }
    //         }
    //     }

    //     for(int i=0;i<pointerToQ1Info.GetNumberOfVehicles();i++){
    //         for(int j=0;j<pointerToQ2Info.GetNumberOfVehicle();j++){
    //             if(pointerToQ1Info.GetInfo()[i].VehicleNum ==pointerToQ2Info.GetInfo()[j].ViolationVehicleNumber)
    //             {
    //                 cout<<"Notice Has been sent to :"<<pointerToQ1Info.GetInfo()[i].OwnerFirstName<<" "<<pointerToQ1Info.GetInfo()[i].OwnerLastName<<" Car Number: "<<pointerToQ1Info.GetInfo()[i].VehicleNum<<"Report Type"<<pointerToQ2Info.GetInfo()[j].ReportType<<" AT location: "<<pointerToQ2Info.GetInfo()[j].ReportLocation<<endl;
    //             }
    //         }
    //     }

    // }

    void identifyProbableAddresses(const TrafficDepartmentQ1& pointerToQ1Info, const ViolationDatabase& pointerToQ2Info, const string& searchVehicleNumber)
{
    bool found = false;

    // Search for the vehicle number in Q1 information
    for (int i = 0; i < pointerToQ1Info.GetNumberOfVehicles(); i++)
    {
        if (pointerToQ1Info.GetInfo()[i].VehicleNum == searchVehicleNumber)
        {
            // cout << "Vehicle Number: " << pointerToQ1Info.GetInfo()[i].VehicleNum << endl;
            // cout << "Owner First Name: " << pointerToQ1Info.GetInfo()[i].OwnerFirstName << endl;
            // cout << "Owner Last Name: " << pointerToQ1Info.GetInfo()[i].OwnerLastName << endl;
            // cout << "Owner Address: " << pointerToQ1Info.GetInfo()[i].OwnerAddress << endl;
            found = true;
            break;
        }
    }

    // Search for the vehicle number in Q2 information
    for (int j = 0; j < pointerToQ2Info.GetNumberOfVehicle(); j++)
    {
        if (pointerToQ2Info.GetInfo()[j].ViolationVehicleNumber == searchVehicleNumber)
        {
            cout << "Notice has been sent to: " << pointerToQ1Info.GetInfo()[j].OwnerFirstName << " " << pointerToQ1Info.GetInfo()[j].OwnerLastName
                 << " Car Number: " << pointerToQ1Info.GetInfo()[j].VehicleNum << " Report Type: " << pointerToQ2Info.GetInfo()[j].ReportType
                 << " at location: " << pointerToQ2Info.GetInfo()[j].ReportLocation << endl;
            found = true;
            break;
        }
    }

    // If the vehicle number is not found in both Q1 and Q2
    if (!found)
    {
        cout << "Vehicle number not found in the records." << endl;
    }

}

};

    // New class for Challenge Case
class ChallengeCase {
    public:
        string VehicleNumber;
        string PersonResponse;
        vector<string> Witnesses;
        ViolationRelated ViolationDetails;


        void displayCaseDetails() const{
            cout << "Vehicle Number: " << VehicleNumber << endl;
            cout << "Person Response: " << PersonResponse << endl;
            cout << "Violation Details:" << endl;
            cout << "  Violation Vehicle Number: " << ViolationDetails.ViolationVehicleNumber << endl;
            cout << "  Report Type: " << ViolationDetails.ReportType << endl;
            cout << "  Report Location: " << ViolationDetails.ReportLocation << endl;
            cout << "Witnesses:" << endl;
            for (const auto& witness : Witnesses) {
                cout << "  " << witness << endl;
            }
        }
};

class ChallengeDatabase {
        private:
        vector<ChallengeCase> Cases;

        public:
        void addCase(const ChallengeCase& newCase) {
            Cases.push_back(newCase);
        }

        void displayAllCases() {
            for (const auto& challengeCase : Cases) {
                challengeCase.displayCaseDetails();
                cout << endl;
            }
        }
};



int main()
{
    TrafficDepartmentQ1 objectQ1;
    objectQ1.ReadCSV("A4-Q1.csv");
    // objectQ1.printInformation();

    ViolationDatabase objectQ2;
    objectQ2.ReadCSV("A4-Q2.csv");


    TrafficDatabaseQ3 object;
    object.ReadCSV("A4-Q3.csv");
    // object.printInformation();
    string vehiclenumber;
    cout<<"Enter the vehicle Number"<<endl;
    cin>>vehiclenumber;
    object.identifyProbableAddresses(objectQ1,objectQ2,vehiclenumber);


    ChallengeCase newCase;
    newCase.VehicleNumber = vehiclenumber;
    newCase.PersonResponse = "Person's response here";
    newCase.Witnesses = { "Witness1", "Witness2" };
    newCase.ViolationDetails = { "456", "Speeding", "Main Street" };

    ChallengeDatabase challengeDB;
    challengeDB.addCase(newCase);

    // Display all challenge cases
    challengeDB.displayAllCases();
}