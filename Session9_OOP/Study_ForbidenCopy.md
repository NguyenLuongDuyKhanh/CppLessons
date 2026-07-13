There are 2 ways:
    - Turn the copy constructor to private
    - Turn the copy constructor to delete
  
  
Example 1
```
class noncopyable {
protected:
    noncopyable() = default;
    ~noncopyable() = default;

private:
    noncopyable(const noncopyable&);
    noncopyable& operator=(const noncopyable&);
};
```

Example 2
```
class Logger {
public:
    Logger() = default;

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};
```