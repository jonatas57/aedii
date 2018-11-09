#include <iostream>
#include "tn_trie.h"

using namespace std;

int main() {
  string url;
  tn_trie_node *root = new_node();
  while (cin >> url && url != "-1") {
    insert(root, url);
  }
  while (cin >> url && url != "-2") {
    cout << "Search " << url << ":" << endl;
    tn_suggest(root, url);
  }
  return 0;
}
