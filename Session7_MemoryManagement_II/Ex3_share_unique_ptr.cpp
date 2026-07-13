#include "Ex3_share_unique_ptr.h"

void ShowInfo(const std::unique_ptr<Employee> &emp) {
    std::cout << "Employee project details: ";
    emp->GetProject()->ShowProjectDetails();
}
int main() {
    unique_ptr<Project> prj{new Project()};
    prj->SetName("Video Decoder");

    unique_ptr<Employee> e1{new Employee()};
    e1->SetProject(prj);
    unique_ptr<Employee> e2{new Employee()};
    e2->SetProject(prj);
    unique_ptr<Employee> e3{new Employee()};
    e3->SetProject(prj);

    ShowInfo(e1);
    // Segmentation fault
    // ShowInfo(e2);
    // prj->ShowProjectDetails();

    return 0;
}