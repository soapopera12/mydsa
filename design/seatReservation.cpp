// 1845. Seat Reservation Manager
// https://leetcode.com/problems/seat-reservation-manager/description/


class SeatManager {
public:

    // vector<int> seats;
    // int noSeats;

    // SeatManager(int n) {
    //     noSeats = n;
    //     seats.resize(n);
    // }
    
    // int reserve() {
    //     int seatNo = -1;
    //     for(int i=0;i<noSeats;i++) {
    //         if(seats[i] == 0) {
    //             seats[i] = 1;
    //             seatNo = i+1;
    //             break;
    //         }
    //     }
    //     return seatNo;
    // }
    
    // void unreserve(int seatNumber) {
    //     seats[seatNumber-1] = 0;
    // }
    set<int> st; //Create a set to keep track of unreserved seats
    SeatManager(int n) {
        for(int i=1;i<=n;i++) st.insert(i); // Insert all the values to set
    }
    
    int reserve() {
        int val = *st.begin(); //find out the first element of set, because it stores the data in ascending order
        st.erase(val); //Remove this from unreserved list
        return val;
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber); //insert the given seat number to unreserved list
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */