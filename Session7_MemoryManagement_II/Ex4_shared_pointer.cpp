#include "Ex4_shared_pointer.h"

void ShowInfo(unique_ptr<Employee>& emp) {
    std::cout << "Employee project details: ";
    emp->GetProject()->ShowProjectDetails();
}
int main() {
    shared_ptr<Project> prj{new Project()};
    prj->SetName("Video Decoder");

    unique_ptr<Employee> e1{new Employee()};
    e1->SetProject(prj);
    unique_ptr<Employee> e2{new Employee()};
    e2->SetProject(prj);
    unique_ptr<Employee> e3{new Employee()};
    e3->SetProject(prj);

    ShowInfo(e1);
    ShowInfo(e2);
    prj->ShowProjectDetails();

    /*  use_count return the number of references to a smart pointer
        It is four originally: prj, e1, e2, e3, e4
        Reset e3 will decrease it by 1
        Reset prj make other object cannot refer to it -> use_count return 0
    */
    // e3.reset();
    // prj.reset();
    cout << "Reference count: " << prj.use_count() << endl;
    
    // cannot delete smart pointer
    // error: type ‘class std::shared_ptr<Project>’ argument given to ‘delete’, expected pointer
    // delete prj, e1, e2, e3;
    return 0;
}