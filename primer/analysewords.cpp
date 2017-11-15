#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// comparison function to be used to sort by word length
bool isShorter(const string &s1, const string &s2)
{
  return s1.size() < s2.size();
}

// determine whether a length of a given word is 6 or more
bool GT6(const string &s)
{
  return s.size() >= 6;
}

inline string make_plural(unsigned int n, const char* str, const char* postfix)
{
  if (n > 1)
    return string(str) + string(postfix);
  else
    return string(str);
}

int main()
{
  vector<string> words;
  // copy contents of each book into a single vector
  string next_word;

  while (cin >> next_word) {
    // insert next book's contents at end of words
    words.push_back(next_word);
  }

  int i;
  for (i = 0; i < words.size(); ++i) {
    cout << words.at(i) << ' ';
  }
  cout << endl;

  // sort words alphabetically so we can find the duplicates
  sort(words.begin(), words.end());

  for (i = 0; i < words.size(); ++i) {
    cout << words.at(i) << ' ';
  }
  cout << endl;

  // eliminate duplicate words:
  // unique reorders words so that each word appears once in the front portion
  //     of words and returns an iterator one past the unique range;
  // erase uses a vector operation to remove the nonunique elements
  vector<string>::iterator end_unique = unique(words.begin(), words.end());
  for (i = 0; i < words.size(); ++i) {
    cout << words.at(i) << ' ';
  }
  cout << endl;
  words.erase(end_unique, words.end());

  for (i = 0; i < words.size(); ++i) {
    cout << words.at(i) << ' ';
  }
  cout << endl;

  // sort words by size, but maintain alphabetic order for words of the same size
  stable_sort(words.begin(), words.end(), isShorter);
  vector<string>::size_type wc = count_if(words.begin(), words.end(), GT6);

  cout << wc << " " << make_plural(wc, "word", "s")
       << " 6 characters or longer" << endl;

  return 0;
}
