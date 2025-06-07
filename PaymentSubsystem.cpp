#include<bits/stdc++.h>
using namespace std;

class Receipt 
{
    public:
        void print() 
        {
            cout << "Printing receipt..." << endl;
        }
};

class RefundPolicy 
{
    public:
        string getPolicyDetails() 
        {
            return "Standard 7-day refund policy.";
        }
};

class PaymentGateway 
{
    private:
        string gatewayId;
        string gatewayType;

    public:
        PaymentGateway(string id = "", string type = "") : gatewayId(id), gatewayType(type) {}

        string initiateTransaction() 
        {
            cout << "Initiating transaction through gateway: " << gatewayId << endl;
            return "TXN12345";
        }

        bool processTransaction() 
        {
            cout << "Processing transaction through gateway: " << gatewayType << endl;
            return true;
        }

        string getTransactionStatus() 
        {
            cout << "Returning transaction status from gateway: " << gatewayId << endl;
            return "Success";
        }
};

class Payment 
{
    private:
        string paymentId;
        double amount;

    public:
        Payment(string id = "", double amt = 0.0) : paymentId(id), amount(amt) {}

        bool processPayment() 
        {
            cout << "Processing payment ID: " << paymentId << " for amount: " << amount << endl;
            return true;
        }

        bool verifyPayment() 
        {
            cout << "Verifying payment ID: " << paymentId << endl;
            return true;
        }

        string getTransactionStatus() 
        {
            cout << "Getting transaction status for payment ID: " << paymentId << endl;
            return "Completed";
        }

        Receipt generateReceipt() 
        {
            cout << "Generating receipt for payment ID: " << paymentId << endl;
            return Receipt();
        }
};

class RefundManager 
{
    private:
        RefundPolicy refundPolicy;

    public:
        bool initiateRefund() 
        {
            cout << "Initiating refund..." << endl;
            return true;
        }

        double calculateRefundAmount() 
        {
            cout << "Calculating refund amount..." << endl;
            return 49.99;
        }

        bool processRefund() 
        {
            cout << "Processing refund based on policy: " << refundPolicy.getPolicyDetails() << endl;
            return true;
        }

        string getRefundStatus() 
        {
            cout << "Getting refund status..." << endl;
            return "Refunded";
        }
};

class PaymentProcessor 
{
    private:
        vector<PaymentGateway> processors;

    public:
        PaymentProcessor() 
        {
            processors.push_back(PaymentGateway("G001", "UPI"));
            processors.push_back(PaymentGateway("G002", "CreditCard"));
        }

        PaymentGateway selectGateway(string type = "UPI") 
        {
            cout << "Selecting gateway of type: " << type << endl;
            for (auto& pg : processors) {
                if (type == "UPI") return pg;
            }
            return processors[0]; // Default
        }

        bool routePayment() 
        {
            cout << "Routing payment to selected gateway..." << endl;
            return true;
        }

        void logTransaction() 
        {
            cout << "Logging transaction to system..." << endl;
        }

        bool validatePayment() 
        {
            cout << "Validating payment via processor..." << endl;
            return true;
        }

        bool processRefund() 
        {
            cout << "Processing refund via processor..." << endl;
            return true;
        }
};

int main() 
{
    Payment payment("P123", 99.99);
    payment.processPayment();
    payment.verifyPayment();
    payment.getTransactionStatus();
    Receipt receipt = payment.generateReceipt();
    receipt.print();

    PaymentProcessor processor;
    PaymentGateway gateway = processor.selectGateway("UPI");
    gateway.initiateTransaction();
    gateway.processTransaction();
    gateway.getTransactionStatus();

    processor.routePayment();
    processor.logTransaction();
    processor.validatePayment();
    processor.processRefund();

    RefundManager refundMgr;
    refundMgr.initiateRefund();
    refundMgr.calculateRefundAmount();
    refundMgr.processRefund();
    refundMgr.getRefundStatus();

    return 0;
}
