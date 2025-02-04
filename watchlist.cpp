#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <restclient-cpp/restclient.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <fstream>

using namespace std;
using namespace rapidjson;
const string apiKey = ""; // https://www.omdbapi.com/apikey.aspx
class Item
{
public:
    Item(string imdbId)
    {
        setImdbId(imdbId);
        setDetails();
    }

    void setDetails()
    {
        Document d;
        RestClient::Response r = RestClient::get("http://www.omdbapi.com/?i=" + imdbId + "&apikey=" + apiKey);
        const char* cStr = r.body.c_str();
        d.Parse(cStr);
        name = d["Title"].GetString();
        released = d["Released"].GetString();
        type = d["Type"].GetString();
        rating = d["imdbRating"].GetString();
        genre = d["Genre"].GetString();
    }

    string getName()
    {
        return name;
    }
    string getReleased()
    {
        return released;
    }
    string getType()
    {
        return type;
    }
    string getRating() {
        return rating;
    }
    string getGenre() {
        return genre;
    }
    void setImdbId(string id)
    {
        imdbId = id;
    }
    string getImdbId()
    {
        return imdbId;
    }

private:
    string imdbId;

    string name;
    string released;
    string type;
    string rating;
    string genre;
};


class List
{
public:
    List() {
        string imdbId;
        ifstream MyReadFile("list.data");
        while (getline(MyReadFile, imdbId)) {
            add(imdbId);
        }
        MyReadFile.close();
    };

    void add(string imdbId) {
        Item item(imdbId);
        list.push_back(item);
        cout << "Added!\n";
    };
    void remove(string imdbId) {
        int index = -1;
        for (int i = 0; i < list.size(); i++) {
            if (list.at(i).getImdbId() == imdbId) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Couldn't find it in the list\n";
            return;
        }
        list.erase(list.begin() + index);
        cout << "Deleted!\n";
    };
    void display() {
        cout << "List:\n";
        for (int i = 0; i < list.size(); i++) {
            cout << "=====================\n";
            cout << "ID: " << list.at(i).getImdbId() << "\n";
            cout << "Title: " << list.at(i).getName() << " ( " << list.at(i).getRating() << " )" << "\n";
            cout << "Released: " << list.at(i).getReleased() << "\n";
            cout << "Type: " << list.at(i).getType() << "\n";
            cout << "Genre: " << list.at(i).getGenre() << "\n";
            cout << "=====================\n";
        }
    };
    ~List() {
        ofstream MyFile("list.data");
        for (int i = 0; i < list.size(); i++) {
            MyFile << list.at(i).getImdbId() + "\n";
        }
        MyFile.close();
    };

private:
    vector<Item> list;
};
int main()
{
    List watchList;
    while (true)
    {
        int choice;
        string id;
        cout << "######### Watch List #########";
        cout << "\nChoose: \n1. Show list\n2. Add to list\n3. Remove from list\n4. Exit the program\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            watchList.display();
            break;
        case 2:
            cout << "Enter an IMDB ID: ";
            cin >> id;
            watchList.add(id);
            break;
        case 3:
            cout << "Enter an IMDB ID: ";
            cin >> id;
            watchList.remove(id);
            break;
        case 4:
            return 0;
        }
        cout << "Enter 1 to choose again and 2 to exit: ";
        cin >> id;
        if (id == "2") return 0;
        system("cls");
        continue;
    }
}
