//#include <iostream>
//#include <stack>
//using namespace std;
//#define NO_OF_CITIES 8
//
//struct cityData {
//	string name;
//	int outConCount;
//	int* outCons;
//	bool seen;
//	int pred;
//
//	cityData(string name = "", int outConCount = 0, int* outCons = NULL) {
//		this->name = name;
//		this->outConCount = outConCount;
//		this->outCons = outCons;
//		seen = false;
//		pred = -1;
//	}
//};
//
//int indexOfCity(cityData cities[],string name) {
//	for (int i = 0; i < NO_OF_CITIES; i++) {
//		//cout <<"for index "<< cities[i].name << endl; //->
//		if (cities[i].name == name) return i;
//	}
//	return -1;
//}
//bool search(cityData cities[], cityData currentCity, cityData destCity) {
//	if (currentCity.name == destCity.name) {
//		int indexOfDCity = indexOfCity(cities, destCity.name);
//		cities[indexOfDCity].seen = true;
//		return true;
//	}
//	int indexOfCurrCity = indexOfCity(cities, currentCity.name);
//	//cout << indexOfCurrCity << " " << currentCity.name << " -> ";// ->
//	if (currentCity.outCons == nullptr) return false;
//	for (int i = 0; i < currentCity.outConCount; i++) {
//		cities[indexOfCurrCity].seen = true;
//		int index_of_outCity = currentCity.outCons[i];
//		cities[index_of_outCity].pred = indexOfCurrCity;
//		if (search(cities, cities[index_of_outCity], destCity)) return true;
//	}
//	return false;
//}
//
//int main() {
//
//	int out0[2] = { 1,3 };
//	int out1[1] = { 7 };
//	int out4[3] = { 1,3,6};
//	int out5[2] = { 0,3 };
//	int out6[1] = { 4 };
//	int out7[1] = { 5 };
//
//	cityData c1("Lahore", 2, out0);
//	cityData c2("Kasur", 1, out1);
//	cityData c3("Jazira", 0);
//	cityData c4("Bakhar", 0);
//	cityData c5("Okara", 3, out4);
//	cityData c6("Jhang", 2, out5);
//	cityData c7("Khushab", 1, out6);
//	cityData c8("Sahiwal", 1, out7);
//
//	cityData cities[NO_OF_CITIES] = { c1,c2,c3,c4,c5,c6,c7,c8 };
//	cout << search(cities, c1, c4) << endl;
//
//	for (int i = 0; i < NO_OF_CITIES; i++)
//	{
//		if (cities[i].seen == true) {
//			cout << cities[i].name << " -> "<< cities[i].pred << endl;
//		}
//	}
//	cout << endl;
//}