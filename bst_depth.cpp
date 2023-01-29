#include <iostream>
#include <sstream>
#include <vector>


int GetDepthAndPath(std::vector<int> &bst, int target, std::vector<int> &path) {
  if(bst.empty()){
    return -1;
  }
  int distance = 0;
  for(int i = 0; i < bst.size(); i++){
    if(bst[i] == target){
      path.push_back(bst[i]);
      return distance;
    }
    if(bst[i] > target){
      path.push_back(bst[i]);
      i = 2 * i;
      distance++;
    }
    if(bst[i] < target){
      path.push_back(bst[i]);
      i = 2 * i + 1;
      distance++;
    }
  }
  return distance;
}



int main() {
  std::vector<int> bst;
  std::string input;
  getline(std::cin, input);
  std::stringstream iss(input);
  int number;
  while (iss >> number) {
    bst.push_back(number);
  }
  int target;
  std::cin >> target;
  
  std::vector<int> path;
  int depth = GetDepthAndPath(bst, target, path);

  std::cout << "depth = " << depth << std::endl;
  std::cout << "path = ";
  for(int i = 0; i < path.size(); i++) {
    std::cout << path[i];
    if (i < path.size() - 1) {
      std::cout << " ";
    }
  }
  return 0;
}

