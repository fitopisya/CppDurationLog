#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void AssertImpl(const T& expr, const string& text, const string& file, unsigned line,const string& func, const string& hint ){
    if(!expr){
        cout << boolalpha;
        cout << file << '(' << line << ')' << ": "s << func << ": "s;
        cout << "ASSERT("s << text << ") failed. "s;
        if(!hint.empty()){
            cout << "Hint: "s << hint;
        } cout << endl;
        abort();
    }
}
#define ASSERT(expr) AssertImpl(((expr)), #expr, __FILE__, __LINE__, __FUNCTION__, ""s)
#define ASSERT_HINT(expr, hint) AssertImpl(((expr)), #expr, __FILE__, __LINE__, __FUNCTION__, (hint))

int main() {
    string hello = "hello"s;
    ASSERT(!hello.empty());
    ASSERT_HINT(2 + 2 == 5, "This will fail"s);
    return 0;
}
