#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class User
{
    string name;
    int age;
public:
    User(string name, int age) : name{ name }, age{ age } {}
    friend ostream& operator<<(ostream& out, const User& u)
    {
        out << "(" << u.name << ") - [" << u.age << "]";
        return out;
    }
    string& Name() { return name; }
    int& Age() { return age; }

    friend bool operator==(const User& u1, const User& u2)
    {
        return u1.name == u2.name;
    }
};

int main()
{
    vector<int> v1{ 1, 4, 5, 2, 3, 6, 7, 8, 9 };
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << "\n\n";

    //auto it = partition(v1.begin(), v1.end(),
    //                    [](auto item) { return item % 2; });
    stable_partition(v1.begin(), v1.end(),
                          [](auto item) { return item % 2; });
    auto it = partition_point(v1.begin(), v1.end(),
                          [](auto item) { return item % 2; });
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    copy(v1.begin(), it, ostream_iterator<int>(cout, " "));
    cout << "\n";
    copy(it, v1.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
}
