#include<iostream>
#include<string>
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

class EntityArray{
protected:
    int capacity;
    int cnt;
    Entity **entityPtr;
public:
    EntityArray();
    ~EntityArray();
    virtual void add(string id, bool isOn, bool isSer, double lon, double lat) = 0;
    void print();
};

EntityArray::EntityArray(){
    this->cnt = 0;
    this->capacity = MAX_N;
    this->entityPtr = new Entity*[this->capacity];
}

EntityArray::~EntityArray(){
    for (int i = 0; i < cnt; i++){
        delete entityPtr[i];
    }
    delete[] entityPtr;
}

void EntityArray::print(){
    for (int i = 0; i < cnt; i++){
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


class CarArray: public EntityArray{
private:
public:
    void add(string id, bool isOn , bool isSer , double lon , double lat) override;
};

void CarArray::add(string id, bool isOn , bool isSer , double lon , double lat){
    if(this->cnt < this->capacity){
        entityPtr[cnt] = new Car(id, isOn, isSer, lon, lat);
        this->cnt++;
    }
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

class PassengerArray: public EntityArray{
private:
public:
    void add(string id, bool isOn , bool isSer , double lon , double lat) override;
};

void PassengerArray::add(string id, bool isOn , bool isSer , double lon , double lat){
    if(this->cnt < this->capacity){
        entityPtr[cnt] = new Passenger(id, isOn, isSer, lon, lat);
        this->cnt++;
    }
}

// main function
int main(){
    CarArray carArray;
    carArray.add("LIN-1014", true, true, 0, 0);
    carArray.add("XYZ-0118", true, true, 0, 0);
    carArray.add("SABI-014", true, false, 7414, 487);
    carArray.print();

    PassengerArray passArr;
    passArr.add("Chih-Lin, Chu", true, false, 727, 727);
    passArr.add("Japanese LaoMei", true, true, 727, 67);
    passArr.add("Grava", false, false, 1, 67);
    passArr.print();

    system("pause");
    return 0;
}