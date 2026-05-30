#include<iostream>
#include<string>
using namespace std;

const int MAX_DRIVER = 10000;
const int MAX_PASSENGER = 10000;
const int MAX_N = 10000;

// enum state
enum class CarStatus
{
    Offline,
    Idle,
    InService
};

enum class PassengerStatus
{
    Offline,
    Waiting,
    InService
};

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
    EntityArray();
public:
    ~EntityArray();
    void add(Entity* entity);
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

void EntityArray::add(Entity* entity) {
    if (this->cnt < this->capacity) {
        entityPtr[cnt] = entity;
        this->cnt++;
    }
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
    Car(string id, CarStatus status, double lon , double lat);
    void print() override;
};

Car::Car(string id, CarStatus status, double lon , double lat): Entity(id, status != CarStatus::Offline, status == CarStatus::InService, lon, lat){}

void Car::print(){
    cout << "Car: " << this->id << endl;
    if (!isOn) {
        cout << "Offline" << endl;
    } else {
        cout << "Online: " << (this->isSer ? "In-service" : "Idle") << endl;
        cout << "Location: (" << this->lon << ", " << this->lat << ")" << endl;
    }
    
    cout << "====================" << endl;
}


class CarArray: public EntityArray{
private:
public:
    void add(string id, CarStatus status, double lon, double lat);
};

void CarArray::add(string id, CarStatus status, double lon, double lat){
    EntityArray::add(new Car(id, status, lon, lat));
}

// Passengers
class Passenger: public Entity
{
private:
public:
    Passenger(string id, PassengerStatus status , double lon , double lat);
    void print() override;
};

Passenger::Passenger(string id, PassengerStatus status , double lon , double lat):Entity(id, status != PassengerStatus::Offline, status == PassengerStatus::InService, lon, lat){}

void Passenger::print(){
    cout << "Passenger: " << this->id << endl;
    if (!isOn) {
        cout << "Offline" << endl;
    } else {
        cout << "Online: " << (this->isSer ? "In-service" : "Waiting") << endl;
        cout << "Location: (" << this->lon << ", " << this->lat << ")" << endl;
    }
    cout << "====================" << endl;
}

class PassengerArray: public EntityArray{
private:
public:
    void add(string id, PassengerStatus status, double lon, double lat);
};

void PassengerArray::add(string id, PassengerStatus status, double lon , double lat){
    EntityArray::add(new Passenger(id, status, lon, lat));
}

// main function
int main(){
    CarArray carArray;
    carArray.add("LIN-1014", CarStatus::InService, 0, 0);
    carArray.add("XYZ-0118", CarStatus::InService, 727, 67);
    carArray.add("SABI-014", CarStatus::Idle, 7414, 487);
    carArray.print();

    PassengerArray passArr;
    passArr.add("Chih-Lin, Chu", PassengerStatus::Waiting, 727, 727);
    passArr.add("Japanese LaoMei", PassengerStatus::InService, 727, 67);
    passArr.add("Grava", PassengerStatus::Offline, 1, 67);
    passArr.print();

    system("pause");
    return 0;
}