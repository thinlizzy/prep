#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using Index = int;
using Value = int;
using Values = vector<Value>;

class Frankenstein {
	struct Context {
		Value value;
		int total;
		Index first; // closed interval
		Index last;  // open interval
		int totalSliced(Index iMin, Index iMax) const;
	};
	vector<Context> rank;
public:
	Frankenstein(Values const & values);
	void solve(Index iMin, Index iMax);
};

int main()
{
	Index total;
	Values values;
	for( cin >> total; total > 0; cin >> total ) {
		int queries;
		cin >> queries;

		values.resize(total);
		for( Index i = 0; i < total; ++i ) {
			cin >> values[i];
		}

		Frankenstein frank(values);

		for( int q = 0; q < queries; ++q ) {
			Index iMin,iMax;
			cin >> iMin >> iMax;
			frank.solve(iMin,iMax);
		}
	}
}

Frankenstein::Frankenstein(Values const & values)
{
	Context tc = {values[0], 1, 0, 0};

	for( tc.last = 1; tc.last < Index(values.size()); ++tc.last ) {
		auto value = values[tc.last];
		if( value == tc.value ) {
			++tc.total;
		} else {
			rank.push_back(tc);
			tc.value = value;
			tc.total = 1;
			tc.first = tc.last;
		}
	}
	rank.push_back(tc);

	sort(rank.begin(),rank.end(),[](Context const & c1, Context const & c2) {
		return c1.total > c2.total;
	});
}

void Frankenstein::solve(Index iMin, Index iMax)
{
	int bestTotal = 0;
	for( auto const & tc : rank ) {
		auto total = tc.totalSliced(iMin,iMax);
		if( total > bestTotal ) {
			bestTotal = total;
		}
		// slicing did not happen. totals only will be lower now. stop
		if( total == tc.total ) break;
	}
	cout << bestTotal << endl;
}

int Frankenstein::Context::totalSliced(Index iMin, Index iMax) const
{
	--iMin; // now both ranges are [closed,open)

	auto result = total;
	if( first < iMin) {
		result -= (iMin - first);
	}
	if( last > iMax ) {
		result -= (last-iMax);
	}
	return result;
}
