# Key take away starting with boost

Boost is a set of many libraries:
    - Most Boost libraries are header-only: they consist entirely of header files containing templates and inline functions, and require no separately-compiled library binaries or special treatment when linking.
        c++ -I path/to/boost_1_82_0 example.cpp -o example

    - To build the separately-compiled Boost libraries, you'll need to acquire library binaries.
        c++ -I boost_1_82_0 Ex2_UsingSeparatelyCompiledBoostLib.cpp -o Ex2_UsingSeparatelyCompiledBoostLib -L/usr/local/lib -lboost_regex
        
# References
https://www.boost.org/doc/libs/1_87_0/more/getting_started/unix-variants.html#id21
