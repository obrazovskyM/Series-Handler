#pragma once
#include <string>
#include <sstream>

using namespace std;
using namespace System;

/// //////////////////////////////////////////////////////////////////


ref class Dataset {

/// //////////////////////////////////////////////////////////////////

#pragma region Init

public:
	string* mass = new string[0];
	int length = 0;

	Dataset() {
		mass = new string[0];
		length = 0;
	}
#pragma endregion

/// //////////////////////////////////////////////////////////////////

#pragma region UI functions

	void Write(String^ value) {
		string line = "";
		for (int i = 0; i < value->Length; i++) {
			if (static_cast<char>(value[i]) != '\n')
				line += static_cast<char>(value[i]);
			else {
				if (line.length() != 0) {
					Add(line);
					line = "";
				}
			}
		}
		if (line.length() != 0)
			Add(line);
	}
	String^ Get() {
		String^ datamass;
		string temp_arr;
		for (int i = 0; i < length; i++)
			temp_arr = temp_arr + mass[i] + '\n';
		datamass = gcnew System::String(temp_arr.c_str());
		return datamass;
	}

	void Clear() {
		length = 0;
		mass = new string[0];
		return;
	}

#pragma endregion

/// //////////////////////////////////////////////////////////////////

#pragma region Procesing Functions

	void Cut() {
		Remove(0);
		Remove(0);

		for (int i = 0; i < length; i++) {
			mass[i] = mass[i].erase(0, 2);
			mass[i] = mass[i].erase(mass[i].length() - 1, 1);
		}

		return;
	}
	void Delsmb() {
		for (int i = 0; i < length; i++)
			for (int x = 0; x < mass[i].length(); x++) {
				char smb = mass[i][x];
				//if the smb is not number or latter*
				if (/*1*/  !(  /*2*/  ((smb >= 48) && (smb <= 57)) || ((smb >= 65) && (smb <= 90)) || ((smb >= 97) && (smb <= 122))  /*2*/  )   /*1*/) {
					mass[i][x] = '~';
				}
			}
		for (int i = 0; i < length; i++)
			for (int x = mass[i].length(); x >= 0; x--)
				if (mass[i][x] == '~')
					mass[i] = mass[i].erase(x, 1);
		return;
	}
	void Merge() {
		for (int i = 0; i < length - 1; i++) {

			mass[i] = mass[i] + ", " + mass[i + 1];
			mass[i + 1] = "";
			i++;
		}
		Delempty();
		return;
	}
	void Extend() {

		if (length <= 1)
			return;

		int separator = Get_separator(mass[0]);
		if (separator >= mass[0].length())
			return;
		int insert = Get_insert(separator);

		Dataset new_dataset;

		for (int i = 0; i < length - 1; i = i + 2) {

			if (i + 1 >= length)
				return;

			string wordpath = mass[i];
			wordpath = wordpath.erase(separator + 1, mass[i].length() - separator - 1);
			
			string numpath = mass[i];
			numpath = numpath.erase(0, separator + 1);

			while ((numpath[0] == 48) && (numpath.length() > 1)) {
				numpath.erase(0, 1);
				wordpath = wordpath + "0";
			}
				

			long long int numend = 0;
			stringstream stream(numpath);
			stream >> numend;

			for (int x = 0; x <= insert; x++) {
				new_dataset.Add(wordpath + to_string(numend + x));
				new_dataset.mass[new_dataset.length - 1];
				while (new_dataset.mass[new_dataset.length - 1].length() - mass[i].length() != 0) {
					if (new_dataset.mass[new_dataset.length - 1][separator + 1] == '0')
						new_dataset.mass[new_dataset.length - 1] = new_dataset.mass[new_dataset.length - 1].erase(separator, 1);
				}
				
			}
			//check series
			if (new_dataset.mass[new_dataset.length - 1] != mass[i + 1]) {
				new_dataset.mass[new_dataset.length - 1] += "*";
				new_dataset.mass[new_dataset.length - 1 - insert] = "*" + new_dataset.mass[new_dataset.length - 1 - insert];
			}
			//
		}

		mass = new_dataset.mass;
		length = new_dataset.length;

		return;
	}

#pragma endregion
/// //////////////////////////////////////////////////////////////////
#pragma region Local functions

private:

	void Add(string value) {

		string* temp_arr = new string[length + 1];

		for (int i = 0; i < length; i++)
			temp_arr[i] = mass[i];

		temp_arr[length] = value;

		mass = temp_arr;
		length++;
		return;
	}
	void Remove(int index) {

		if (index >= length)
			return;

		string* temp_arr = new string[length - 1];

		for (int i = 0; i < index; i++)
			temp_arr[i] = mass[i];

		for (int i = index + 1; i < length; i++)
			temp_arr[i - 1] = mass[i];

		mass = temp_arr;
		length--;
		return;
	}
	void Delempty() {
		for (int i = 0; i < length; i++)
			if (mass[i] == "") {
				Remove(i);
				i--;
			}
	}
	int Get_separator(string value) {//end of the smb path
		for (int i = value.length() - 1; i >= 0; i--) {
			if ((value[i] >= 48) && (value[i] <= 57))
				continue;
			else
				return i;
		}
		return false;
	}
	int Get_insert(int spr) {
		if (length < 2)
			return false;
		string numpath_first = mass[0];
		string numpath_second = mass[1];

		numpath_first = numpath_first.erase(0, spr + 1);
		numpath_second = numpath_second.erase(0, spr + 1);

		long long int first = 0;
		long long int second = 0;

		stringstream stream1(numpath_first);
		stringstream stream2(numpath_second);

		stream1 >> first;
		stream2 >> second;

		int insert = second - first;

		if (insert <= 0)
			return false;
		if (insert >= 250)
			return false;


		return insert;
	}
	int digit(int value) {
		int result = 0;
		while (value > 0) {
			value = value / 10;
			result++;
		}
		return result;
	}
	void remove_digit(int index) {
		string value = mass[index];
		int i = 0;
		for (i = value.length() - 1; i >= 0; i--)
			if ((value[i] > 57) && (value[i] < 48))
				break;
		if (i < value.length())
			value = value.erase(i, 1);
		mass[index] = value;
	}

#pragma endregion
/// //////////////////////////////////////////////////////////////////
};
