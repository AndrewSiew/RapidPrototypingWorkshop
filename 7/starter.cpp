#include <iostream>
#include <list>

using namespace std;

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

  // Should print out something like this
  /*
  UBC Rapid
  6
  Will,Isabelle,Meghan,Friend, 
  Will,Isabelle,               
  will@gmail.com,isabelle@gmail.com,meghan@gmail.com,friend@gmail.com,andrew@gmail.com,monica@gmail.com,
  Meghan,Andrew,
  */

  return 0;
}
