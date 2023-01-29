
#ifndef __AUTOCOMPLETE_H___
#define __AUTOCOMPLETE_H___


#include <vector> 
#include "tree_node.h"
#include <string>


std::vector<TreeNode<char>> Children;
TreeNode<char> lastnode;
TreeNode<char> FindNode(TreeNode<char> node, std::string prefix, int index){
  if(prefix.size() == 0 || prefix[0] == '*'){
    return node;
  }
  int count = 0;
  int j = 0;
  while(j < node.GetChildren().size()){
    if(prefix[index] == node.GetChildren()[j].GetValue()){
      count++;
    }
    j++;
  }
  if(node.GetValue() == prefix[prefix.size() - 1]){
    if(index != prefix.size()){
    }
    else{
      return node;
    }
  }
  if(count == 0){
    return TreeNode<char> ();
  }
  else{
    for(int i = 0; i < node.GetChildren().size(); i++){
      if(node.GetChildren()[i].GetValue() == prefix[index]){
        index++;
        lastnode = FindNode(node.GetChildren()[i], prefix, index);
        break;
      }
    }
    return lastnode;
  }
}


int id = 0;
std::string s;
std::string ret;
void CollectWords(TreeNode<char> node, std::string prefix, std::vector<std::string> &results){
  for(int i = 0; i < node.GetChildren().size(); i++){
    if(node.GetChildren()[i].GetValue() =='$'){
      ret = prefix;
      ret.append(s);
      results.push_back(ret);
    }
    else{
    s.push_back(node.GetChildren()[i].GetValue());
    CollectWords(node.GetChildren()[i], prefix, results);
    s.pop_back();
    }
  }
}



std::vector<std::string> GetCandidates(TreeNode<char> root, std::string prefix){
  TreeNode<char> get_node;
  get_node = FindNode(root, prefix, 0);
  std::vector<std::string> final;
  CollectWords(get_node, prefix, final);
  return final;
}

#endif /* __AUTOCOMPLETE_H___ */