#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


vector <char> input_name()
{
	char buffer[100];
	vector <char> data;
	
	cin >> buffer;
	for (int i = 0; i < sizeof(buffer) && buffer[i] != '\0'; ++i)
	{
		data.push_back(buffer[i]);
	}
	return data;
}
int i = 0;
ifstream file_choose()
{
	vector <char> data;
	bool ok = true;
	
	while (ok)
	{
		data = input_name();
		if (data.size() == 2)
		{
			switch (data[0] + data[1])
			{
			case ('t' + '1'):
			{
				ifstream text("d:\\texts\\t1.txt");
				i = 1;
				return text;
			}
			case ('t' + '2'):
			{
				ifstream text("d:\\texts\\t2.txt");
				i = 2;
				return text;
			}
			case ('t' + '3'):
			{
				ifstream text("d:\\texts\\t3.txt");
				i = 3;
				return text;
			}
			default:
				cout << "Error! File doesn`t exist" << endl;
				break;
			}
		}
		else cout << "Error! File doesn`t exist" << endl;
	}

}
ofstream ofstr_file()
{
	bool ok = true;
	while (ok)
	{
		switch (i)
		{
		case (1):
		{
			ofstream text("d:\\texts\\t1.txt", ios::app);
			return text;
		}
		case (2):
		{
			ofstream text("d:\\texts\\t2.txt", ios::app);
			return text;
		}
		case (3):
		{
			ofstream text("d:\\texts\\t3.txt", ios::app);
			return text;
		}
		}
	}
}


vector <char> file_reading(ifstream& file)
{
	vector < char > data;
	char symb;
	while ((symb = file.get()) != EOF)
		data.push_back(symb);
	file.close();

	return data;
}

void output(vector <char>& data)
{
	cout << "Your text is: " << endl;
	for (int i = 0; i < data.size(); ++i) {
		cout << data[i];
	}
}

pair <int, int> calculations(vector <char>& data)
{
	int upper_count = 0, lower_count = 0;
	for (auto c : data)
	{
		if (isupper(c)) upper_count += 1;
		if (islower(c)) lower_count += 1;
	}
	return make_pair(upper_count, lower_count);
}


bool YN_function() {
	char buffer[100];
	bool ok = true;
	cout << "Do you want to continue? Write 'Y' or 'N': " << endl;
	while (ok) {

		cin >> buffer;
			if (buffer[0] == 'Y' && buffer[1]=='\0') return true;
			if (buffer[0] == 'N' && buffer[1]=='\0') return false;
			else cout << "Error! Try again!" << endl;
	}
}
bool finish = true;

int main()
{
	while (finish)
	{
		cout << "Input file`s name: " << endl;
		ifstream file = file_choose();
		
		
		vector <char> data = file_reading(file);
		output(data);

		ofstream ofile = ofstr_file();
		int upper_count = calculations(data).first; int lower_count = calculations(data).second;

		if (lower_count != 0) {
			cout << '\n' << "Upper to lower symbols percentage is: " << upper_count * 100 / lower_count << "%" << endl;
			ofile << ' ' << upper_count * 100 / lower_count << "%";
		}
		else cout << "There are no upper symbols in this file" << endl;
		ofile.close();

		finish = YN_function();
	}
}
