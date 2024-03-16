#include "splay.hpp"
using namespace std;


/* 
 * Main method, do not change
 */
int main(int argc, const char * argv[]) {
  SplayTree splaytree;
  std::string filename = argv[1];
  freopen(filename.c_str(), "r", stdin);
  std::string input;
  int data;
  while(std::cin >> input){
    if (input == "insert"){
      std::cin>>data;
      splaytree.insert(data);
    } else if(input == "delete"){
      std::cin>>data;
      splaytree.remove(data);
    } else if(input == "print"){
      splaytree.print();
      std::cout << "\n";
    } else{
      std::cout<<"Data not consistent in file";
      break;
    }
  }
  return 0;
}
/*
 * END main method
 */
