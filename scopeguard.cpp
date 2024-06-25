#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class User;

class UserDatabase
{
public:
	void AddFriend(const std::string& user, User& the_friend);
};

void UserDatabase::AddFriend(const std::string& user, User& the_friend)
{
	std::cout << "Added friend to user in DB!" << std::endl;
}

class UserList 
{
public:
	void Push(User& user);
};

void UserList::Push(User& user)
{
	// hardcode to throw exception
	throw std::runtime_error("Error adding user"); 
}

class User
{
public:
	User(std::string name)
	:name_(name)
	{}
	std::string GetName() const { return name_; } 
	void AddFriend(User& newFriend);		
private:
	UserList friends_;
	UserDatabase* pDB_;
	std::string name_;
};

void User::AddFriend(User& newFriend)
{
	// Add the new friend to the database
	pDB_->AddFriend(GetName(), newFriend);
	// Add the new friend to the vector of friends
	friends_.Push(newFriend);
}

int main()
{
	User bk = User("Beyonce Knowles");
	User mt = User("Margaret Thatcher");
	bk.AddFriend(mt);	

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////
// error: cannot bind non-const lvalue reference of type 'std::string&' {aka 'std::__cxx11::basic_string<char>&'} to an rvalue of type 'std::string' {aka 'std::__cxx11::basic_string<char>'}

// 48 |         pDB_->AddFriend(GetName(), newFriend);
//    |                         ~~~~~~~^~
// .\scopeguard.cpp:14:43: note:   initializing argument 1 of 'void UserDatabase::AddFriend(std::string&, User&)'
//   14 | void UserDatabase::AddFriend(std::string& user, User& the_friend)
//      |                              ~~~~~~~~~~~~~^~~~

