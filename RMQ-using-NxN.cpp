//
// beautiful code
//

#include <algorithm>  // min
#include <bitset>
#include <cassert>  // assert
#include <cmath>
#include <csignal>
#include <deque>    // deque
#include <fstream>  // ifstream
#include <functional> // greater
#include <iomanip>  // setw, setfill
#include <iostream>
#include <limits>   // numeric_limits
#include <map>      // map, multimap
#include <numeric>
#include <queue>    // priority_queue (greatest on top, by default, use greater for smallest on top)
#include <set>      // set
#include <sstream>  // stringstream
#include <stack>    // stack
#include <tuple>    // tuple
#include <unordered_map>
#include <unordered_set> // unordered_set
#include <vector>   // vector

using namespace std;


bool ON = 1;
bool OFF = 0;

#ifdef DEBUGG
bool DEBUG_MODE = ON;
bool LOGS = ON;
#else
bool DEBUG_MODE = OFF;
bool LOGS = OFF;
#endif

template <typename Arg, typename... Args>
void debug(Arg&& arg, Args&&... args) {

	if (LOGS) {
		std::ostream& out = std::cout;
		out << std::forward<Arg>(arg);
		using expander = int[];
		(

			void)expander {
			0, (void(out << ' ' << std::forward<Args>(args)), 0)...
		};
	}
}

template <typename T>
ostream & operator<<(ostream &o1, const vector<T> &v1) {
	for (auto it = v1.begin(); it != v1.end(); it++) {
		o1 << setw(4) << *it << " ";
	}
	return o1;
}

template <typename T>
vector <T> range(T N1, T N2) {
	vector<T> numbers(N2 - N1);
	iota(numbers.begin(), numbers.end(), N1);
	return numbers;
}

template <typename T>
vector <T> zero_till(T N) {
	vector<T> numbers(N);
	iota(numbers.begin(), numbers.end(), 0);
	return numbers;
}

template <typename T>
vector <T> one_till(T N) {
	vector<T> numbers(N);
	iota(numbers.begin(), numbers.end(), 1);
	return numbers;
}

// -----------------------------------
// -----------------------------------
// -----------------------------------

// #define PTypeVal short // 1 to 50
//
//#define NTypeValue int // 1 to 10^5
//#define MTypeValue int // 1 to 10^5
//#define XTypeValue int // 1 to 10^9
//#define VTypeValue int // 0 to 10^6
//#define TypeValue unsigned long long // 0 to 10^6
//#define PTypeVal unsigned long long
//#define VTypeVal unsigned short // long long
//#define PTypeVal long long
//#define DTypeVal long long
//#define TTypeVal unsigned long long
//#define LTypeVal unsigned long long
//#define SumOfLTypeVal unsigned long long

// #define PTypeVal unsigned long long
#define NTypeVal int
#define EleTypeVal int
#define EleTypeVeryLargVal unsigned long long
// #define SizeT unsigned int
// -----------------------------------

/*
struct Node
{
	NTypeVal i;
	EleTypeVal d;
	Node *l, *r, *p;	// left, right, parent
};
*/

template <class NType, class EleType>
class NxN {

	NType N;
	EleType Ai;
	deque<NType> v1;   // input array, with N+1 elements - element at index 0, is not used

	deque<NType> v_seg;  // v_seg array, with N+1 elements - element at index 0, is not used
	deque<deque<NType>> v_seg2;  // v_seg array, with N+1 elements - element at index 0, is not used

								 // unordered_set <EleType> s1;
								 // unordered_multimap <NTypeVal, pair<NTypeVal, EleTypeVal>> m1;
								 // unordered_map <pair<NTypeVal, NTypeVal >, EleTypeVal> m1;

								 // unordered_multimap <NTypeVal, pair<NTypeVal, EleTypeVal>>
								 // pair<NTypeVal, EleTypeVal> least_gr_eq;

								 //NType   least_gr_eq_ri;
								 //EleType least_gr_eq_rmin;

public:

	NxN(istream &cin) {
		cin >> N;

		// v1.reserve(N);

		// get arr
		for (NType i = 0; i <= N - 1; i++) {
			cin >> Ai;
			v1.push_back(Ai);
		}

		///////// cout << one_till(N) << endl;
		// cout << v1 << endl;
		// cout << setw(4) << Ai << " ";
	}

	void build_for_NxN_RMQ_wrapper() {
		v_seg2.resize(N);
		for (int i = 0; i <= N - 1; i++) {
			v_seg2[i].resize(N);
			fill(v_seg2[i].begin(), v_seg2[i].end(), numeric_limits<EleType>::max());
		}
		build_for_NxN_RMQ();
	}

	void build_for_NxN_RMQ() {

		for (NType ql = 0; ql <= N - 1; ql++) {
			v_seg2[ql][ql] = v1[ql];
		}

		for (NType ql = 0; ql <= N - 1; ql++) {
			for (NType qh = ql + 1; qh <= N - 1; qh++) {
				v_seg2[ql][qh] = min(v_seg2[ql][qh - 1], v1[qh]);
			}
		}

	}

	void NxN_RMQ() {
		for (NType ql = 0; ql <= N - 1; ql++) {
			for (NType qh = ql; qh <= N - 1; qh++) {

				cout << "[" << ql << "," << qh << "] = " << v_seg2[ql][qh] << endl;
			}
		}
	}

	void doMain() {

		build_for_NxN_RMQ_wrapper();
		NxN_RMQ();

	}
};

// testsss
#define ReturnCountTypeValue char
vector < pair < vector<string>, vector<ReturnCountTypeValue >>> tests = {
	/*	{
			{
				"5",
				"5 10 40 30 28"
			},
			{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)
		}, */
		/*
		*/
	{
					{
						"11",
						"9 3  7 1 8  12 10 20  15 18 5"
					},
					{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)		5*10 = 50
				},
	/*
	{
					{
						"12",
							"9 3  7 1 8  12 12 10 20  15 18 5"
					},
					{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)	6*10 = 50
				},

{
		{
			"5",
			"1 2 3 4 5"
		},
		{ 0, 0, 0, 0, 0, 0, 0, 0 } // 4(new) 3 (old)
	}*/
};

// template <class NType, class VType, class PType, class DType>
template <class NType, class EleType>
class Cls1 {

	//    HNType n;
	//    MType m;
	// deque <pair<VType, NType > > p1;
	//    XType x;
	//    string S;
	//    LenType k;
	//    TType type;
	//    HVType v;
	//    VType v;
	//    PType P;
	//    DType D;
	//    KType K;
	// Heap<NType, pair<LType, TType>> h1;
	// multiset<HVType> se1;
	// deque<HVType> p1;

public:

	Cls1() {
		// LOGS = OFF;
	}


	vector <ReturnCountTypeValue> testFunction(istream & cin) {
		// debug("testFunction - begin\n\n");
		vector <ReturnCountTypeValue> res;
		// --------------------

		// LOGS = 0;


		NxN <NType, EleType> o1(cin);
		o1.doMain();


		auto actual_result = 0;
		res.push_back(actual_result);

		return res;
	}

};


int main() {

	if (!DEBUG_MODE) {

		Cls1<NTypeVal, EleTypeVal> o;
		o.testFunction(cin);

		return 0;
	}
	else {

		for (unsigned long i = 0; i < tests.size(); i++) {
			// debug("----------------------- input getting ready ----------------------------- ", "\n");

			auto input = tests[i].first;
			auto expected_output = tests[i].second;

			std::stringstream ss;
			istream &cin = ss;

			for (size_t i = 0; i < input.size(); i++) {
				// debug(input[i], "\n");
				ss << input[i] << endl;
			}

			/*
			ifstream ifs;
			// ifs.open("../lr_input09_dummy.txt");
			ifs.open("../lr_input09.txt");
			string temp;
			vector<string> a;
			getline(ifs, temp); 	ss << temp << endl;
			getline(ifs, temp); 	ss << temp << endl;
			*/


			// debug("----------------------- input ready ----------------------------- ", "\n");

			Cls1<NTypeVal, EleTypeVal> o;
			// Cls1<NTypeVal, VTypeVal, PTypeVal, DTypeVal> o;
			// Cls1<NTypeVal, LTypeVal> o;
			// auto actual_result = o.testFunction(cin, q)[0];
			auto actual_result = o.testFunction(cin)[0];

			//            for (PTypeVal k = 0; k < q; k++) {
			//            Cls1<NTypeVal, LTypeVal, TTypeVal> o;
			//                // // debug("\tactual_result ", actual_result, " ", "expected_output ", expected_output[k], "\n");
			//
			//                // assert(actual_result == expected_output[k]);
			//            }

			// break;

		} // for tests.size()

		return 0;
	}

	return 0;
}
