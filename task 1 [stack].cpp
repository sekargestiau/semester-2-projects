#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<string> stack_books;
    stack_books.push("Numerical Analysis");
    stack_books.push("Discrete Mathematics and Its Applications");
    stack_books.push("Computer Networking: A Top Down Approach");
    stack_books.push("Introduction to Machine Learning");
    stack_books.push("Linear Algebra and Its Applications");
    stack_books.push("Fundamentals of Computer Graphics");

    //mengeluarkan buku Fundamentals of Computer Graphics
    stack_books.pop();

    //mengeluarkan buku Linear Algebra and Its Applications
    stack_books.pop();

    //mengambil buku Introduction to Machine Learning
    stack_books.pop();

    //meletakkan kembali buku Linear Algebra and Its Applications
    stack_books.push("Linear Algebra and Its Applications");

    //meletakkan kembali buku Fundamentals of Computer Graphics
    stack_books.push("Fundamentals of Computer Graphics");

    cout << "" << endl;
    cout << "Stack of Books :" << endl;
    cout << "" << endl;
     while (!stack_books.empty()) {
        cout << "" << stack_books.top() << endl;
        stack_books.pop();
    }
    cout << "" << endl;


    return 0;
}
