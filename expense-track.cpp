#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
using namespace std;
using namespace rapidjson;
struct Item {
	string name;
	string description;
	string amount;
};

class Expense {
	public:
		void add(string name, string description, string amount) {
			Item i;
			i.name = name;
			i.description = description;
			i.amount = amount;
			list[name] = i;
		};
		void remove(string name) {
			list.erase(name);
		};
		void viewList() {
			cout << "Name\t\tDescription\t\tAmount" << endl;
			for (auto i : list) {
				Item item = i.second;
				cout << item.name << "\t\t" << item.description << "\t\t\t" << item.amount << endl;
			}
		};
		int getSize() {
			return list.size();
		};
		Expense(string fileName) {
			file = fileName;
			ifstream MyReadFile(file);
			string json;
			while (getline(MyReadFile, json)) {
				Document d;
				d.Parse(json.c_str());
				Item i;
				i.name = d["name"].GetString();
				i.description = d["description"].GetString();
				i.amount = d["amount"].GetString();
				list[d["name"].GetString()] = i;
			}
		};
		~Expense() {
			ofstream MyFile(file);
			for (auto i : list) {
				Item item = i.second;
				MyFile << "{\"name\":\"" << item.name << "\",\"description\":\"" << item.description << "\",\"amount\":\"" << item.amount << "\"}" << endl;
			}
			MyFile.close();
		};
	private:
		map<string, Item> list;
		string file;
};


int main(int argc,
	char* argv[],
	char* envp[])
{
	Expense expense("list.data");
	string option = argv[1];
	if ((option == "add" or option == "edit") and argc == 5) {
		expense.add(argv[2], argv[3], argv[4]);
		cout << "Done! " << endl;
		return 0;
	}
	if (option == "remove" and argc == 3) {
		expense.remove(argv[2]);
		cout << "Done!" << endl;
		return 0;
	}
	if (option == "list") {
		expense.viewList();
		return 0;
	}
	cout << "Use: add, remove, edit, list and info" << endl;
}
