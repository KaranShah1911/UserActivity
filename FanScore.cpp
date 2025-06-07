#include<bits/stdc++.h>
using namespace std;

class LoyaltyProgram 
{
    private:
        string programId;
        vector<string> rules;

    public:
        LoyaltyProgram(string id = "LP001") : programId(id) 
        {
            rules.push_back("Attend 3 events = 10 points");
            rules.push_back("Refer a friend = 5 points");
        }

        vector<string> getRules() 
        {
            cout << "Fetching rules for Loyalty Program: " << programId << endl;
            return rules;
        }

        int calculatePoints() 
        {
            cout << "Calculating loyalty points based on activity..." << endl;
            return 15;
        }

        bool redeemPoints() 
        {
            cout << "Redeeming points for Loyalty Program: " << programId << endl;
            return true;
        }

        string getUserStatus() 
        {
            cout << "Returning user loyalty tier/status..." << endl;
            return "Gold Member";
        }
};

class RewardPoints
{
    private:
        string userId;
        int points;

    public:
        RewardPoints(string uid = "") : userId(uid), points(0) {}

        void addPoints() 
        {
            points += 10;
            cout << "Added points for user: " << userId << ". Total now: " << points << endl;
        }

        bool deductPoints() 
        {
            if (points >= 5) 
            {
                points -= 5;
                cout << "Deducted 5 points for user: " << userId << ". Remaining: " << points << endl;
                return true;
            }
            
            cout << "Not enough points to deduct." << endl;
            return false;
        }

        int getBalance() 
        {
            cout << "Getting balance for user: " << userId << endl;
            return points;
        }

        vector<string> getHistory() 
        {
            cout << "Returning dummy history of reward transactions for user: " << userId << endl;
            return {"+10 points", "-5 points", "+10 points"};
        }
};

class FanScoreCalculator 
{
    private:
        map<string, int> metrics;
        string algorithm = "WeightedAvg"; // Simplified for C++

    public:
        FanScoreCalculator() 
        {
            metrics["spotify_plays"] = 100;
            metrics["concert_attendance"] = 3;
        }

        int calculateScore() 
        {
            cout << "Calculating fan score using algorithm: " << algorithm << endl;
            
            int score = metrics["spotify_plays"] / 10 + metrics["concert_attendance"] * 5;
            return score;
        }

        void updateMetrics() 
        {
            cout << "Updating fan metrics..." << endl;
            metrics["spotify_plays"] += 50;
            metrics["concert_attendance"] += 1;
        }

        map<string, int> getMetricsData() 
        {
            cout << "Returning fan metrics data..." << endl;
            return metrics;
        }

        vector<string> getScoreHistory() 
        {
            cout << "Fetching historical scores..." << endl;
            return {"Score: 45", "Score: 50", "Score: 60"};
        }
};

class UserActivity 
{
    private:
        string userId;

    public:
        UserActivity(string id = "") : userId(id) {}

        void logActivity() 
        {
            cout << "Logging activity for user: " << userId << endl;
        }
};

int main() 
{
    // Loyalty program
    LoyaltyProgram lp;
    lp.getRules();
    lp.calculatePoints();
    lp.redeemPoints();
    lp.getUserStatus();

    // Reward points
    RewardPoints rp("user123");
    rp.addPoints();
    rp.deductPoints();
    cout << "Balance: " << rp.getBalance() << endl;
    rp.getHistory();

    // Fan score calculation
    FanScoreCalculator fsc;
    fsc.calculateScore();
    fsc.updateMetrics();
    fsc.getMetricsData();
    fsc.getScoreHistory();

    // User activity
    UserActivity ua("user123");
    ua.logActivity();

    return 0;
}
