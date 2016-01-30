/*
 * parenthesis.cpp
 *
 *  Created on: 27/08/2014
 *      Author: diego
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

vector<string> genParenthesis(int n);

int main()
{
	auto pars = genParenthesis(4);
	copy(pars.begin(),pars.end(),ostream_iterator<string>(cout,", "));
	cout << endl;
}

vector<string> genParenthesis(int n)
{
	struct Gen {
		vector<string> result;
		string current;
		int n;

		Gen(int n): n(n) {}

		void generate(char c, int left, int right)
		{
			current.push_back(c);
			if( current.size() == size_t(n*2) ) {
				if( left == n && right == n ) {
					result.push_back(current);
				}
			} else
			if( left <= n && left >= right ) {
				generate('(',left+1,right);
				generate(')',left,right+1);
			}
			current.pop_back();
		}
	};

	Gen gen(n);
	gen.generate('(',1,0);
	return gen.result;
}
