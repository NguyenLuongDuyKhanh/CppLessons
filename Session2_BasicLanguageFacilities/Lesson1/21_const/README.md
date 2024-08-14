## const function
    It means that *this is const inside that member function, i.e. it doesn't alter the object.



Ex1.cpp: In member function ‘int SampleClass::sampleConstFunction() const’:
Ex1.cpp:9:26: error: passing ‘const SampleClass’ as ‘this’ argument discards qualifiers [-fpermissive]
    9 |             privateSetter();
      |             ~~~~~~~~~~~~~^~
Ex1.cpp:13:14: note:   in call to ‘void SampleClass::privateSetter()’
   13 |         void privateSetter() {
      |              ^~~~~~~~~~~~~
