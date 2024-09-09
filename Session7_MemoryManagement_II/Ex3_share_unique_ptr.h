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
    unique_ptr<Project> m_Project{};
public:
    void SetProject(unique_ptr<Project> &prj) {
        m_Project = move(prj);
    }
    const unique_ptr<Project>& GetProject() const {
        return m_Project;
    }    
};