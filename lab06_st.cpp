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
//int indexOfCity(cityData cities[], string name) {
//	for (int i = 0; i < NO_OF_CITIES; i++) {
//		if (cities[i].name == name) return i;
//	}
//	return -1;
//}
//bool search(cityData cities[], cityData currentCity, cityData destCity) {
//	stack<cityData> st;
//	st.push(currentCity);
//	while (!st.empty()) {
//		cityData c = st.top();
//		st.pop();
//		int indexOfCurrCity = indexOfCity(cities, c.name);
//		if (c.name == destCity.name) {
//			int indexOfDCity = indexOfCity(cities, destCity.name);
//			cities[indexOfDCity].seen = true;
//			return true;
//		}
//		else {
//			cities[indexOfCurrCity].seen = true;
//	        for (int i = 0; i < c.outConCount; i++) {
//				int index_of_outCity = c.outCons[i];
//				cities[index_of_outCity].pred = indexOfCurrCity;
//				/*if (cities[index_of_outCity].seen == true) cities[index_of_outCity].seen = false;*/
//				st.push(cities[index_of_outCity]);
//			}
//			/*cities[indexOfCurrCity].seen = false;*/
//		}
//	}
//	return false;
//}
//
//int gcd(int m, int n) {
//	int rem;
//	while (n != 0) {
//		rem = m % n;
//		m = n;
//		n = rem;
//	}
//	return m;
//}
//int main() {
//
//	int out0[2] = { 1,3 };
//	int out1[1] = { 7 };
//	int out4[3] = { 1,3,6 };
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
//	/*cityData cities[NO_OF_CITIES] = { c1,c2,c3,c4,c5,c6,c7,c8 };
//	cout << search(cities, c1, c6) << endl;
//
//	for (int i = 0; i < NO_OF_CITIES; i++)
//	{
//		if (cities[i].seen == true) {
//			cout << cities[i].name << " -> " << cities[i].pred << endl;
//		}
//	}
//	cout << endl;*/
//	cout << gcd(8, 20) << endl;
//	cout << gcd(10, 6) << endl;
//}