#include<bits/stdc++.h>
using namespace std;

class Booking 
{
    private:
        string bookingId;
        string userId;
        string status = "Active"; // default status

    public:
        Booking(string bId = "", string uId = "") : bookingId(bId), userId(uId) {}

        string getDetails() 
        {
            cout << "Getting booking details for Booking ID: " << bookingId << ", User ID: " << userId << endl;
            return "Booking ID: " + bookingId + ", User ID: " + userId;
        }

        bool updateBooking() 
        {
            cout << "Updating booking: " << bookingId << endl;
            return true;
        }

        bool cancelBooking() 
        {
            status = "Cancelled";
            cout << "Cancelling booking: " << bookingId << endl;
            return true;
        }

        string getStatus() 
        {
            cout << "Status of booking " << bookingId << ": " << status << endl;
            return status;
        }

        string getUserId() const 
        {
            return userId;
        }

        string getBookingId() const 
        {
            return bookingId;
        }
};

class BookingManager {
    private:
        vector<Booking> bookings;

    public:
        Booking createBooking(string bookingId, string userId) 
        {
            Booking b(bookingId, userId);
            
            bookings.push_back(b);
            cout << "Created booking for User ID: " << userId << " with Booking ID: " << bookingId << endl;
            
            return b;
        }

        bool modifyBooking(string bookingId) 
        {
            for (auto& b : bookings) 
            {
                if (b.getBookingId() == bookingId) 
                {
                    cout << "Modifying booking: " << bookingId << endl;
                    return b.updateBooking();
                }
            }

            cout << "Booking not found: " << bookingId << endl;
            return false;
        }

        bool cancelBooking(string bookingId) 
        {
            for (auto& b : bookings) 
            {
                if (b.getBookingId() == bookingId) 
                {
                    cout << "Cancelling booking from BookingManager: " << bookingId << endl;
                    return b.cancelBooking();
                }
            }

            cout << "Booking not found for cancellation: " << bookingId << endl;
            return false;
        }

        vector<Booking> getUserBookings(string userId) 
        {
            vector<Booking> userBookings;
            cout << "Getting all bookings for user: " << userId << endl;
        
            for (auto& b : bookings) 
            {
                if (b.getUserId() == userId) 
                {
                    userBookings.push_back(b);
                }
            }
            return userBookings;
        }
};

class Ticket {
    private:
        string ticketId;

    public:
        Ticket(string tId = "") : ticketId(tId) {}

        string getDetails() 
        {
            cout << "Getting ticket details for Ticket ID: " << ticketId << endl;
            return "Ticket ID: " + ticketId;
        }
};

int main() 
{
    BookingManager manager;

    // Create bookings
    Booking b1 = manager.createBooking("B001", "U001");
    Booking b2 = manager.createBooking("B002", "U001");
    Booking b3 = manager.createBooking("B003", "U002");

    // Modify and cancel a booking
    manager.modifyBooking("B002");
    manager.cancelBooking("B003");

    // Show status
    b1.getStatus();
    b3.getStatus();

    // Get bookings for a user
    vector<Booking> userBookings = manager.getUserBookings("U001");
    for (auto& b : userBookings) 
    {
        b.getDetails();
    }

    // Ticket example
    Ticket t("T1001");
    t.getDetails();

    return 0;
}
