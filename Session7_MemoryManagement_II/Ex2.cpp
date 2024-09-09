#include "Ex2.h"

void ShowInfo(Employee *emp) {
    std::cout << "Employee project details: ";
    emp->GetProject()->ShowProjectDetails();
}
int main() {
    Project* prj = new Project();
    prj->SetName("Video Decoder");

    Employee *e1 = new Employee{};
    e1->SetProject(prj);
    Employee *e2 = new Employee{};
    e2->SetProject(prj);
    Employee *e3 = new Employee{};
    e3->SetProject(prj);

    ShowInfo(e1);
    ShowInfo(e2);
    prj->ShowProjectDetails();

    delete prj, e1, e2, e3;
    return 0;
}