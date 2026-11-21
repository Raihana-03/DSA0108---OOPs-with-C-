#include <iostream>
class Event {
    int rows, seatsPerRow, booked;
    char** seats;
public:
    Event(int r,int s) : rows(r), seatsPerRow(s), booked(0), seats(nullptr) {
        if (rows > 0 && seatsPerRow > 0) {
            seats = new char*[rows];
            int made=0;
            try {
                for (; made<rows; ++made) {
                    seats[made]=new char[seatsPerRow];
                    for(int j=0;j<seatsPerRow;++j) seats[made][j]='O';
                }
            } catch (...) {
                for(int i=0;i<made;++i) delete[] seats[i];
                delete[] seats; seats=nullptr; throw;
            }
        }
        std::cout << "Created event " << rows << "x" << seatsPerRow << '\n';
    }
    bool book(int r,int s) {
        if(!seats||r<0||r>=rows||s<0||s>=seatsPerRow||seats[r][s]=='X') return false;
        seats[r][s]='X'; ++booked; return true;
    }
    bool cancel(int r,int s) {
        if(!seats||r<0||r>=rows||s<0||s>=seatsPerRow||seats[r][s]!='X') return false;
        seats[r][s]='O'; --booked; return true;
    }
    ~Event() {
        for(int i=0;i<rows && seats;++i) delete[] seats[i];
        delete[] seats;
        std::cout << "Closed event; booked seats: " << booked << '\n';
    }
};
int main() {
    Event stackEvent(2,3);
    stackEvent.book(0,1); stackEvent.book(1,2); stackEvent.cancel(0,1);
    { Event blockEvent(1,2); blockEvent.book(0,0); }
    Event* heapEvent=new Event(2,2); heapEvent->book(1,1); delete heapEvent;
    Event zeroRows(0,5);
}
