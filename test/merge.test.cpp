#include <iostream>
#include <assert.h>
#include "../lib/merge.hpp"

using namespace std;

template<typename Comparable>
void test_sort(void (*sort)(vector<Comparable>&), vector<Comparable>&  unsorted, vector<Comparable>& sorted)
{
	sort(unsorted);
	assert(unsorted == sorted);
}

void test_empty_vector()
{
	vector<int> empty_vector( 0 ), another_empty_vector( 0 );
	test_sort<int>(cpp_sort::merge_sort<int>, empty_vector, another_empty_vector);
}

void test_singleton_vector()
{
	vector<int> singleton_vector{ 1 }, another_singleton_vector{ 1 };
	test_sort<int>(cpp_sort::merge_sort<int>, singleton_vector, another_singleton_vector);
}

void test_two_element_vector()
{
	vector<int> unsorted_vector{ 2,1 }, sorted_vector{ 1,2 };
	test_sort<int>(cpp_sort::merge_sort<int>, unsorted_vector, sorted_vector);
}

void test_int_vector()
{
	vector<int> unsorted_vector{ -1, 2, 3, 3, 3, -4, 5, 0, -8 };
	vector<int> sorted_vector{ -8, -4, -1, 0, 2, 3, 3, 3, 5 };
	test_sort<int>(cpp_sort::merge_sort<int>, unsorted_vector, sorted_vector);
}

void test_char_vector()
{
	string unsorted( "beabdbc" ), sorted( "abbbcde" );
	vector<char> unsorted_vector( unsorted.begin(), unsorted.end() ),
		sorted_vector( sorted.begin(), sorted.end() );

	test_sort<char>(cpp_sort::merge_sort<char>, unsorted_vector, sorted_vector);
}

int main()
{
	test_empty_vector();
	test_singleton_vector();
	test_two_element_vector();
	test_int_vector();
	test_char_vector();
	cout << "All mergesort tests passed" << endl;
}
