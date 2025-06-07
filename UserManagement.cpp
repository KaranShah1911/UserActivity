#include<bits/stdc++.h>
using namespace std;

class UserProfile 
{
    private:
        string userId;
        vector<string> preferences;

    public:
        UserProfile(string uid = "") : userId(uid) {}

        vector<string> getPreferences() 
        {
            cout << "Getting user preferences for userId: " << userId << endl;
            return preferences;
        }

        void setPreferences(const vector<string>& prefs) 
        {
            preferences = prefs;
            cout << "Preferences updated for userId: " << userId << endl;
        }
};

class User 
{
    private:
        string userId;
        string email;
        UserProfile profile;

    public:
        User(string uid = "", string mail = "") : userId(uid), email(mail), profile(uid) {}

        bool login() 
        {
            cout << "Logging in user: " << email << endl;
            return true;
        }

        void logout() 
        {
            cout << "Logging out user: " << email << endl;
        }

        bool registerUser() 
        {
            cout << "Registering user: " << email << endl;
            return true;
        }

        bool updateProfile() 
        {
            cout << "Updating profile for user: " << email << endl;
            return true;
        }

        UserProfile& getProfile() 
        {
            return profile;
        }
};

class Authentication 
{
    private:
        string authToken;
        string credentials;

    public:
        Authentication(string creds = "") : credentials(creds) {}

        bool verifyCredentials() 
        {
            cout << "Verifying credentials: " << credentials << endl;
            return true;
        }

        string generateToken() 
        {
            authToken = "ABC123XYZ";
            cout << "Generated token: " << authToken << endl;
            return authToken;
        }

        bool validateToken() 
        {
            cout << "Validating token: " << authToken << endl;
            return !authToken.empty();
        }
};

class ThirdPartyAuth 
{
    private:
        string provider;
        string oauthToken;

    public:
        ThirdPartyAuth(string prov = "Google") : provider(prov) {}

        bool authenticate() 
        {
            cout << "Authenticating with provider: " << provider << endl;
            oauthToken = "OAuthToken123";
            return true;
        }

        UserProfile fetchUserInfo() 
        {
            cout << "Fetching user info using OAuth token from " << provider << endl;
            return UserProfile("thirdparty_user");
        }

        bool linkAccount() 
        {
            cout << "Linking third-party account from provider: " << provider << endl;
            return true;
        }
};

int main() 
{
   
    User user("user001", "user@example.com");
    user.registerUser();
    user.login();
    user.updateProfile();
    user.logout();

    // Profile operations
    vector<string> prefs = {"music", "sports"};
    user.getProfile().setPreferences(prefs);
    user.getProfile().getPreferences();

    // Auth operations
    Authentication auth("user:password");
    auth.verifyCredentials();
    auth.generateToken();
    auth.validateToken();

    // Third-party auth
    ThirdPartyAuth tpa("Spotify");
    tpa.authenticate();
    UserProfile profile = tpa.fetchUserInfo();
    tpa.linkAccount();

    return 0;
}
