#include <iostream>
using namespace std;

namespace top_level_namespace1
{
    namespace nested_namespaceA
    {
        void function()
        {
            cout <<"hello from nested_namespaceA"<<endl;
        }
        
    };

    namespace nested_namespaceB
    {
        string variable = "hello from nested_namespaceB";
    };
};
namespace top_level_namespace2
{
    string variable = "hello from top_level_namespace2";
    void function()
    {
        cout <<"hello from top_level_namespace2"<<endl;
    }
};