```markdown
### Copy Constructor in C++

A copy constructor is a member function that initializes an object using another object of the same class.

#### Syntax of Copy Constructor
Copy constructor takes a reference to an object of the same class as an argument.

```cpp
ClassName (ClassName &obj)
{
  // body_containing_logic
}
```
Just like the default constructor, the C++ compiler also provides an implicit copy constructor if the explicit copy constructor definition is not present. Here, it is to be noted that, unlike the default constructor where the presence of any type of explicit constructor results in the deletion of the implicit default constructor, the implicit copy constructor will always be created by the compiler if there is no explicit copy constructor or explicit move constructor is present.

#### Examples of Copy Constructor
The below examples demonstrate how to use the copy constructors in C++.

##### Example 1: Illustration of Implicit Copy Constructor

```cpp
// C++ program to illustrate the use of Implicit copy
// constructor
#include <iostream>
using namespace std;
 
class Sample {
    int id;
 
public:
    // parameterized constructor
    Sample(int x) { id = x; }
    void display() { cout << "ID=" << id; }
};
 
int main()
{
    Sample obj1(10);
    obj1.display();
    cout << endl;
 
    // creating an object of type Sample from the obj
    Sample obj2(obj1); // or obj2=obj1;
    obj2.display();
    return 0;
}
```

##### Example 2: Defining of Explicit Copy Constructor

```cpp
// C++ Program to demonstrate how to define the explicit
// copy constructor
#include <iostream>
using namespace std;
 
class Sample {
    int id;
 
public:
    // default constructor with empty body
    Sample() {}
 
    // parameterized constructor
    Sample(int x) { id = x; }
 
    // copy constructor
    Sample(Sample& t) { id = t.id; }
 
    void display() { cout << "ID=" << id; }
};
 
// driver code
int main()
{
    Sample obj1(10);
    obj1.display();
    cout << endl;
 
    // copy constructor called
    Sample obj2(obj1); // or obj2=obj1;
    obj2.display();
 
    return 0;
}
```

##### Example 3: Defining of Explicit Copy Constructor with Parameterized Constructor

```cpp
// C++ program to demonstrate copy construction along with
// parameterized constructor
#include <iostream>
#include <string.h>
using namespace std;
 
// class definition
class student {
    int rno;
    char name[50];
    double fee;
 
public:
    student(int, char[], double);
    student(student& t) // copy constructor
    {
        rno = t.rno;
        strcpy(name, t.name);
        fee = t.fee;
    }
 
    void display();
};
 
student::student(int no, char n[], double f)
{
    rno = no;
    strcpy(name, n);
    fee = f;
}
 
void student::display()
{
    cout << endl << rno << "\t" << name << "\t" << fee;
}
 
int main()
{
    student s(1001, "Manjeet", 10000);
    s.display();
 
    student manjeet(s); // copy constructor called
    manjeet.display();
 
    return 0;
}
```

#### Uses of Copy Constructor
- Constructs a new object by copying values from an existing object.
- Can be used to perform deep copy.
- Modify specific attributes during the copy process if needed.

### Move Constructor in C++

The move constructor is a recent addition to the family of constructors in C++. It is like a copy constructor that constructs the object from the already existing objects, but instead of copying the object in the new memory, it makes use of move semantics to transfer the ownership of the already created object to the new object without creating extra copies.

It can be seen as stealing the resources from other objects.

#### Syntax of Move Constructor in C++
```cpp
className (className&& obj) {
     // body of the constructor
}
```

The move constructor takes the rvalue reference of the object of the same class and transfers the ownership of this object to the newly created object.

Like a copy constructor, the compiler will create a move constructor for each class that does not have any explicit move constructor.

#### Examples of Move Constructor
The below examples demonstrate how to use the move constructors in C++.

##### Example 1: Defining Move Constructor

```cpp
// C++ Program to illustrate how to define a move
// constructor
#include <iostream>
using namespace std;
 
class Box {
 
public:
    int* data; // Pointer to an integer value
    // Constructor
    Box(int value)
    {
        data = new int;
        *data = value;
    }
 
    // Move constructor
    Box(Box&& other) noexcept
    {
        cout << "Move Constructor Called" << endl;
 
        data = other.data; // Transfer ownership of 'other'
                           // data
        other.data = nullptr; // Null out 'other' to prevent
                              // double deletion
    }
 
    // Destructor
    ~Box() { delete data; }
};
 
int main()
{
    // Create a Box with value 42
    Box originalBox(42);
 
    // Create a new Box by moving resources from the
    // originalBox
    Box newBox(move(originalBox));
 
    cout << "newBox.data: " << *newBox.data;
 
    // originalBox is now in a valid but unspecified
    // state (its resources were moved to newBox)
 
    return 0;
}
```

#### Uses of Move Constructor
- Instead of making copies, move constructors efficiently transfer ownership of these resources.
- This prevents unnecessary memory copying and reduces overhead.
- You can define your own move constructor to handle specific resource transfers.
```