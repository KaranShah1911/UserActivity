#include<bits/stdc++.h>
using namespace std;

class Show 
{
    private:
        string showId;
        string title;
        string genre;

    public:
        Show(string id = "", string t = "", string g = "") : showId(id), title(t), genre(g) {}

        string getDetails() 
        {
            cout << "Getting details for show: " << title << endl;
            return "Show ID: " + showId + ", Title: " + title + ", Genre: " + genre;
        }

        bool getAvailability() 
        {
            cout << "Checking availability for show: " << title << endl;
            return true;
        }

        bool updateShow() 
        {
            cout << "Updating show: " << title << endl;
            return true;
        }

        bool cancelShow() 
        {
            cout << "Cancelling show: " << title << endl;
            return true;
        }

        string getGenre() const { return genre; }
        string getTitle() const { return title; }
        string getShowId() const { return showId; }
};

class ShowCatalog 
{
    private:
        vector<Show> shows;

    public:
        vector<Show> getShows() 
        {
            cout << "Retrieving list of all shows in catalog." << endl;
            return shows;
        }

        bool addShow(const Show& s) 
        {
            shows.push_back(s);
            cout << "Added show to catalog: " << s.getTitle() << endl;
            return true;
        }

        bool removeShow(const Show& s) 
        {
            for (auto it = shows.begin(); it != shows.end(); it++) 
            {
                if (it->getShowId() == s.getShowId()) 
                {
                    shows.erase(it);
                    cout << "Removed show from catalog: " << s.getTitle() << endl;
                    return true;
                }
            }

            cout << "Show not found to remove: " << s.getTitle() << endl;
            return false;
        }

        bool updateShow(const Show& s) 
        {
            cout << "Updating show in catalog: " << s.getTitle() << endl;
            return true;
        }
};

class ShowSearch 
{
    private:
        map<string, string> searchFilters;

    public:
        vector<Show> search(const string& criteria) 
        {
            cout << "Searching shows by criteria: " << criteria << endl;
            return {};
        }

        vector<Show> filterByGenre(const string& genre) 
        {
            cout << "Filtering shows by genre: " << genre << endl;
            return {};
        }

        vector<Show> filterByLocation(const string& loc) 
        {
            cout << "Filtering shows by location: " << loc << endl;
            return {};
        }
};

class ThirdPartyProvider 
{
    private:
        string providerId;

    public:
        ThirdPartyProvider(string id = "") : providerId(id) {}

        vector<Show> fetchShows() 
        {
            cout << "Fetching shows from third-party provider: " << providerId << endl;
            return {};
        }

        bool syncShows() 
        {
            cout << "Syncing shows with provider: " << providerId << endl;
            return true;
        }

        string getApiStatus() 
        {
            cout << "Getting API status from provider: " << providerId << endl;
            return "Online";
        }
};

class ShowAdmin 
{
    private:
        string adminId;

    public:
        ShowAdmin(string id = "") : adminId(id) {}

        Show createShow() 
        {
            cout << "Admin " << adminId << " creating a show." << endl;
            return Show("S123", "Sample Show", "Comedy");
        }

        bool modifyShow(Show s) 
        {
            cout << "Admin " << adminId << " modifying show: " << s.getTitle() << endl;
            return true;
        }

        bool deleteShow(Show s) 
        {
            cout << "Admin " << adminId << " deleting show: " << s.getTitle() << endl;
            return true;
        }

        bool approveShow(Show s) 
        {
            cout << "Admin " << adminId << " approving show: " << s.getTitle() << endl;
            return true;
        }
};

int main() 
{
    // Admin creates a show
    ShowAdmin admin("admin001");
    Show newShow = admin.createShow();
    admin.approveShow(newShow);

    // Catalog management
    ShowCatalog catalog;
    catalog.addShow(newShow);
    catalog.getShows();

    // Show update/cancel
    newShow.updateShow();
    newShow.cancelShow();

    // Third party sync
    ThirdPartyProvider provider("Netflix");
    provider.fetchShows();
    provider.syncShows();
    provider.getApiStatus();

    // Show search
    ShowSearch search;
    search.search("Live");
    search.filterByGenre("Comedy");
    search.filterByLocation("Mumbai");

    return 0;
}
