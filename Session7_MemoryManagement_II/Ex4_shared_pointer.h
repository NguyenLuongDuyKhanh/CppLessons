#include <iostream>
#include <memory>
using namespace std;

class Project {
    std::string m_name;
public:
    void SetName(const std::string &name) {
        m_name = name;
    }
    void ShowProjectDetails() const {
        std::cout << "[Project Name]" << m_name << std::endl;
    }
};

class Employee {
    shared_ptr<Project> m_Project{};
public:
    void SetProject(const shared_ptr<Project> &prj) {
        m_Project = prj;
    }
    const shared_ptr<Project> GetProject() const {
        return m_Project;
    }    
};