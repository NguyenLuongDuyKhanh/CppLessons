#include <iostream>
using namespace std;

namespace top_level_namespace1
{
    namespace nested_namespaceA
    {
        void functionC()
        {
            cout <<"hello from another part of nested_namespaceA"<<endl;
        }
        
    };
};