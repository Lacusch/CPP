# TODO

Now, add the execute(`Bureaucrat const & executor`) const member function to
the base form and implement a function to execute the form’s action of the concrete
classes. You have to check that the form is signed and that the grade of the bureaucrat
attempting to execute the form is high enough. Otherwise, throw an __appropriate
exception__.

Whether you want to check the requirements in every concrete class or __in the base
class (then call another function to execute the form)__ is up to you. However, one way is
prettier than the other one (the second).

1. AForm : `Bureaucrat const & executor = 0`
    - create a `check_Requirements()` function in the `AForm` class, that throws an exception at the wrong value, and that runs the `Bureaucrat const & executor()` function at right value.
1. Bureaucrat :  `executeForm(Form const & form)`
