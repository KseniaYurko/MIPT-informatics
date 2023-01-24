#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>

using namespace std;

void BUSES_FOR_STOP(string &stop, const map <string, vector<string>> &all_buses, const vector <string> &one_bus_list){
    vector <string> result;
    for(const auto &b: all_buses){
        for(const auto &s: b.second){
            if(s == stop){
                result.push_back(b.first);
            }
        }
    }
    
    for(const auto x: result){
        cout << x << ", ";
    }
}


void STOPS_FOR_BUS(string &bus, const map <string, vector<string>> &all_buses, const vector <string> &one_bus_list){
    
}


void ALL_BUSES(const map <string, vector<string>> &all_buses){
    if(all_buses.size() == 0){
        cout << "No buses :(\n";
    }

    else{
        for(const auto &b: all_buses){
            cout << "BUS: " << b.first << "\n";
            for(const auto &s: b.second){
                cout << s << ";  "; 

            }
            cout << "\n" << "\n";
        }
    }
}


int main(){
    cout << "Enter number of requests: ";
    int Q;
    cin >> Q;

    map <string, vector<string>> all_buses;
    vector <string> one_bus_list;

    cout << "Enter your reqests: ";
    cout << "\n";
    for(int i = 0; i < Q; i++){
        string request, bus, stop; 
        cin >> request;

        if(request == "NEW_BUS"){
            int stops_count;
            cin >> bus >> stops_count; 
            one_bus_list.push_back(bus);

            for(int i = 0; i < stops_count; i++){
                string stop_name;
                cin >> stop_name;
                all_buses[bus].push_back(stop_name);
            }
        }

        else if(request == "BUSES_FOR_STOP"){
            cin >> stop;
            BUSES_FOR_STOP(stop, all_buses, one_bus_list);
        }

        else if(request == "STOPS_FOR_BUS"){
            cin >> bus;
            STOPS_FOR_BUS(bus, all_buses, one_bus_list);
        }

        else if(request == "ALL_BUSES"){
            ALL_BUSES(all_buses);
        }

        else{
            cout << "Error request :(\n";
        }
    }

}