#include <iostream>

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
    Project* m_Project{};
public:
    void SetProject(Project*prj) {
        m_Project = prj;
    }
    const Project* GetProject() const {
        return m_Project;
    }    
};