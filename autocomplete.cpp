#include "autocomplete.h"
#include<iostream>
using namespace std;


/* EFFECTS: Traverses the Tree based on the charactes in the prefix and 
          returns the TreeNode that we end at. If we cannot find a valid node,
          we return an empty TreeNode. The index variable keeps track of what 
          character we're at in prefix.
*/ 

TreeNode<char> FindNode(TreeNode<char> node, std::string prefix, int index) {
  cout << node.GetValue();
  return TreeNode<char>();
}

/* EFFECTS: Collects all the words starting from a given TreeNode. For each word, 
          prepends the word with the prefix and adds it to the results vector.
*/

void CollectWords(TreeNode<char> node, std::string prefix, std::vector<std::string> &results) {
}

/* EFFECTS: Returns the list of all possible words that can be made starting with
          the letters in prefix, based on traversing the tree with the given root.
*/

std::vector<std::string> GetCandidates(TreeNode<char> root, std::string prefix) {
  return std::vector<std::string>();
}
