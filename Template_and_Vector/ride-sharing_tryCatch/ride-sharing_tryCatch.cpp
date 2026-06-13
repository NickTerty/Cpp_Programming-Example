#include<iostream>
#include<string>
#include<stdexcept>
#include<vector>
using namespace std;

const int MAX_DRIVER = 10000;
const int MAX_PASSENGER = 10000;
const int MAX_N = 10000;

// abstract class
class Entity{
protected:
    string id;
    bool isOn;
    bool isSer; // means nothing if isOn == false
    double lon;
    double lat;
public:
    Entity(string id, bool isOn , bool isSer , double lon , double lat);
    virtual void print() = 0;
};

Entity::Entity(string id, bool isOn, bool isSer, double lon, double lat) : id(id), isOn(isOn), isSer(isSer), lon(lon), lat(lat) {

}

void Entity::print(){
    cout << this->id << ": " << this->isOn << " " << this->isSer << " (" << this->lon << ", " << this->lat << ")" << endl;
}

template<typename entityType>
class EntityArray{
protected:
    int capacity;
    int cnt;
    entityType **entityPtr;

public:
    EntityArray();
    ~EntityArray();
    void add(string id, bool isOn, bool isSer, double lon, double lat);
    void print();
};

template<typename entityType>
EntityArray<entityType>::EntityArray(){
    this->cnt = 0;
    this->capacity = MAX_N;
    this->entityPtr = new entityType*[this->capacity];
}

template<typename entityType>
EntityArray<entityType>::~EntityArray(){
    for (int i = 0; i < cnt; i++){
        delete entityPtr[i];
    }
    delete[] entityPtr;
}

template<typename entityType>
void EntityArray<entityType>::add(string id, bool isOn, bool isSer, double lon, double lat){
    if(this->cnt < this->capacity){
        this->entityPtr[cnt] = new entityType(id, isOn, isSer, lon, lat);
        this->cnt++;
    }
    else{
        throw overflow_error("EntityArray overflowed!");
    }
}

template<typename entityType>
void EntityArray<entityType>::print(){
    for (int i = 0; i < this->cnt; i++){
        entityPtr[i]->print();
    }
}

// Instance classes
// Car
class Car: public Entity
{
private:
public:
    Car(string id, bool isOn , bool isSer , double lon , double lat);
    void print() override;
};

Car::Car(string id, bool isOn , bool isSer , double lon , double lat): Entity(id, isOn, isSer, lon, lat){}

void Car::print(){
    cout << "Car: " << this->id << endl;
    if(isOn){
        cout << "Online: ";
        if(isSer){
            cout << "In-service" << endl;
        }
        else{
            cout << "Idle" << endl;
        }
        cout << "Location: (" << this->lon << ", " << this->lat << ")" << endl;
    }
    else{
        cout << "Offline" << endl;
    }
    cout << "====================" << endl;
}

// Passengers
class Passenger: public Entity
{
private:
public:
    Passenger(string id, bool isOn , bool isSer , double lon , double lat);
    void print() override;
};

Passenger::Passenger(string id, bool isOn , bool isSer , double lon , double lat):Entity(id, isOn, isSer, lon, lat){}

void Passenger::print(){
    cout << "Passenger: " << this->id << endl;
    if(isOn){
        cout << "Online: ";
        if(isSer){
            cout << "In-service" << endl;
        }
        else{
            cout << "Waiting" << endl;
        }
        cout << "Location: (" << this->lon << ", " << this->lat << ")" << endl;
    }
    else{
        cout << "Offline" << endl;
    }
    cout << "====================" << endl;
}

// main function
int main(){
    EntityArray<Car> carArray;
    try{
        carArray.add("LIN-1014", true, true, 0, 0);
        carArray.add("XYZ-0118", true, true, 0, 0);
        carArray.add("SABI-014", true, false, 7414, 487);
    }
    catch(const overflow_error& e){
        cout << "Caught an exception: " << e.what() << endl;
    }
    
    carArray.add("LIN-1014", true, true, 0, 0);
    carArray.add("XYZ-0118", true, true, 0, 0);
    carArray.add("SABI-014", true, false, 7414, 487);
    carArray.print();

    EntityArray<Passenger> passArr;

    try{
        passArr.add("Chih-Lin, Chu", true, false, 727, 727);
        passArr.add("Japanese LaoMei", true, true, 727, 67);
        passArr.add("Grava", false, false, 1, 67);
    }
    catch(const overflow_error& e){
        cout << "Caught an exception: " << e.what() << endl;
    }

    passArr.print();

    system("pause");
    return 0;
}