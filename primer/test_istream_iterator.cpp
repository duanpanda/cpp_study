#include <iostream>
using namespace std;

int main()
{
  istream_iterator<int> cin_it(cin); // reads ints from cin
  istream_iterator<int> end_of_stream; // end iterator value
  // writes Sales_items from the ofstream named outfile
  // each element is followed by a space
  // ofstream outfile;
  // ostream_iterator<Sales_item> output(outfile, " ");
  return 0;
}
