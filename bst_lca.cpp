#include <iostream>
#include <sstream>
#include <vector>


int GetLCA(std::vector<int> &bst, int l, int m) {
  std::vector<int> path1;
  std::vector<int> path2;
  int index1=0,index2=0;

  while(bst[index1]!=l){
  	path1.push_back(bst[index1]);
  	if (l < bst[index1]){
  		index1 = index1 * 2 + 1;
	  }
	else{
		index1= index1 * 2 + 2;
	}
  }
  while(bst[index2]!=m){
  	path2.push_back(bst[index2]);
  	if (m < bst[index2]){
  		index2 = index2 * 2 + 1;
	  }
	else{
		index2= index2 * 2 + 2;
	}
  }
  int checker=0;
  int a;
  if(index1 > index2){
    a = path1.size();
  }else{
    a= path2.size();
  }
  while(path1[checker]==path2[checker]){
  	checker++;
        if(checker >= a){
            break;
        }
  }
  return path1[checker-1];
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
  int l, m;
  std::cin >> l;
  std::cin >> m;
  
  std::vector<int> path;
  int lca = GetLCA(bst, l, m);

  std::cout << "lca = " << lca;
  return 0;
}

