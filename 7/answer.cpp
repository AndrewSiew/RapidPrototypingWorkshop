// Sample answer to Part 1
// Don't look before you try !!!

#include <iostream>
#include <list>

using namespace std;

class Member
{
public:
  string name;
  string position;
  string subteam;
  string contact;
};

class Team
{
private:
  string name;
  std::list < Member > members;

public:
  Team ()
  {
    name = "no name";
  }

  Team (string n)
  {
    name = n;
  }

  void AddMember (string name, string position, string subteam,
		  string contact)
  {
    Member m;
    m.name = name;
    m.position = position;
    m.subteam = subteam;
    m.contact = contact;
    members.push_back (m);
  }

  string GetName ()
  {
    return name;
  }

  string GetMemberCount ()
  {
    return to_string (members.size ());
  }

  string GetExecs ()
  {
    list < Member >::iterator m;
    string ret;
    for (m = members.begin (); m != members.end (); m++)
      {
	Member mm = *m;
	if (mm.position != "Member")
	  {
	    ret = ret + mm.name + ",";
	  }
      }
    return ret;
  }

  string GetCaptians ()
  {
    list < Member >::iterator m;
    string ret;
    for (m = members.begin (); m != members.end (); m++)
      {
	Member mm = *m;
	if (mm.position == "Captain")
	  {
	    ret = ret + mm.name + ",";
	  }
      }
    return ret;
  }

  string GetContacts ()
  {
    list < Member >::iterator m;
    string ret;
    for (m = members.begin (); m != members.end (); m++)
      {
	Member mm = *m;
	ret = ret + mm.contact + ",";
      }
    return ret;
  }

  string GetSubteam (string subteam)
  {
    list < Member >::iterator m;
    string ret;
    for (m = members.begin (); m != members.end (); m++)
      {
	Member mm = *m;
	if (mm.subteam == subteam)
	  {
	    ret = ret + mm.name + ",";
	  }
      }
    return ret;
  }
};

int
main ()
{
  Team rapid ("UBC Rapid");
  rapid.AddMember ("Will", "Captain", "Consulting", "will@gmail.com");
  rapid.AddMember ("Isabelle", "Captain", "Marlin", "isabelle@gmail.com");
  rapid.AddMember ("Meghan", "Exec", "Printing service", "meghan@gmail.com");
  rapid.AddMember ("Friend", "Exec", "Workshop", "friend@gmail.com");
  rapid.AddMember ("Andrew", "Member", "Printing service",
		   "andrew@gmail.com");
  rapid.AddMember ("Monica", "Member", "Workshop", "monica@gmail.com");
  // all of these functions return string
  cout << rapid.GetName () << "\n";
  cout << rapid.GetMemberCount () << "\n";
  cout << rapid.GetExecs () << "\n";
  cout << rapid.GetCaptians () << "\n";
  cout << rapid.GetContacts () << "\n";
  cout << rapid.GetSubteam ("Printing service") << "\n";

  return 0;
}
