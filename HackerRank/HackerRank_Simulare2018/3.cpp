#include <iostream>
using namespace std;

struct Car {
    string driver;
    string* passengers;
    int seats; // excluzand soferul
    int freeSeats;

    Car(int seats) {
        this->seats = seats;
        freeSeats = seats;
        passengers = new string[seats];
    }

    Car(const Car &other) {
        //TODO: copiati toate campurile
        //TODO: deep-copy in cazul array-ului de pasageri
        driver = other.driver;
        seats = other.seats;
        freeSeats = other.freeSeats;
        passengers = new string[seats];
        for (int i = 0; i < seats - freeSeats; i++) {
          passengers[i] = other.passengers[i];
        }
    }

    void operator=(const Car &other) {
        //TODO: copiati toate campurile
        //TODO: deep-copy in cazul array-ului de pasageri
        if (this == &other) {
          return;
        }
        driver = other.driver;
        seats = other.seats;
        freeSeats = other.freeSeats;
        passengers = new string[seats];
        for (int i = 0; i < seats - freeSeats; i++) {
          this->passengers[i] = other.passengers[i];
        }
    }

    ~Car() {
      //TODO: eliberati memoria
      delete [] passengers;
    }

    void setDriver(string driver) {
        this->driver = driver;
    }

    void addPassenger(string passenger) {
        if (freeSeats == 0) {
            cout << "Car already full!";
        } else {
            passengers[seats - freeSeats] = passenger;
            freeSeats--;
        }
    }

    void print() {
        cout << driver << " will drive with: ";
        for (int i = 0; i < seats - freeSeats; ++i) {
            cout << passengers[i] << " ";
        }
        cout << "as passengers\n";
    }

};

int main()
{
    int seats;
    cin >> seats;

    Car first_car(seats);

    int passengers;
    string passenger;

    cin >> passengers;

    for (int i = 0; i < passengers; ++i) {
        cin >> passenger;
        first_car.addPassenger(passenger);
    }

    Car second_car = first_car;

    Car third_car(seats);
    third_car = first_car;

    first_car.setDriver("First Driver");
    second_car.setDriver("Second Driver");
    third_car.setDriver("Third Driver");

    string last_minute_passenger;
    cin >> last_minute_passenger;
    first_car.addPassenger(last_minute_passenger);

    first_car.print();
    second_car.print();
    third_car.print();


    return 0;
}
