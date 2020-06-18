#include <iostream>
#include <vector>
#include <map>
#include <fstream>

int printToJson(std::vector<std::map<std::string, std::string>> map_vector)
{
        std::ofstream my_file("data.json");
        my_file << "[ \n";
        for (auto x : map_vector)
        {
                if (x != *map_vector.begin())
                {
                        my_file << ",";
                }

                my_file << "{";
                for (auto tup : x)
                {
                        if (tup != (*(x.begin())))
                        {
                                my_file << ",";
                        }
                        my_file << ("\"" + tup.first + "\":" + "\"" + tup.second + "\"");
                        std::cout << (tup.first);
                        std::cout << ((x.begin())->first);
                }
                my_file << "}\n";
        }
        my_file << "]";
        my_file.close();
        return 1;
}
int main(int argc, char* argv[])
{
        std::string key11, val11, key12, val12, key2, val2;
        std::map<std::string, std::string> m1, m2;
        key11 = "key11";
        key12 = "key12";
        key2 = "key2";
        val11 = "val11";
        val12 = argv[0];
        val2 = argv[1];
        m1.insert({key11, val11});
        m1.insert({key12, val12});
        m2.insert({key2, val2});

        std::vector<std::map<std::string, std::string>> map_vector;
        map_vector.push_back(m1);
        map_vector.push_back(m2);
        printToJson(map_vector);
}