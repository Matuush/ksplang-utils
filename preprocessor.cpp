#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::vector;

struct func {
   string name;
   vector<vector<string>> code;
   func(string p_n, vector<vector<string>> p_c = vector<vector<string>>(0)) : name(p_n), code(p_c) {}
   void add(vector<string> line) {
      code.push_back(line);
   }
};

int main(int argc, char* argv[]) {
   std::ifstream infile(argv[1]);
   string line;
   std::vector<func> funcs = {};
   bool active = false;
   vector<vector<string>> code(0);

   while(std::getline(infile, line)) {
      std::stringstream stream(line);
      string inst;
      vector<string> list(0);
      while(std::getline(stream, inst, ' '))
         list.push_back(inst);

      // comments
      bool com = false;
      for(int i = 0; i < list.size(); i++) {
         if(list[i][0] == '/' && list[i][1] == '/')
            com = true;
         if(com) {
            list.erase(list.begin() + i);
            i--;
         }
      }
      
      // functions
      if(list.size() > 0 && list[0] == "def") {
         funcs.push_back(func(list[1]));
         if(active) return 1;
         active = true;
         continue;
      }
      else if(list.size() > 0 && list[0] == "end") {
         if(!active) return 2;
         active = false;
         continue;
      }
      else if(active) {
         funcs[funcs.size()-1].add(list);
         continue;
      }

      // paste functions
      if(!active) {
         bool isf = false; int i_f = 0;
         if(list.size() > 0) {
            for(int f = 0; f < funcs.size(); f++) 
               if(funcs[f].name == list[0]) isf = true, i_f = f;
         }
         if(isf) {
            for(vector<string> v : funcs[i_f].code)
               code.push_back(v);
         }
         else
            code.push_back(list);
      }
   }

   string outname = argv[1];
   outname += ".out";
   std::ofstream out(outname);
   for(vector<string> line : code) {
      for(string inst : line)
         out << inst << " ";
      out << std::endl;
   }
   return 0;
}
