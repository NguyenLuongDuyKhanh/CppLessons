#include "header_file.h"
#include "header_file_bis.h"
using namespace top_level_namespace2;
using namespace top_level_namespace1;
using namespace nested_namespaceB;

int main()
{
    /*
        using namespace std was put in header_file.h so don't need it here
    */
    cout << "Hello"<<endl;
    cout <<top_level_namespace2::variable<<endl;
    top_level_namespace2::function();
    top_level_namespace1::nested_namespaceA::functionC();
    cout <<nested_namespaceB::variable<<endl;
}