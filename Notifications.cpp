#include<bits/stdc++.h>
using namespace std;

enum NotificationType { EMAIL, SMS };
enum DeliveryStatus { PENDING, SENT, FAILED };
enum ChannelType { EMAIL_CHANNEL, SMS_CHANNEL };
enum ChannelStatus { ACTIVE, INACTIVE };

struct Config 
{
    string name = "DefaultConfig";
};

struct ChannelConfig 
{
    string setting = "DefaultSetting";
};

class Notification 
{
    private:
        string notificationId;
        string content;
        DeliveryStatus status;

    public:
        Notification(string id = "", string msg = "")
            : notificationId(id), content(msg), status(PENDING) {}

        string getContent() 
        {
            cout << "Getting content of notification ID: " << notificationId << endl;
            return content;
        }

        NotificationType getType() 
        {
            cout << "Determining notification type..." << endl;
            return EMAIL; // default
        }

        DeliveryStatus getStatus() 
        {
            cout << "Getting delivery status of notification ID: " << notificationId << endl;
            return status;
        }

        void markAsRead() 
        {
            cout << "Marking notification as read: " << notificationId << endl;
        }
};

class CommunicationChannel 
{
    protected:
        ChannelType channelType;
        ChannelConfig config;

    public:
        CommunicationChannel(ChannelType type = EMAIL_CHANNEL) : channelType(type) {}

        virtual DeliveryStatus send() 
        {
            cout << "Sending notification via CommunicationChannel..." << endl;
            return SENT;
        }

        ChannelStatus getStatus() 
        {
            cout << "Getting channel status..." << endl;
            return ACTIVE;
        }

        bool validateRecipient(string recipient) 
        {
            cout << "Validating recipient: " << recipient << endl;
            return true;
        }

        string formatMessage(string content) 
        {
            cout << "Formatting message: " << content << endl;
            return "Formatted: " + content;
        }
};

class SMSChannel : public CommunicationChannel 
{
    public:
        SMSChannel() : CommunicationChannel(SMS_CHANNEL) {}

        DeliveryStatus sendSMS(string msg) 
        {
            cout << "Sending SMS: " << msg << endl;
            return SENT;
        }

        string formatSMSText(string text) 
        {
            cout << "Formatting SMS text..." << endl;
            return "SMS: " + text;
        }
};

class EmailChannel : public CommunicationChannel 
{
    public:
        EmailChannel() : CommunicationChannel(EMAIL_CHANNEL) {}

        DeliveryStatus sendEmail(string emailContent) 
        {
            cout << "Sending email: " << emailContent << endl;
            return SENT;
        }

        string formatEmailTemplate(string templateData) 
        {
            cout << "Formatting email template..." << endl;
            return "Email: " + templateData;
        }
};

class NotificationService 
{
    private:
        queue<Notification> queuedNotifications;
        Config deliveryConfig;

    public:
        bool sendNotification(Notification notif) 
        {
            cout << "Sending notification immediately..." << endl;
            return true;
        }

        bool scheduleNotification(Notification notif) 
        {
            cout << "Scheduling notification..." << endl;
            queuedNotifications.push(notif);
            return true;
        }

        map<string, DeliveryStatus> bulkSend(vector<Notification> notifs) 
        {
            cout << "Sending bulk notifications..." << endl;
            map<string, DeliveryStatus> results;
        
            for (auto& n : notifs) 
            {
                cout << "Sending to: " << n.getContent() << endl;
                results[n.getContent()] = SENT;
            }
            return results;
        }

        void retryFailedNotifications() 
        {
            cout << "Retrying failed notifications in queue..." << endl;
        }
};

int main() 
{
    // Create Notifications
    Notification n1("N101", "Welcome to our platform!");
    Notification n2("N102", "Your booking is confirmed!");

    // Use Notification Service
    NotificationService service;
    service.scheduleNotification(n1);
    service.sendNotification(n2);

    vector<Notification> batch = {n1, n2};
    service.bulkSend(batch);
    service.retryFailedNotifications();

    // Use Channels
    SMSChannel sms;
    sms.sendSMS("Hello via SMS!");
    sms.formatSMSText("Hi there!");

    EmailChannel email;
    email.sendEmail("Hello via Email!");
    email.formatEmailTemplate("Welcome Email Template");

    return 0;
}
