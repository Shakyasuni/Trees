#include <iostream>
#include <sstream>
#include <vector>


bool IsBST(std::vector<int> &binary_tree) {
  // Implement this function.
  if(binary_tree.empty())
    return true;
  for(int i = 0; i < binary_tree.size(); i++){
    if(2 * i + 1 < binary_tree.size()){
      if(binary_tree[i] < binary_tree[2 * i + 1]){
        return false;
      }
    }
    if(2 * i + 2 < binary_tree.size()){
     if(binary_tree[i] > binary_tree[2 * i + 2]){
       return false;
     }
   }
  }
  return true;
}


int main() {
  std::vector<int> binary_tree;
  std::string input;
  getline(std::cin, input);
  std::stringstream iss(input);
  int number;
  while (iss >> number) {
    binary_tree.push_back(number);
  }
  if (IsBST(binary_tree)) {
    std::cout << "True";
  } else {
    std::cout << "False";
  }
  return 0;
}

