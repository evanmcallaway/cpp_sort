// merge.hpp
#ifndef MERGE_HPP
#define MERGE_HPP

#include <vector>

using namespace std;

namespace cpp_sort {

	template <typename Comparable>
	void merge( vector <Comparable>& a, vector<Comparable>& tmp, unsigned int leftPos, unsigned int rightPos, unsigned int rightEnd )
	{
		unsigned int leftEnd = rightPos - 1;
		unsigned int tmpPos = 0;
		unsigned int numElements = rightEnd - leftPos + 1;

		// merge the two sides until one side is depleated
		while( leftPos <= leftEnd && rightPos <= rightEnd )
			tmp[tmpPos++] = ( a[leftPos] <= a[rightPos] ) ? a[leftPos++] : a[rightPos++];

		// tack any remaining to the end
		while( leftPos <= leftEnd )
			tmp[tmpPos++] = a[leftPos++];
		while( rightPos <= rightEnd )
			tmp[tmpPos++] = a[rightPos++];

		// copy back to the original array
		for( unsigned int i = 0; i < numElements; ++i)
			a[rightEnd--] = tmp[--tmpPos];
	}

	template <typename Comparable>
	void merge_sort( vector<Comparable>& a, vector<Comparable>& tmp, unsigned int left, unsigned int right )
	{
		if( left < right ) {
			unsigned int center = (left + right) / 2;
			merge_sort( a, tmp, left, center );
			merge_sort( a, tmp, center + 1, right );
			merge( a, tmp, left, center + 1, right );
		}
	}


	template <typename Comparable>
	void merge_sort( vector<Comparable>& a )
	{
		vector<Comparable> tmp( a.size() );
		if ( a.size() > 0 )
			merge_sort( a, tmp, 0, a.size() - 1 );
	}
}
#endif
